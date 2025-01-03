% 02/01/2025
% Revisão Linguagem C: Introdução
% Exercícios de fixação: Exercício 1
% João Henrique Santana Oliveira Campos
% Turma 304 - Automação Industrial
% Professor Márcio Fantini

clc; clear all; close all;

for i = 1 : 200
  v(i) = mod(i, 30);
endfor

plot(v, 'x');
