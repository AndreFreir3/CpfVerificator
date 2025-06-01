# Validador de CPF em Linguagem C

Este projeto consiste em um programa escrito em linguagem C que realiza a **validação de números de CPF**. Ele lê uma lista de CPFs de um arquivo de entrada (`entrada.txt`), verifica se cada CPF é válido de acordo com a regra oficial, e gera um arquivo de saída (`saida.txt`) com os resultados.

## 🧾 Como funciona

1. O programa lê CPFs (um por linha) do arquivo `entrada.txt`.
2. Para cada CPF, ele verifica:
   - Se possui exatamente 11 dígitos.
   - Se não é composto por todos os dígitos iguais.
   - Se os dois dígitos verificadores estão corretos.
3. O resultado é escrito no arquivo `saida.txt` com a indicação `Válido` ou `Inválido`.

## 🛠️ Compilação e execução

Compile o código usando o `gcc`:

```bash
gcc validador_cpf.c -o validador_cpf
```

Execute o programa:

```bash
./validador_cpf
```

## 📂 Arquivos

- `validador_cpf.c` — Código-fonte em C.
- `entrada.txt` — Arquivo com CPFs a serem validados.
- `saida.txt` — Arquivo gerado com o resultado da validação.

## 📌 Exemplo de entrada

**entrada.txt**
```
12345678909
98765432100
11144477735
```

**saida.txt**
```
12345678909 - Inválido
98765432100 - Inválido
11144477735 - Válido
```

## 📄 Licença

Este projeto é de uso livre para fins educacionais.
