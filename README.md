# ♟️ MateCheck — Xadrez em C (Nível Mestre)

Este projeto é o **desafio final** da série **MateCheck**, implementado em **linguagem C**, com foco em **estruturas de repetição avançadas** e **recursividade** para simular os movimentos de peças de xadrez.

O código foi desenvolvido seguindo os requisitos do **Nível Mestre**, explorando:
- **Funções recursivas**
- **Loops aninhados**
- **Controle de fluxo com `continue` e `break`**
- **Organização e legibilidade de código**

---

## 📌 Nível escolhido: **Mestre**
O nível **Mestre** exige implementar:
1. **Recursividade** para **Torre**, **Bispo** e **Rainha**.
2. **Loops complexos** para **Cavalo** (2 casas para cima, 1 para direita) usando `continue` e `break`.
3. **Loops aninhados** para **Bispo** (externo = vertical, interno = horizontal).
4. **Saída clara no console** (`Cima`, `Baixo`, `Esquerda`, `Direita`).
5. **Sem entrada de usuário** — valores definidos diretamente no código.

---

## 🎯 Objetivo
Simular, de forma didática e estruturada, os movimentos das peças:
- **Bispo**: diagonal para cima e direita (5 casas) → recursivo e por loops.
- **Torre**: direita (5 casas) → recursivo.
- **Rainha**: esquerda (8 casas) → recursivo.
- **Cavalo**: em “L” para cima e direita (2+1) → loops complexos.

---

## 🛠️ Tecnologias e Conceitos Utilizados
- **Linguagem C**
- **Funções recursivas** (controle de movimento casa a casa)
- **Loops aninhados** (`for` externos e internos)
- **Controle de fluxo** (`continue`, `break`)
- **Organização modular do código**
- **Comentários explicativos**
- **Impressão formatada no console**

---

## 📂 Estrutura do Código

```plaintext
xadrez.c
├── Funções de impressão (print_cima, print_direita, etc.)
├── Funções recursivas:
│   ├── mover_torre_direita_rec
│   ├── mover_rainha_esquerda_rec
│   └── mover_bispo_cima_direita_rec
├── Função de loops aninhados para o Bispo
├── Função de loops complexos para o Cavalo
└── main (coordena a execução das peças)
````

---

## 📜 Execução

### Compilação:

```bash
gcc -Wall -Wextra -O2 xadrez.c -o xadrez
```

### Execução:

```bash
./xadrez
```

---

## 📤 Saída esperada

```
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita

Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita

Direita
Direita
Direita
Direita
Direita

Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda

Cima
Cima
Direita
```

Cada bloco representa uma peça, separado por **linhas em branco**.

---

## 📖 Aprendizados

* **Recursividade**: fácil leitura de movimentos repetitivos e controle por "caso base".
* **Loops aninhados**: simulam movimentos compostos (como diagonais).
* **Controle de fluxo**: `continue` e `break` permitem lógica refinada para movimentos específicos.
* **Legibilidade**: organização modular e nomes descritivos tornam o código mais fácil de manter.

---

## 🏆 Conclusão

Este projeto consolida conceitos avançados de **programação em C**, aplicados a um contexto lúdico e estratégico como o **xadrez**.
Ao atingir o **Nível Mestre**, é possível perceber o poder de **estruturas de repetição**, **funções recursivas** e **controle de fluxo**, amplamente utilizados em desafios reais de lógica e engenharia de software.