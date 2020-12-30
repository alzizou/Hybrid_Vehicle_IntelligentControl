clear
clc
global g c R_max S_p Cd den Af M fr T_min fd G_simp2 T1_p TC bb 
global Rw G_simp1 G_Plan FW_inertia M1
bb=0;
TC=0;   % Lockup Clutch (Torque Converter) Status
S_p=1;
T1_p=0;
g=1;
c=1;
k1=0.99749568*2^-7;
k2=0.98441412;
k3=0.99749568*2^-7;
k4=0.98441412;
% T_max=1060*1.5;
% T_max=1060*1.25;
% T_max=1060;
T_max=1100;
T_max_457=1250;
x=1060*1.5;
T_min=5060;
% T_min=50600;
I_ICE=2.16;
% Idle_spd_eng_906=560;   % Engine Idle Speed (RPM)
I_wheel=1;
fuel_density=810; % kg/m3 or g/lit
TC_spd_ratio_max=0;
Impeller_Inertia=0.16;
Turbine_Inertia=0.11;
gear_inertia=.01;
% clutchRise=0.01;                      %Changed Clutch Rise
% clutchRise=0.6;                         %Changed Clutch Rise
clutchRise=.06;
Idle_spd_eng_457=625;
%% Gears

% R_max=5;
% R_min=.5;
R_max=15; %  (from Veshaq)
R_min=3; %  (from Veshaq)
fd=4.3;
G_simp1=R_max;
% G_simp2=10*.5;
% G_simp2=10;
G_simp2=20000/5000; % speed compatibility between FW & CVT(from Veshaq)
G_simp2=20000/5000*0.75; % speed compatibility between FW & CVT(from Veshaq)

G_Plan=-(R_min - R_max)/R_min;

% Twait=25;
Twait=250;
% Twait=5;
Twait1=250;
time_step=0.001;
% load('CVT_loss_Table.mat')
load('engine.mat')
load('torque_convertor.mat')
% load('retarder.mat')
load('shift.mat')
load('map_170.mat')
load('BSFC_map_906_205.mat')
load('cyc_teh.mat')                     %Changed Cyc_Teh
load('cyc_Artemis.mat')
load('cyc_japan_midtown.mat')
load('cyc_FTP.mat')
load('my_cyc.mat')
load('cyc_UKbus.mat')
cyc_teh2=[cyc_teh(:,1),cyc_teh(:,2)*80/max(cyc_teh(:,2))];
% load('cyc_nuremburg_24.mat')            %Changed cyc_nuremburg_24

load('b.mat')          % ?!

load('fuzz_cntl1.mat')
load('fuzy_controller2.mat')
load('fuzy_controller1_imp_1.mat')
load('fuzy_controller1_imp_2.mat')

load('local_road.mat')
load('collector_a_b.mat')
load('collector_c_d.mat')
load('collector_e_f.mat')
load('otp_T_eng_loc_rod.mat')
load('otp_T_eng_loc_rod_1.mat')
load('otp_T_pm_loc_rod.mat')
load('otp_T_pm_loc_rod_1.mat')
load('otp_T_eng_col_a_b.mat')
load('otp_T_pm_col_a_b.mat')
load('otp_T_eng_col_c_d.mat')
load('otp_T_pm_col_c_d.mat')
load('otp_T_eng_col_e_f.mat')
load('otp_T_eng_col_e_f_1.mat')
load('otp_T_pm_col_e_f.mat')
load('otp_T_pm_col_e_f_1.mat')

load('sec_eng_sfc_map.mat')
% load('y1.mat')
% load('y2.mat')
%% O457Bus Characteristics

M_457=9850; % without passenger
M_906=9850-400; % without passenger
delta=1.05; % Effective Mass
M1_457=M_457*delta;
M1_906=M_906*delta;
M1_457=M1_457+(70*70); % with passenger
M1_906=M1_906+(70*70); % with passenger
M_axor_av=15000; %average mass of the Axor truck
M_457=9850; % without passenger
M_906=9850-400; % without passenger
delta=1.05; % Effective Mass
M1_axor_av=M_axor_av*delta; 
fr=0.01;
Cd=0.55;
den=1.202;
Af=6.3;


Rw=0.466;

%% Flywheel Constants    %%%%%%%%%
FW_max_spd=20000*pi/30;   % rad/s (from Veshaq)
FW_min_spd=10000*pi/30;   % rad/s (from Veshaq)
% FW_init_spd=2500;   % rad/s
FW_init_SoC=90;       % (%)
FW_init_spd=FW_min_spd+(FW_max_spd-FW_min_spd)*FW_init_SoC/100; % rad/s
% FW_min_SoC=10;    % (%)
% FW_max_spd=3000;   % rad/s
FW_inertia=3.78;    % kg*m^2
% FW_inertia=eps;    % kg*m^2
FW_loss_on=0;
CVT_loss_on=0;


%% PID
% PR1=input('PR1 = ?');
% IR1=input('IR1 = ?');
% DR1=input('DR1 = ?');
% sim('FW_Parallel_9_Test_3.mdl')

%% Hydraulic Hybrid
T_max_906=1100;
x=1060*1.5;
Idle_spd_eng_906=560;

load('pmax_125.mat')
load('qv_125.mat')
load('v_p_5.mat')
load('v_p_10.mat')
load('v_p_15.mat')
load('p_v_15.mat')
load('cyc_nuremburg_10.mat')
load('cyc_nuremburg.mat')
load('cyc_manhatan_30.mat')
load('CYC_NewYorkBus.mat')
% load('cyc_teh_6.mat');
m_eng_r=-370;%engine mass reduction
m_pm_a=+90;%pm mass addition
m_coup_a=+25;%coupling mass addition
m_con_a=+10;%control unit mass addition
m_hyd_a=+65;%hydraulic circuit mass addition;
m_chg=m_eng_r+m_pm_a+m_coup_a+m_con_a+m_hyd_a;%total changing mass addition (kg)
M_hydr=9850+m_chg; % mass changes is included
delta=1.05; % Effective Mass
M1_hydr=M_hydr*delta;
M1_hydr=M1_hydr+(70*70); % with passenger

% strategy control parameter - parallel hydraulic hybrid - Ali.Safaie
T_0=500;% first torque limit ( Nm )
T_1=600;% seconed torque limit ( Nm )
T_2=1000;%third torque limit ( Nm )
soc_1=20;% seconed lower SOC limit ( % )
soc_2=50;% first upper SOC limit ( % )
veh_spd_0=1;% vehicle speed limit ( km/h ) to change mode from pure HHV into hybrid
t_wait_1=0.5;% wait time for turn the engine on ( s )
t_wait_2=5;% wait time for turn the engine off ( s )
t_wait_3=1;% wait time for switch between engine-idle mode and engine-off mode


% constants for intelligent control strategy
load('fuz_wgt.mat');
load('fuzz_wght_2_corr.mat');
load('fuzz_wght_3_corr.mat');
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

load('collector_a_b_feature_n_norm_4.mat');
load('collector_c_d_feature_n_norm_4.mat');
load('collector_e_f_feature_n_norm_4.mat');
load('local_road_feature_n_norm_4.mat');

load('collector_a_b_feature_n_norm_5.mat');
load('collector_c_d_feature_n_norm_5.mat');
load('collector_e_f_feature_n_norm_5.mat');
load('local_road_feature_n_norm_5.mat');

% teta=[collector_a_b_feature_6 collector_c_d_feature_6 collector_e_f_feature_6 local_road_feature_6];
teta=[collector_a_b_feature_n_norm_4 collector_c_d_feature_n_norm_4 collector_e_f_feature_n_norm_4 local_road_feature_n_norm_4];
teta5=[collector_a_b_feature_n_norm_5 collector_c_d_feature_n_norm_5 collector_e_f_feature_n_norm_5 local_road_feature_n_norm_5];
load('teta_new_10.mat')
% teta=[ones(6,1) ones(6,1) ones(6,1) ones(6,1)];

T0=10;T1=T0/10;

%% anfis nets
load('FIS_col_ab_56.mat');
load('FIS_col_ab_67.mat');
load('FIS_col_ab_78.mat');
load('FIS_col_ab_89.mat');
load('FIS_col_cd_25.mat');

%% new
load('T_eng_1_a.mat');
load('T_pm_1_a.mat');
load('T_dem_col_ab.mat');
load('T_dem_col_cd.mat');
load('T_dem_col_ef.mat');
load('T_dem_loc_rod.mat');
load('T_dem_loc_rod_1.mat');
load('T_dem_col_ef_1.mat');
load('soc_col_cd.mat')
load('soc_col_ab.mat')
load('soc_col_ef.mat')
load('soc_loc_rod.mat')
load('soc_loc_rod_1.mat')

%%
load('cyc_nuremburg_5.mat')
load('cyc_teh_5.mat')
load('cyc_FTP_5.mat')
load('cyc_FTP.mat')
load('cyc_Artemis_5.mat')
load('cyc_NewYorkBus_5.mat')
load('cyc_newyorkbus_km_5.mat')
load('cyc_newyorkbus_km.mat')
load('cyc_UKbus_5.mat')
load('cyc_japan_midtown_5.mat')
load('local_road_5.mat')
load('refuse_cyc.mat')
load('refuse_2_cyc.mat')

%----------------------------------------------
Driving_Cycle=input('Which driving cycle?');

%% axor - sohrab
Twait_aux=10;
Twait_aux2=30;
aux1=5;
aux2=15;
load('fuzz_cntl1.mat')
