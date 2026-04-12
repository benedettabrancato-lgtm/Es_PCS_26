%Dimensioni problema
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

%Vettore Colonna 1 
Bubble_Sort = [5.55e-07; 1.044e-06; 2.508e-06; 9.032e-06; 3.0736e-05; 0.000124773; 0.00045111; 0.00171337; 0.00749448; 0.0208328; 0.08346; 0.383303];

%Vettore Colonna 2
Selection_Sort = [2.88e-07; 7.19e-07; 1.232e-06; 3.028e-06; 8.427e-06; 3.0136e-05; 0.000107645; 0.00041739; 0.0012863; 0.00512398; 0.0189155; 0.07482];

%Vettore Colonna 3
Insertion_Sort = [3.43e-07; 8.72e-07; 2.09e-06; 5.519e-06; 1.633e-05; 5.1312e-05; 0.000169225; 0.000649391; 0.00174288; 0.00691728; 0.0266452; 0.107777];

%Vettore Colonna 4
Sort = [9.16e-07; 1.179e-06; 1.793e-06; 5.8e-06; 1.1697e-05; 2.4588e-05; 5.2909e-05; 0.00013542; 0.000184064; 0.000402131; 0.000847543; 0.00174594];

figure(1);
plot(N,Bubble_Sort,'b','LineWidth', 2);
hold on
plot(N,Selection_Sort, 'g', 'LineWidth', 2);
plot(N,Insertion_Sort, 'r','LineWidth', 2);
plot(N, Sort,'m','LineWidth', 2);

grid on;
xlabel('Dimensione Vettore (N)');
ylabel('Tempo (secondi)');
title('Rappresentazione durata algoritmi di ordinamento')
legend('Bubble Sort', 'Selection Sort','Insertion Sort', 'Sort');