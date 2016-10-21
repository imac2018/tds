function y = quant(x,d,q)
// y = quant(x,d,q) : quantization
// x : input matrix
// d : decision levels
// q : quantization levels

if argn(2) ~= 3 then
   error('Incorrect number of arguments');
end
N = length(q);
if length(d) ~= N+1 then
   error('There must be N+1 decision levels for N quantization levels')
end
[P,Q] = size(x);
x = x(:);
y = zeros(P*Q,1);

d = d(:)';
d = [d(1:N) (1+%eps)*d(N+1)]


for n = 1:N
   ind = find(d(n) <= x & x < d(n+1));
   y(ind) = q(n)*ones(length(ind),1);
end

y = matrix(y,P,Q);

endfunction
   
