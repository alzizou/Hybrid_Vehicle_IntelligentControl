% HW3 SI #1-a ali safaie 810689047
clear
clc
close all
load('fun_1_data.mat');
m=12;% number of neurons in the layer
eipoch_num=600;% number of eipochs
q0=size(x1_trn);
q1=q0(1,1);
q2=size(x1_tst);
q3=q2(1,1);
eta=0.1;% learning rate
u_trn=zeros(3,m);
u_tst=zeros(3,m);
x_trn=zeros(m,eipoch_num);
x_tst=zeros(m,eipoch_num);
z_trn=zeros(m,eipoch_num);
z_tst=zeros(m,eipoch_num);
w=zeros(m,3);
z1_out_trn=zeros(q1,1);
z1_out_tst=zeros(q3,1);
err_trsh=0.0000001;
grd=zeros(m,3);
for i11=1:m 
    a=randn(1,3);
    a_max=max(abs(a));
    a_nrm=a/a_max;
    w(i11,:)=0.25*a_nrm;% initial values for hidden layer weights
end
a1=randn(m,1);
a1_max=max(abs(a1));
a1_nrm=a1/a1_max;
teta=a1_nrm;% initial values for output layer weights
for eipoch=1:eipoch_num  
    sse_trn=0;
    sse_tst=0;
    for i2=1:q1
        for j1=1:m
            u_trn(:,j1)=[1;x1_trn(i2);y1_trn(i2)];
            x_trn(j1,eipoch)=w(j1,:)*u_trn(:,j1);
            z_trn(j1,eipoch)=tanh(x_trn(j1,eipoch));
        end
        z1_out_trn(i2)=teta'*z_trn(:,eipoch);
        sse_trn=sse_trn+(z1_trn(i2)-z1_out_trn(i2))^2;
        for j3=1:m
            for j4=1:3
                grd(j3,j4)=(teta(j3)*u_trn(j4,j3)*(1-(tanh(x_trn(j3,eipoch)))^2))*0.5*(z1_trn(i2)-z1_out_trn(i2));
                w(j3,j4)=w(j3,j4)+(eta*grd(j3,j4));
            end
        end
        teta=teta+(eta*0.5*(z1_trn(i2)-z1_out_trn(i2))*z_trn(:,eipoch));
     end
     mse_trn_eipoch(eipoch)=sse_trn/q1;
     for i3=1:q3
            for j2=1:m
                u_tst(:,j2)=[1;x1_tst(i3);y1_tst(i3)];
                x_tst(j2,eipoch)=w(j2,:)*u_tst(:,j2);
                z_tst(j2,eipoch)=tanh(x_tst(j2,eipoch));
            end
     z1_out_tst(i3)=teta'*z_tst(:,eipoch);
     sse_tst=sse_tst+((z1_tst(i3)-z1_out_tst(i3))^2);
     end
     mse_tst_eipoch(eipoch)=sse_tst/q3;
     eipoch_vec(eipoch)=eipoch;
end
figure
plot(eipoch_vec,mse_trn_eipoch);
hold on
plot(eipoch_vec,mse_tst_eipoch,'r');
xlabel('eipoch')
ylabel('mse trn(blue) & mse tst(red)')
grid
