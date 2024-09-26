#!/bin/bash

# Compila o código
gcc -o normalize src/main.c src/read_csv.c src/normalize_vector.c -lm

# Executa o código e redireciona a saída para um arquivo
./normalize > results.txt

echo "Testes concluídos. Resultados salvos em results.txt"
