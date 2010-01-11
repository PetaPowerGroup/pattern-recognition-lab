% uzorak je matrica uèitana iz c++a
function r_uzorak = pca(uzorak);

n = floor(sqrt(130)); %broj znaèajki
m = uzorak-mean(mean(uzorak)).*ones(size(uzorak,1),size(uzorak,2));
cov = m*m';
N = size(cov,1);
[v, lambda] = eig(cov);
e = zeros(N,n);

for i=1:n
    [x,y,z] = find(lambda == max(max(lambda)), 1, 'first');
    lambda(x,:) = [];
    e(:,i) = v(:,x);
    v(:,x) = [];
end

r_uzorak = e'*uzorak;

return r_uzorak;