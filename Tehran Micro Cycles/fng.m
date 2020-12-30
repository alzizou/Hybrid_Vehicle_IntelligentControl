% generation of feature_n vector for each cycle
function out=fng(cyc_feature)
num=0;cyc_feature_n=zeros(34,1);
for i=1:3
    for j=1:8
        cyc_feature_n(num+j,1)=cyc_feature(i,j);
    end
    num=i*8;
end
for k=25:31
    cyc_feature_n(k,1)=cyc_feature(4,k-24);
end
for e=32:34
    cyc_feature_n(e,1)=cyc_feature(5,e-31);
end
out=cyc_feature_n;
end
% fit_1=avg_spd  ,  fit_2=max_spd  ,  fit_3=% of time spd in 0-10
% fit_4=% of time spd in 10-20 , fit_5=% of time spd in 20-30
% fit_6=% of time spd in 30-40 , fit_7=% of time spd in 40-50
% fit_8=% of time spd in 50-up , fit_9=avg_acc , fit_10=max_acc
% fit_11=% of time acc in 0-0.2 , fit_12=% of time acc in 0.2-0.4
% fit_13=% of time acc in 0.4-0.6 , fit_14=% of time acc in 0.6-0.8
% fit_15=% of time acc in 0.8-1 , fit_16=% of time acc in 1-up
% fit_17=avg_dec , fit_18=max_dec , fit_19=% of time dec in 0--0.2
% fit_20=% of time dec in -0.2--0.4 , fit_21=% of time dec in -0.4--0.6
% fit_22=% of time dec in -0.6--0.8 , % fit_23=% of time dec in -0.8--1
% fit_24=% of time dec in -1-down , fit_25= RPA 
% fit_26=% of time av in 0-5 , fit_27=% of time av in -5-0
% fit_28=% of time av in 5-10 , fit_29=% of time av in -5--10
% fit_30=% of time av in 10-up , fit_31=% of time av in -10-down
% fit_32= number of stops , fit_33= number of stops per km , fit_34= PKE
