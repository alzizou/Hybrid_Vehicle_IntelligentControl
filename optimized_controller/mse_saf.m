function out=mse_saf(inp)
s1=size(inp);
s=s1(1,1);
out=(1/s)*(sqrt(inp'*inp));
end
