# repositorio

# Atividade 03: Estruturas Condicionais e Seleção em C

Módulo de análise de elegibilidade e concessão de descontos académicos com base em critérios socioeconómicos, rendimento escolar e pontualidade de pagamento.

---

## 📌 Descrição do Projeto

O programa realiza a leitura dos dados do estudante, valida as condições mínimas de acesso, enquadra o aluno numa faixa social, determina o desconto base académico através de decisões aninhadas e aplica uma bonificação de pontualidade via operador ternário.

### Regras de Negócio Implementadas
* **Validação de Entrada (`if` / `if-else`):** Rejeita estudantes com idade inferior a 16 anos ou rendimento familiar menor ou igual a zero.
* **Classificação Social (`if-else-if`):**
  * Até R$ 2.000,00 $\rightarrow$ Faixa A[cite: 2].
  * De R$ 2.000,01 a R$ 5.000,00 $\rightarrow$ Faixa B[cite: 2].
  * Acima de R$ 5.000,00 $\rightarrow$ Faixa C[cite: 2].
* **Desconto Académico (`if` Aninhado):**
  * **Faixa A:** Média $\ge 8.5 \rightarrow 50\%$; Caso contrário $\rightarrow 30\%$[cite: 2].
  * **Faixa B:** Média $\ge 9.0 \rightarrow 25\%$; Caso contrário $\rightarrow 10\%$[cite: 3].
  * **Faixa C:** Média $\ge 9.5 \rightarrow 10\%$; Caso contrário $\rightarrow 0\%$[cite: 3].
* **Bónus de Pontualidade (Operador Ternário `?:`):** Concede $5\%$ adicional se o estado for `'S'`, ou $0\%$ se for `'N'`[cite: 3].

---

## 🧠 Questão Teórica

> **"Em qual situação do seu código o uso do operador ternário ?: é mais vantajoso que o if-else tradicional e em qual situação o if aninhado tornou-se indispensável?"**
>
> *Resposta:*
> O operador ternário (`?:`) é mais vantajoso no cálculo do bónus de pontualidade por se tratar de uma atribuição condicional direta e binária (`'S'` ou `'N'`), tornando o código mais conciso em apenas uma linha sem a verbosidade de blocos estruturais `if-else`. Por sua vez, o `if` aninhado tornou-se indispensável na análise do desconto académico, visto que as notas de corte e as percentagens atribuídas dependem do contexto prévio da faixa social em que o estudante foi classificado, exigindo uma tomada de decisão hierárquica em múltiplos níveis.

---

## 📂 Estrutura de Ficheiros

```text
Atividades/
└── Atividade03/
    ├── analise_bolsa.c
    ├── testes.txt
    └── README.md
