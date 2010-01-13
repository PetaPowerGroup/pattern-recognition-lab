% uzorak je matrica uèitana iz c++a
function pca();

%uèitavanje iz txt fajla
%pretpostavio sam da je broj uzoraka 2400(8x300)
uzorak = zeros(2,9);
fid = fopen('svm/test1.txt','r');
for i=1:9
%C = scanf(fid, '%d');
    for j=1:2
        data = fscanf(fid, '%d:%f32');
        uzorak(j,i)=data(2);
    end
fscanf(fid, '\n');
end
fclose(fid);

%size(uzorak)=4096x2400
cov = zeros(2,2);
n = 1; %broj znaèajki, matrica 4096x2400 se reducira na 130x2400
for i=1:9
    m = uzorak(:,i)-mean(mean(uzorak(:,i))).*ones(2,1);
    cov = cov + m*m';
end
cov = cov/8;

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

fid = fopen('svm/r_uzorak.txt','r+');
for i=1:9
%C = fprintf(fid, '%d ', i);
    for j=1:1
        fprintf(fid, '%d:%f ',j, r_uzorak(j,i));
    end
    fprintf(fid, '\n');
end
fclose(fid);

return;