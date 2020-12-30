function out=feat_corr_2(dat)
% clear
% clc
diff_a=0.01;
q=length(dat);
num=1;
num0=0;
for i=2:q
    for j=1:i-1
    if abs(dat(i,2)-dat(j,2))<diff_a
        if abs(dat(i,3)-dat(j,3))<diff_a
            num0=num0+1;
            if num0==1
                num=num+1;
                similar(num,1:2)=dat(i,2:3);                
            end
            if num0>1
                corr_plus=1;
                s11_siml=size(similar);
                s1_siml=s11_siml(1,1);
                for u=1:s1_siml
                    if abs(dat(i,2)-similar(u,1))<diff_a
                        if abs(dat(i,3)-similar(u,2))<diff_a                            
                            corr_plus=0;                        
                        end
                    end                 
                end
                if corr_plus==1
                    num=num+1;
                    similar(num,1:2)=dat(i,2:3);                    
                end
            end            
        end
    end
    end
end
if num0==0
    similar=zeros(1,3);
end
s11=size(similar);
s_similar=s11(1,1);
out_similar=zeros(s_similar,3);
num1=zeros(s_similar,1);
for j=1:s_similar
    frst_sum=0;
    for i=1:q
        if abs(dat(i,2)-similar(j,1))<diff_a
            if abs(dat(i,3)-similar(j,2))<diff_a                
                num1(j)=num1(j)+1;
                frst_sum=frst_sum+dat(i,4);                
            end
        end
    end
    out_similar(j,1)=similar(j,1);
    out_similar(j,2)=similar(j,2);
    out_similar(j,3)=frst_sum/num1(j);
end
num2=0;
for i=1:q
    test_ok=0;
    for j=1:s_similar
        if abs(dat(i,2)-similar(j,1))<diff_a
            if abs(dat(i,3)-similar(j,2))<diff_a                
                test_ok=1;               
            end
        end
    end
    if test_ok==0
        num2=num2+1;
        out1(num2,1:2)=dat(i,2:3);        
        out1(num2,3)=dat(i,4);
    end
end
s_out_similar=size(out_similar);
lt_out_similar=s_out_similar(1,1);
lt_out1=length(out1);
out(1:lt_out1,1:3)=out1(:,1:3);
if num0>0
    out(lt_out1+1:lt_out1+lt_out_similar,1:3)=out_similar(:,1:3);
end
end