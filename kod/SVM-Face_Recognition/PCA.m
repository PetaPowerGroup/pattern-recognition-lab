% uzorak je matrica uèitana iz c++a
function pca();

%uèitavanje iz txt fajla
%pretpostavio sam da je broj uzoraka 2400(8x300)
fid = fopen('svm/test1.txt','r');
for i=1:300
%C = scanf(fid, '%d');
    for j=1:2400
        data = fscanf(fid, '%d:%f32');
        uzorak(j,i)=data(2);
    end
fscanf(fid, '\n');
end
fclose(fid);

%size(uzorak)=4096x2400
cov = zeros(4096,4096);
n = 130; %broj znaèajki, matrica 4096x2400 se reducira na 130x2400
for i=1:2400
    m = uzorak(:,i)-mean(mean(uzorak(:,i))).*ones(4096,1);
    cov = cov + m*m';
end
cov = cov/2399;

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

fid = fopen('svm/r_uzorak.txt','w');
for i=1:2400
%C = fprintf(fid, '%d ', i);
    for j=1:4096
        fprintf(fid, '%d:%f32 ',j, uzorak(j,i));
    end
    fprintf(fid, '\n');
end
fclose(fid);

return;