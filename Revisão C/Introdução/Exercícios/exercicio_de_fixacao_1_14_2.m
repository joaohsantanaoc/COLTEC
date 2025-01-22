% 22/01/2025
% Revisão Linguagem C: Introdução
% Exercícios de fixação 1.14.2
% Exercício 1
% João Henrique Santana Oliveira Campos
% Turma 304 - Automação Industrial
% Professor Márcio Fantini

% Limpando command window e figures
clc; clear all; close all; 

% Inicialização de vetor v:
v = zeros(200, 1);

% Resto da divisão de i (variando de 1 até 200) por 30:
for i = 1 : 200
    v(i) = mod(i, 30);
end

% Gráfico com os valores gerados:
figure(1);
plot(v, 'x');
title("Números aleatórios do vetor v");
xlabel("Eixo x");
ylabel("Eixo y");
grid on;