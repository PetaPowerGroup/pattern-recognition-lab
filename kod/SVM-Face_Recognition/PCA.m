% uzorak je matrica uèitana iz c++a
function tr = pca(uzorak);
n = 130;

m = uzorak-mean(mean(uzorak)).*ones(size(uzorak,1),size(uzorak,2));
cov = m*m';
N = size(cov,1);

cov = sym(cov);
I = sym(eye(N));
lambda = sym('lambda');
x = solve('det(cov-lambda.*I)=0', 'lambda');

znac = wkeep(sort(x,'descend'),n,'l');

tr = zeros(N,n);
for i = 1:n
    L = sym(znac(i).*eye(N));
    A = sym('A');
    tr(:,i) = solve('(cov-L)*A=0', 'A');
end
tr = tr';

return tr;