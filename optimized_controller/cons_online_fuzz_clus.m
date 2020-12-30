ali_veh_spd=struct('signals',0,'time',0);
ali_veh_spd.signals=struct('values',zeros(1001,1));

ali_veh_acc=struct('signals',0,'time',0);
ali_veh_acc.signals=struct('values',zeros(1001,1));

ali_veh_spdacc=struct('signals',0,'time',0);
ali_veh_spdacc.signals=struct('values',zeros(1001,1));

load('collector_a_b_feature_6.mat');
load('collector_c_d_feature_6.mat');
load('collector_e_f_feature_6.mat');
load('local_road_feature_6.mat');

teta=[collector_a_b_feature_6 collector_c_d_feature_6 collector_e_f_feature_6 local_road_feature_6];
% teta=[ones(6,1) ones(6,1) ones(6,1) ones(6,1)];