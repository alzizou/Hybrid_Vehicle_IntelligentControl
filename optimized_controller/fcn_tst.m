function u = fcn_tst(x_feat,teta,init,t, T0, T1)
dist1=zeros(4,1);
p=4;q=2;dist2=zeros(4,1);
u1=zeros(4,1);
u=init;
if t>T0
    r=rem(t,T1);
    r1=rem(t,T0);
    if r<0.01 && (r1>=0.01)
        for j=1:4
            num=0;
            for e=1:6
                num=num+1;
                dist1(j)=dist1(j)+(((x_feat(e)-teta(e,j))/teta(e,j))^p);
            end
            dist2(j)=(dist1(j))^(1/p);
        end
        for k=1:4
            den=0;
            for t=1:4
                den=den+((dist2(k)/dist2(t))^(1/(q-1)));
            end
            u1(k)=1/(den);
        end
        u=u1;
   end
end
end