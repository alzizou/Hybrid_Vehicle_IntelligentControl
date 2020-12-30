% Generalized Fuzzy Algorithm Scheme - clustering method
function out=fuz_clus(fit_fir,clus_feat,data_feat)
n=34;p=2;
q=2;% fuzzifier
x=data_feat;teta=clus_feat;
dist1=zeros(6,4);u=zeros(6,4);
out=zeros(7,4);dist2=zeros(6,4);
for i=1:6
    for j=1:4
        num=0;
        for e=1:n
            if fit_fir(e)==1
                num=num+1;
                dist1(i,j)=dist1(i,j)+(abs(x(e,i)-teta(e,j))^p);
            end
        end
        dist2(i,j)=((dist1(i,j))/num)^(1/p);
    end
    for k=1:4
        den=0;
        for t=1:4
            den=den+((dist2(i,k)/dist2(i,t))^(1/(q-1)));
        end
        u(i,k)=1/(den);
    end
end
err1=0;
for i=1:6
    for j=1:4
        err1=err1+((u(i,j)^q)*(dist2(i,j)));
    end
end
dist1_clus=zeros(4,4);dist2_clus=zeros(4,4);
for i=1:4
    for j=1:4
        num=0;
        for e=1:n
            if fit_fir(e)==1
                num=num+1;
                dist1_clus(i,j)=dist1_clus(i,j)+(abs(teta(e,i)-teta(e,j))^p);
            end
        end
        if i~=j
            dist2_clus(i,j)=((dist1_clus(i,j))/num)^(1/p);
        else
            dist2_clus(i,j)=1;
        end
    end
end
err2_2=min(dist2_clus);
err2_3=min(err2_2);
err2=1/err2_3;
alpha=0.85;
err=alpha*err1 + (1-alpha)*err2;
out(1,1)=err;
out(2:7,:)=u;
end