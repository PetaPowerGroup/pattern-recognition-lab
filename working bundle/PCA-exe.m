% uzorak je matrica uèitana iz c++a
function pca();

fid = fopen('parametri.txt','r');
    p = fscanf(fid, '%d');
fclose(fid);
k=p(1)
a=p(2)
n=p(3)
%uèitavanje iz txt fajla
%pretpostavio sam da je broj uzoraka 2400(8x300)
uzorak = zeros(a,k);
broj = zeros(a,k);
c=zeros(2,k);
fid = fopen('vrijednostiZnacajkiUzoraka.txt','r');
for i=1:k
    c(:,i) = fscanf(fid, '%d %d');
    broj(1,i)=c(2,i);
    data = fscanf(fid, ':%f32');
    uzorak(1,i)=data;
    for j=2:a
        data = fscanf(fid, '%d:%f32');
        uzorak(j,i)=data(2);
        broj(j,i)=data(1);
    end
    fscanf(fid, '\n');
end
fclose(fid);

%size(uzorak)=4096x2352
cov = zeros(a,a);
for i=1:k
    m = uzorak(:,i)-mean(mean(uzorak(:,i))).*ones(a,1);
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

fid = fopen('skup_svih_znacajki.txt','w');
for i=1:k
fprintf(fid, '%d ', c(1,i));
%floor((i-1)/8)+1
    for j=1:n
        fprintf(fid, '%d:%f ',broj(j,i), r_uzorak(j,i));
    end
    fprintf(fid, '\r\n');
end
fclose(fid);

return;