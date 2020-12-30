function out=brk_enrg_1(driver_scope)
% kJ
inp=driver_scope.signals(1,2).values(:,1)*10/36;
h1=size(inp);
h=h1(1,1);
out_re=0;out_rr=0;out_dr=0;out_to=0;
M_axor_av=15000; %average mass of the Axor truck
M_457=9850; % without passenger
M_906=9850-400; % without passenger
delta=1.05; % Effective Mass
M1_axor_av=M_axor_av*delta; 
M1_457=M_457*delta;
M1_906=M_906*delta;
M1_457=M1_457+(70*70); % with passenger
M1_906=M1_906+(70*70); % with passenger
fr=0.01;Cd=0.55;den=1.202;Af=6.3;
for i=2:h
    if inp(i)<inp(i-1)
        out_rr=out_rr+(fr*M1_906*9.81*(inp(i-1)-inp(i))*1);
        out_dr=out_dr+((1/6)*Cd*den*Af*(inp(i-1)^3-inp(i)^3)*1);
        out_to=out_to+(0.5*M1_906*(inp(i-1)^2-inp(i)^2));
        out_re=out_re+(0.5*M1_906*(inp(i-1)^2-inp(i)^2))-(fr*M1_906*9.81*(inp(i-1)-inp(i))*1)-((1/6)*Cd*den*Af*(inp(i-1)^3-inp(i)^3)*1);
    end
end
% disp('braking_energy_rolling_resistance:')
% out_rr/1000
% disp('braking_energy_aerodynamic_drag:')
% out_dr/1000
% disp('braking_energy_kinetic:')
% out_to/1000
% disp('braking_energy_regenerable:')
% out_re/1000
out=out_re/1000;
end