% featue generation
function out=fg(cyc)
clc
close all
plot(cyc(:,1),cyc(:,2));
h=size(cyc);
cyc_tim=h(1,1);
sum_spd=0;a=zeros(cyc_tim,2);sum_acc=0;sum_dec=0;dis=zeros(cyc_tim,1);dist=0;
num_acc=0;num_dec=0;av=zeros(cyc_tim,2);sum_av=0;sum_av_p=0;num_stop=0;pke_1=0;pke_dis=0;
num_spd_0_10=0;num_spd_10_20=0;num_spd_20_30=0;num_spd_30_40=0;num_spd_40_50=0;num_spd_50_up=0;
num_acc_0_02=0;num_acc_02_04=0;num_acc_04_06=0;num_acc_06_08=0;num_acc_08_1=0;num_acc_1_up=0;
num_dec_0_02=0;num_dec_02_04=0;num_dec_04_06=0;num_dec_06_08=0;num_dec_08_1=0;num_dec_1_dn=0;
num_av_0_5=0;num_av_5_0=0;num_av_5_10=0;num_av_10_5=0;num_av_10_up=0;num_av_10_dn=0;
for i=1:cyc_tim
    sum_spd=cyc(i,2)+sum_spd;
    if i>1
        a(i,1)=cyc(i,1);
        a(i,2)=(cyc(i,2)-cyc(i-1,2))*(10/36)/1;
    end
    if a(i,2)>0
        num_acc=num_acc+1;
        sum_acc=sum_acc+a(i,2);
        sum_av_p=sum_av_p+(0.5*((a(i,2)*cyc(i,2)*(10/36))+(a(i+1,2)*cyc(i+1,2)*(10/36))));% trapezoidal formula for integral
    end
    if a(i,2)<0
        num_dec=num_dec+1;
        sum_dec=sum_dec+a(i,2);
    end
    av(i,1)=cyc(i,1);
    av(i,2)=a(i,2)*(cyc(i,2)*10/36);
    sum_av=sum_av+av(i,2);
end
%------------------------------------------------------------------------
% speed
avg_spd=sum_spd/cyc_tim;
max_spd=max(cyc(:,2));
for i=1:cyc_tim
    if cyc(i,2)<10
        num_spd_0_10=num_spd_0_10+1;
    end
    if cyc(i,2)<20 && cyc(i,2)>=10
        num_spd_10_20=num_spd_10_20+1;
    end
    if cyc(i,2)<30 && cyc(i,2)>=20
        num_spd_20_30=num_spd_20_30+1;
    end
    if cyc(i,2)<40 && cyc(i,2)>=30
        num_spd_30_40=num_spd_30_40+1;
    end
    if cyc(i,2)<50 && cyc(i,2)>=40
        num_spd_40_50=num_spd_40_50+1;
    end
    if cyc(i,2)>=50
        num_spd_50_up=num_spd_50_up+1;
    end
end
prc_spd_0_10=100*num_spd_0_10/cyc_tim;
prc_spd_10_20=100*num_spd_10_20/cyc_tim;
prc_spd_20_30=100*num_spd_20_30/cyc_tim;
prc_spd_30_40=100*num_spd_30_40/cyc_tim;
prc_spd_40_50=100*num_spd_40_50/cyc_tim;
prc_spd_50_up=100*num_spd_50_up/cyc_tim;
out_spd=[avg_spd max_spd prc_spd_0_10 prc_spd_10_20 prc_spd_20_30 prc_spd_30_40 prc_spd_40_50 prc_spd_50_up];
%------------------------------------------------------------------------
%distance
for i=1:cyc_tim
    dis(i)=1*cyc(i,2)*10/36;% m
    dist=dist+dis(i);
end
%------------------------------------------------------------------------
% acceleration
avg_acc=sum_acc/num_acc;
max_acc=max(a(:,2));
for i=1:cyc_tim
    if a(i,2)<0.2 && a(i,2)>0
        num_acc_0_02=num_acc_0_02+1;
    end
    if a(i,2)<0.4 && a(i,2)>=0.2
        num_acc_02_04=num_acc_02_04+1;
    end
    if a(i,2)<0.6 && a(i,2)>=0.4
        num_acc_04_06=num_acc_04_06+1;
    end
    if a(i,2)<0.8 && a(i,2)>=0.6
        num_acc_06_08=num_acc_06_08+1;
    end
    if a(i,2)<1 && a(i,2)>=0.8
        num_acc_08_1=num_acc_08_1+1;
    end
    if a(i,2)>=1
        num_acc_1_up=num_acc_1_up+1;
    end
end
prc_acc_0_02=100*num_acc_0_02/num_acc;
prc_acc_02_04=100*num_acc_02_04/num_acc;
prc_acc_04_06=100*num_acc_04_06/num_acc;
prc_acc_06_08=100*num_acc_06_08/num_acc;
prc_acc_08_1=100*num_acc_08_1/num_acc;
prc_acc_1_up=100*num_acc_1_up/num_acc;
out_acc=[avg_acc max_acc prc_acc_0_02 prc_acc_02_04 prc_acc_04_06 prc_acc_06_08 prc_acc_08_1 prc_acc_1_up];
% -----------------------------------------------------------------------
% deceleration
avg_dec=sum_dec/num_dec;
max_dec=min(a(:,2));
for i=1:cyc_tim
    if a(i,2)<0 && a(i,2)>=-0.2
        num_dec_0_02=num_dec_0_02+1;
    end
    if a(i,2)<-0.2 && a(i,2)>=-0.4
        num_dec_02_04=num_dec_02_04+1;
    end
    if a(i,2)<-0.4 && a(i,2)>=-0.6
        num_dec_04_06=num_dec_04_06+1;
    end
    if a(i,2)<-0.6 && a(i,2)>=-0.8
        num_dec_06_08=num_dec_06_08+1;
    end
    if a(i,2)<-0.8 && a(i,2)>=-1
        num_dec_08_1=num_dec_08_1+1;
    end
    if a(i,2)<-1
        num_dec_1_dn=num_dec_1_dn+1;
    end
end
prc_dec_0_02=100*num_dec_0_02/num_dec;
prc_dec_02_04=100*num_dec_02_04/num_dec;
prc_dec_04_06=100*num_dec_04_06/num_dec;
prc_dec_06_08=100*num_dec_06_08/num_dec;
prc_dec_08_1=100*num_dec_08_1/num_dec;
prc_dec_1_dn=100*num_dec_1_dn/num_dec;
out_dec=[avg_dec max_dec prc_dec_0_02 prc_dec_02_04 prc_dec_04_06 prc_dec_06_08 prc_dec_08_1 prc_dec_1_dn];
%------------------------------------------------------------------------
% av
avg_av=sum_av/cyc_tim;
max_av=max(av(:,2));
min_av=min(av(:,2));
for i=1:cyc_tim
    if av(i,2)<5 && av(i,2)>=0
        num_av_0_5=num_av_0_5+1;
    end
    if av(i,2)<0 && av(i,2)>=-5
        num_av_5_0=num_av_5_0+1;
    end
    if av(i,2)<10 && av(i,2)>=5
        num_av_5_10=num_av_5_10+1;
    end
    if av(i,2)<-5 && av(i,2)>=-10
        num_av_10_5=num_av_10_5+1;
    end
    if av(i,2)>=10
        num_av_10_up=num_av_10_up+1;
    end
    if av(i,2)<-10
        num_av_10_dn=num_av_10_dn+1;
    end
end
prc_av_0_5=100*num_av_0_5/cyc_tim;
prc_av_5_0=100*num_av_5_0/cyc_tim;
prc_av_5_10=100*num_av_5_10/cyc_tim;
prc_av_10_5=100*num_av_10_5/cyc_tim;
prc_av_10_up=100*num_av_10_up/cyc_tim;
prc_av_10_dn=100*num_av_10_dn/cyc_tim;
%relative positive acceleration
rpa=sum_av_p/dist;
out_av=[rpa prc_av_0_5 prc_av_5_0 prc_av_5_10 prc_av_10_5 prc_av_10_up prc_av_10_dn 0];
% -----------------------------------------------------------------------
% number of stops per km & Positive Kinetic Energy (pke)
for i=2:cyc_tim
    if cyc(i,2)==0
        if cyc(i-1,2)>0
            num_stop=num_stop+1;
        end
    end
    if a(i,2)>0
        pke_1=pke_1+(((cyc(i+1,2)*(10/36))^2)-((cyc(i,2)*(10/36))^2));
        pke_dis=pke_dis+(cyc(i,2)*(10/36)*1); 
    end
end
num_stop_km=num_stop/(dist/1000);
pke=pke_1/pke_dis;
out_stop=[num_stop num_stop_km pke dist 0 0 0 0];
%------------------------------------------------------------------------
% outputs
out=[out_spd;out_acc;out_dec;out_av;out_stop];
sum_av_p
av
end