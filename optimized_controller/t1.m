function out=t1(inp)
q=length(inp.time);
out=zeros(((q-1)/100),2);
num=0;
for i=1:q
    if inp.time(i)==round(inp.time(i))
        num=num+1;
        out(num,1)=num;
        out(num,2)=inp.signals.values(i);
    end
end
end