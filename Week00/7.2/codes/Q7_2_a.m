% part a
for p = 0:0.01:0.99
a = [1 p];
b = 1;
figure(1)
zplane(b,a);

% part b
n = 1001;
[H,w] = freqz(b,a,n);
figure(2)
plot(w,abs(H));

% part c
figure(3)
impz(b,a);
end
