function out=div_ali(dat1,dat2,dat3,soc1,soc2)
q=length(dat1);
num=0;
for i=1:q
    if dat1(i,4)>=soc1 && dat1(i,4)<=soc2
        num=num+1;
        out(num,1)=dat1(i,4);
        if dat1(i,2)>=0
            out(num,2)=dat1(i,2)/1100;
        else
            out(num,2)=dat1(i,2)/650;
        end
        out(num,3)=dat1(i,3)/100;
        if abs(dat1(i,2))>0
            if dat1(i,2)>0
                out(num,4)=dat2(i,2)/dat1(i,2);
            else 
                out(num,4)=-dat2(i,2)/dat1(i,2);
            end
            out(num,5)=dat3(i,2)/dat1(i,2);
        else
            out(num,4)=0;
            out(num,5)=0;
        end
    end
end
% out: 1st column = soc, 2nd column = T_dem, 3rd column = veh_spd, 4th
% column = T_pm, 5th column = T_eng
end