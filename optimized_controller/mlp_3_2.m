% HW3 SI #1-a ali safaie 810689047
% clear
% clc
% close all
% load('fun_2_data.mat');
function out=mlp_3_2(inputs,outputs)
% avg_err_tot=0;
% avg_err=zeros(1,216);
q0=size(inputs);n=100;
q1=q0(1,1);prc_tst=10;
num_tst=round((prc_tst/100)*q1);
num_vld=num_tst;
num_trn=q1-num_tst-num_vld;
dat_trn_inp=zeros(num_trn,2);dat_trn_otp=zeros(num_trn,1);
dat_tst_inp=zeros(num_tst,2);dat_tst_otp=zeros(num_tst,1);
dat_vld_inp=zeros(num_vld,2);dat_vld_otp=zeros(num_vld,1);
%-------------------------------------------------------------------------
% divide data to test and train series
% divide data to test and train series
for i=1:num_trn   
    if i==1
        u=randi(q1,1);        
    else
        for k=1:100
            w=randi(q1,1);
            cont=0;
            for j=1:i-1
                if w==n(j)
                    cont=1;
                end
            end
            if cont==0
                u=w;
                break
            end
        end 
    end
    n(i)=u;
    n_trn(i)=u;
    dat_trn_inp(i,:)=inputs(u,:);
    dat_trn_otp(i,1)=outputs(u,1);    
end
for j=1:num_tst
    for k=1:100
        w=randi(q1,1);
        cont=0;
        for j1=1:(num_trn+j-1)
            if w==n(j1)
                cont=1;
            end
        end
        if cont==0
            u1=w;
            break
        end
    end 
    n(num_trn+j)=u1;
    n_tst(j)=u1;
    dat_tst_inp(j,:)=inputs(u1,:);
    dat_tst_otp(j,1)=outputs(u1,1);    
end
for j=1:num_vld
    for k=1:100
        w=randi(q1,1);
        cont=0;
        for j1=1:(num_trn+num_tst+j-1)
            if w==n(j1)
                cont=1;
            end
        end
        if cont==0
            u2=w;
            break
        end
    end 
    n(num_trn+num_tst+j)=u2;
    n_vld(j)=u2;
    dat_vld_inp(j,:)=inputs(u2,:);
    dat_vld_otp(j,1)=outputs(u2,1);    
end
input_data=[dat_trn_inp(:,1)' dat_vld_inp(:,1)' dat_tst_inp(:,1)';dat_trn_inp(:,2)' dat_vld_inp(:,2)' dat_tst_inp(:,2)'];
output_data=[dat_trn_otp' dat_vld_otp' dat_tst_otp'];
% m=30;% number of neurons in the seconed layer
epoch_num=5000;% maximum number of epochs
net_ali=newff(input_data,output_data,[20 15],{'tansig','tansig','purelin'},'traingd','learngd');
net_ali.performFcn='mse';
net_ali.initFcn='initlay';
net_ali.layers{1:3}.initFcn='initwb';
net_ali.inputWeights{1}.initFcn='rands';
net_ali.layerWeights{2}.initFcn='rands';
net_ali.biases{1:3}.initFcn='rands';
net_ali.trainParam.epochs=epoch_num;
net_ali.trainParam.lr=0.02;
net_ali.divideFcn='divideInd';
net_ali.divideParam.trainInd=1:num_trn;
net_ali.divideParam.valInd=(num_trn+1):(num_trn+num_vld);
net_ali.divideParam.testInd=(num_trn+num_vld+1):(num_trn+num_vld+num_tst);
% net_ali.inputWeights{1}.learnParam=0.5;
% net_ali.layerWeights{2}.learnParam=0.5;
% net_ali.biases{1}.learnParam=0.5;
[net_ali,tr,out1,err]=train(net_ali,input_data,output_data);
% [output_tst,tr1,tr2,err_tst]=sim(net_ali,[x2_tst';y2_tst';u2_tst']);
out=net_ali;
end