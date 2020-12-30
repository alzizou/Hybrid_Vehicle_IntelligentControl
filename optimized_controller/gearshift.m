function [u]=gearshift(w_ice)
    
    global g
    
    
    if g==1
        if w_ice >= 1913
            g=2;
        else
            g=1;
        end


    elseif g==2
        if w_ice >= 1956
            g=3;
        elseif w_ice <= 1016
            g=1;
        else
            g=2;
        end

            
    elseif g==3
        if w_ice >= 1996
            g=4;
        elseif w_ice <= 1221
            g=2;
        else
            g=3;
        end

            
    elseif g==4
        if w_ice <= 1214
            g=3;
        else
            g=4;
        end
    end
    u=g;
            
end