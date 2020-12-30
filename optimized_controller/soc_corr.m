%soc correction
function out=soc_corr(soc1,soc2,dist)
% soc1=0.7;soc2=0.25;dist=0.35;
v_max=25.077;p_pre=1813;sp_fl=37.3;%mj/lit
v1=soc1*v_max;
v2=soc2*v_max;
v1_gas=50-v1;
v2_gas=50-v2;
p1=pv_15_1(v1,p_pre);
p2=pv_15_1(v2,p_pre);
e1=p1*(2*v1_gas)*101;
e2=p2*(2*v2_gas)*101;
de=e1-e2;
fl_v=(de/sp_fl)*(10e-6);
out=fl_v*1/dist;%lit in 100 km
end