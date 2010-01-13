% uzorak je matrica uèitana iz c++a
function r_uzorak = pca();

%uèitavanje iz txt fajla
fid = fopen('svm/test1.txt','r');
for i=1:2400
%C = scanf(fid, '%d');
    for j=1:4096
        data = fscanf(fid, '%d:%f32');
        uzorak(j,i)=data(2);
    end
fscanf(fid, '\n');
end
fclose(fid);

%size(uzorak)=4096x2400

n = 130; %broj znaèajki, matrica 4096x2400 se reducira na 130x2400
m = uzorak-mean(mean(uzorak)).*ones(size(uzorak,1),size(uzorak,2));
cov = m*m';
N = size(cov,1);    %N=4096
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