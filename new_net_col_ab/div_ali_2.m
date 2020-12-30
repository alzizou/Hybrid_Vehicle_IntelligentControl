function out=div_ali_2(dat1,dat2,dat3,soc1,soc2,x)
q=length(dat1);
num=0;
if x==1
    for i=1:q
        if dat1(i,4)>=(soc1-0.01) && dat1(i,4)<=(soc2+0.01)            
            if dat1(i,2)>0
                num=num+1;
                out(num,1)=dat1(i,4);
                out(num,2)=dat1(i,2)/1100;            
                out(num,3)=dat1(i,3)/100;
                out(num,4)=dat2(i,2)/650;
                out(num,5)=dat3(i,2)/1100;         
            end
        end
    end
else
    for i=1:q
        if dat1(i,4)>=(soc1-0.01) && dat1(i,4)<=(soc2+0.01)            
            if dat1(i,2)<0
                num=num+1;
                out(num,1)=dat1(i,4);
                out(num,2)=dat1(i,2)/650;            
                out(num,3)=dat1(i,3)/100;
                out(num,4)=dat2(i,2)/650;
                out(num,5)=0;         
            end
        end
    end
end
% out: 1st column = soc, 2nd column = T_dem, 3rd column = veh_spd, 4th
% column = T_pm, 5th column = T_eng
end