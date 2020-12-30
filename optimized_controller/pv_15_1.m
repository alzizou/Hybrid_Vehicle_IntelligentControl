% accumualtor pressure look-up table
function out=pv_15_1(v_acm1,p_pre)
load('p_v_15.mat');
v_acm=v_acm1*61.02;
v_map=0:50:2300;p_pre_map=[1000;1400;2000];
p=interp2(p_pre_map,v_map,p_v_15,p_pre,v_acm);
out=p*0.0689;
end