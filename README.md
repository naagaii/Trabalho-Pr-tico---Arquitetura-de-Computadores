# Projeto de Normalização de Vetores

Este projeto implementa três abordagens para normalizar vetores de características:
- Lookup Table
- Newton-Raphson (Otimização Quake III)
- Instruções de Hardware SSE (rsqrtss)

## Como compilar
Use o comando abaixo no terminal:
```bash
gcc -o normalize src/main.c src/read_csv.c src/normalize_vector.c -lm
