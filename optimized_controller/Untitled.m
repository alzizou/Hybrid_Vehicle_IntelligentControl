clear
clc
load('CYC_NewYorkBus.mat');
cyc_mph_10=zeros(6011,2);
cyc_mph_10(:,1)=0:6010;
num=0;
for i=1:10
    num=((i-1)*601);
    for j=1:601
        cyc_mph_10(num+j,2)=cyc_mph(j,2);
    end
end