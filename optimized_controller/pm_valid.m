function out=pm_valid(w_inp,qv,delta_p,Pow_pm,w_pm,vg)
num=0;
for i=1:51
    if abs( w_pm.signals.values(i) - w_inp ) <= 5
        num=num+1;
        pow_out(num)=Pow_pm.signals.values(i) / 1000;
        w_out(num)=w_pm.signals.values(i);
        qv_out(num)=qv.signals.values(i);
        delta_p_out(num)=delta_p.signals.values(i);
        vg_out(num)=vg.signals.values(i);
    end
end
figure
plot(delta_p_out,qv_out)
hold on
plot(delta_p_out,pow_out,'r')
%plot(delta_p_out,vg_out,'*')
%figure

%hold on
%plot(delta_p_out,vg_out,'*')
end