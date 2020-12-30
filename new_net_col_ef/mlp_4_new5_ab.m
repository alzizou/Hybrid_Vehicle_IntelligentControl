% HW3 SI #1-a ali safaie 810689047
% clear
% clc
% close all
% load('data_col_ab_new_1_p.mat');
function out=mlp_4_new5_ab(inps,outps)
% inps=[data_col_ab_new_1_p(:,1:2) data_col_ab_new_1_p(:,6)];
% outps=data_col_ab_new_1_p(:,4);
% avg_err_tot=0;
% avg_err=zeros(1,216);
as=0;num_as=0;
m1=50;m2=50;
perf_ref1=10;
perf_ref2=10;
% while as==0
    num_as=num_as+1
    m1
    m2
    for rep=1:10
        inputs=inps;
        outputs=outps;

        q0=size(inputs);
        q1=q0(1,1);prc_tst=10;prc_vald=5;
        num_tst=round((prc_tst/100)*q1);
        num_vald=round((prc_vald/100)*q1);
        num_trn=q1-num_tst-num_vald;
        dat_trn_inp=zeros(num_trn,3);dat_trn_otp=zeros(num_trn,1);
        dat_tst_inp=zeros(num_tst,3);dat_tst_otp=zeros(num_tst,1);
        dat_vald_inp=zeros(num_vald,3);dat_vald_otp=zeros(num_vald,1);
        %-------------------------------------------------------------------------
        % divide data to test and train series
        trn_inds=zeros(num_trn,1);
        for i=1:num_trn
            r=1;
            while r~=0
                w=randi(q1,1);
                qwa=find(trn_inds==w);
                r=length(qwa);
            end
            trn_inds(i)=w;
            dat_trn_inp(i,:)=inputs(w,:);
            dat_trn_otp(i,1)=outputs(w,1);
            inputs(w,:)=[0 0 0];
            outputs(w,1)=0;
        end
        num=0;
        num_v=0;
        for j=1:q1
            if inputs(j,3)~=0
                if num<num_tst
                    num=num+1;
                    dat_tst_inp(num,:)=inputs(j,:);
                    dat_tst_otp(num,1)=outputs(j,1);
                else 
                    num_v=num_v+1;
                    dat_vald_inp(num_v,:)=inputs(j,:);
                    dat_vald_otp(num_v,1)=outputs(j,1);
                end
            end
        end
        input_data=[dat_trn_inp(:,1)' dat_vald_inp(:,1)' dat_tst_inp(:,1)';dat_trn_inp(:,2)' dat_vald_inp(:,2)' dat_tst_inp(:,2)';dat_trn_inp(:,3)' dat_vald_inp(:,3)' dat_tst_inp(:,3)'];
        output_data=[dat_trn_otp' dat_vald_otp' dat_tst_otp'];
        epoch_num=500;% maximum number of epochs
        net_ali=newff(input_data,output_data,[m1 m2],{'logsig','logsig','purelin'},'trainlm','learngd');
        net_ali.initFcn='initlay';
        net_ali.layers{1:2}.initFcn='initwb';
        net_ali.inputWeights{1}.initFcn='rands';
        net_ali.layerWeights{2}.initFcn='rands';
        net_ali.biases{1:2}.initFcn='rands';
        net_ali.trainParam.epochs=epoch_num;
        net_ali.divideFcn='divideInd';
        net_ali.divideParam.trainInd=1:num_trn;
        net_ali.divideParam.valInd=(num_trn+1):(num_trn+num_vald);
        net_ali.divideParam.testInd=(num_trn+num_vald+1):(num_trn+num_tst+num_vald);
        net_ali.performFcn='mse';
        % net_ali.inputWeights{1}.learnParam=0.5;
        % net_ali.layerWeights{2}.learnParam=0.5;
        % net_ali.biases{1}.learnParam=0.5;
        [net_ali,tr,out1,err]=train(net_ali,input_data,output_data);
        % [output_tst,tr1,tr2,err_tst]=sim(net_ali,[x2_tst';y2_tst';u2_tst']);       
        if tr.best_perf<perf_ref1 && tr.best_tperf<perf_ref2
            net_out=net_ali;
            tr_out=tr;
%             as=1;
            perf_ref1=tr_out.best_perf;
            perf_ref2=tr_out.best_tperf;
        end
    end
    
%     if m1<25
%         m1=m1+1;
%     else
%         m1=5;
%         m2=m2+1;
%     end
%     if m2>25
%         break
%     end
% end
tr_out
out=net_out;
end