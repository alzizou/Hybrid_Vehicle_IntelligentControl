%hydraulic hybrid constant
clear
clc
global g R_max S_p Cd den Af M fr T_min fd T1_p TC bb c Rw
g=1;
c=1;
bb=0;
TC=0;   % Lockup Clutch (Torque Converter) Status
S_p=1;
T1_p=0;R_max=15;R_min=3;  %  (from Veshaq)
err_a=0;
a_e=zeros(1100,1);
T_max_906=1100*1;
x=1060*1.5;
T_min=5060;
fd=4.3;
I_ICE=2.16;
Idle_spd_eng_906=560;
I_wheel=1;
fuel_density=810; % kg/m3 or g/lit
TC_spd_ratio_max=0;
Impeller_Inertia=0.16;
Turbine_Inertia=0.11;
gear_inertia=.01;
clutchRise=.06;
Twait=25;
load('b.mat')
load('engine.mat')
load('torque_convertor.mat')
load('refuse_truck_cyc.mat')
load('shift.mat')
load('my_cyc.mat')
load('pmax_125.mat')
load('qv_125.mat')
load('v_p_5.mat')
load('v_p_10.mat')
load('v_p_15.mat')
load('p_v_15.mat')
load('sec_eng_sfc_map.mat')
% O457Bus Characteristics
m_eng_r=-370;%engine mass reduction
m_pm_a=+90;%pm mass addition
m_coup_a=+25;%coupling mass addition
m_con_a=+10;%control unit mass addition
m_hyd_a=+65;%hydraulic circuit mass addition;
m_chg=m_eng_r+m_pm_a+m_coup_a+m_con_a+m_hyd_a;%total changing mass addition (kg)

M=9850+m_chg; % mass changes is included
M=6000;
delta=1.05; % Effective Mass
M1=M*delta;
M1=M1+(70*70); % with passenger

fr=0.01;
Cd=0.55;
den=1.202;
Af=6.3;
Rw=0.466;

% -------------------------------------------------------------
% Engine Characteristics
% Engine MAP: cons(g/kWh)=f(RPM,Torque(Nm))
load('map_170.mat')
% load('retarder')
% load('mc_trq.mat')
% load('mc_pwr.mat')
% load('mc_pwr_in_a.mat')
% load('mc_trq_out_a.mat')
%load('trq_manhatan.mat')
%load('pwr_manhatan.mat')
%load('cyc_manhatan_30.mat')
%mc_pwr2=[1:1090]';
% %mc_pwr2(:,2)=mc_pwr_in_a/1000;
% mc_trq2=[1:1090]';
% mc_trq2(:,2)=mc_trq_out_a;
% load('advisor.m')
% trq1=load('trq.mat');
% pwr1=load('pwr.mat');
% pwr2=[1:1085]';
% pwr2(:,2)=pwr1.mc_pwr_in_a/1000;
% trq2=[1:1085]';
% trq2(:,2)=trq1.mc_trq_out_a;
%-----------------------------------------------------------------
% strategy control parameter - parallel hydraulic hybrid - Ali.Safaie
T_0=700;% first torque limit ( Nm )
T_1=800;% seconed torque limit ( Nm )
T_2=1000;%third torque limit ( Nm )
soc_1=20;% seconed lower SOC limit ( % )
soc_2=50;% first upper SOC limit ( % )
veh_spd_0=1;% vehicle speed limit ( km/h ) to change mode from pure HHV into hybrid
t_wait_1=0.5;% wait time for turn the engine on ( s )
t_wait_2=5;% wait time for turn the engine off ( s )
t_wait_3=1;% wait time for switch between engine-idle mode and engine-off mode

% constants for optimized control strategy
load('fuz_wgt.mat');
% online optimized controller
% ali_veh_spd=struct('signals',0,'time',0);
% ali_veh_spd.signals=struct('values',zeros(60001,1));
% 
% ali_veh_acc=struct('signals',0,'time',0);
% ali_veh_acc.signals=struct('values',zeros(60001,1));
% 
% ali_veh_spdacc=struct('signals',0,'time',0);
% ali_veh_spdacc.signals=struct('values',zeros(60001,1));

load('collector_a_b_feature_6.mat');
load('collector_c_d_feature_6.mat');
load('collector_e_f_feature_6.mat');
load('local_road_feature_6.mat');

teta=[collector_a_b_feature_6 collector_c_d_feature_6 collector_e_f_feature_6 local_road_feature_6];
% teta=[ones(6,1) ones(6,1) ones(6,1) ones(6,1)];

T0=30;T1=5;
