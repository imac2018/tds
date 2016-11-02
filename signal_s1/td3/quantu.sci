function y = quantu(x,N,dm)
// y = quantu(x,N,dm) : uniform quantization
// x  : input matrix
// N : number of quantization levels
// dm : vector of minimum and maximum decision levels
//      (default value : dm = [min(x) max(x)])

if argn(2) == 2 then
   dm = [min(x(:)) max(x(:))];
elseif argn(2) ~= 3 then
   error('Incorrect number of arguments');
end
dm(2) = (1+%eps)*dm(2);

d = linspace(dm(1),dm(2),N+1)
q = (d(1:N)+d(2:N+1))/2;

//y = quant(x,d(2:N),q);
y = quant(x,d,q);

endfunction
