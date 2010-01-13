% uzorak je matrica uèitana iz c++a
function pca(a,n);

k=2352;
%uèitavanje iz txt fajla
%pretpostavio sam da je broj uzoraka 2400(8x300)
uzorak = zeros(a,k);
fid = fopen('svm/lica-sva.txt','r');
for i=1:k
fscanf(fid, '%d');
    for j=1:a
        data = fscanf(fid, '%d:%f32');
        uzorak(j,i)=data(2);
    end
fscanf(fid, '\n');
end
fclose(fid);

%size(uzorak)=4096x2352
cov = zeros(a,a);
for i=1:k
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

fid = fopen('svm/r_uzorak.txt','w');
for i=1:k
fprintf(fid, '%d ', floor((i-1)/8)+1);
    for j=1:n
        fprintf(fid, '%d:%f ',j, r_uzorak(j,i));
    end
    fprintf(fid, '\r\n');
end
fclose(fid);

return;