function out=div_ali_3(dat1,dat2,dat3,soc1,soc2,x)
q=length(dat1);n=5;
num=0;
if x==1
    for i=n+1:q
        if dat1(i,4)>=(soc1-0.01) && dat1(i,4)<=(soc2+0.01)            
            if dat1(i,2)>0
                num=num+1;
                out(num,1)=dat1(i,4);
                out(num,2)=dat1(i-1,4);
                out(num,3)=dat1(i-2,4);
                out(num,4)=dat1(i-3,4);
                out(num,5)=dat1(i-4,4);
                out(num,6)=dat1(i-5,4);
                out(num,7)=dat1(i,3)/100;
                out(num,8)=dat1(i,2)/1100;                            
                out(num,9)=dat2(i,2)/650;
                out(num,10)=dat3(i,2)/1100;         
            end
        end
    end
else
    for i=1:q
        if dat1(i,4)>=(soc1-0.01) && dat1(i,4)<=(soc2+0.01)            
            if dat1(i,2)<0
                num=num+1;
                out(num,1)=dat1(i,4);
                out(num,2)=dat1(i-1,4);
                out(num,3)=dat1(i-2,4);
                out(num,4)=dat1(i-3,4);
                out(num,5)=dat1(i-4,4);
                out(num,6)=dat1(i-5,4);
                out(num,7)=dat1(i,3)/100;
                out(num,8)=dat1(i,2)/1100;                            
                out(num,9)=dat2(i,2)/650;                
                out(num,10)=0;         
            end
        end
    end
end
% out: 1st column = soc in current step, 2nd column = soc in one step before, 3rd column = soc in 2 steps before
%      4th column = soc in 3 steps before, 5th column = soc in 4 steps before, 6th column = soc in 5 steps before,
%      7th column = T_dem, 8th column = T_pm, 9th column = T_eng
end