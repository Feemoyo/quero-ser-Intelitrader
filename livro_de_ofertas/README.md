# Livro de Ofertas

Este projeto implementa um livro de ofertas utilizando C++ com funcionalidades para manipulação e impressão das ofertas.

## Funcionalidades

### Classe `Ofertas`

A classe `Ofertas` possui métodos para:

- `setInput(std::string input)`: Processa e define uma nova oferta com base em uma string de entrada.
- `setInVector(int index, int operacao, t_oferta aux)`: Insere, atualiza ou remove uma oferta no vetor de ofertas.
- `printOutput()`: Imprime todas as ofertas atualmente registradas.

### Exceções Personalizadas

A classe define exceções personalizadas para tipos inválidos, operações inválidas e inputs negativos.

## Compilação e Execução

Para compilar o projeto, utilize um compilador C++ compatível (por exemplo, g++):

```bash
g++ main.cpp -o livro_de_ofertas

./livro_de_ofertas
```

### Entrada do Usuário
O programa espera que o usuário forneça uma série de entradas seguindo o formato especificado para manipular as ofertas.

- A primeira linha da entrada contém o número de notificações. `ex: 12`

- Cada linha subsequente contém uma notificação no formato: <posição>,<ação>,<valor>,<quantidade>. `ex: 1,0,15.4,50`

- <ação> é representada por um inteiro (0 para INSERIR, 1 para MODIFICAR e 2 para DELETAR).


#### Exemplo de Inputs
```bash
12
1,0,15.4,50
2,0,15.5,50
2,2,0,0
2,0,15.4,10
3,0,15.9,30
3,1,0,20
4,0,16.50,200
5,0,17.00,100
5,0,16.59,20
6,2,0,0
1,2,0,0
2,1,15.6,0
```

### Saída:

O programa imprime o estado final das ofertas após processar todas as notificações.
Cada oferta é impressa no formato: <posição>,<valor>,<quantidade>.

#### Output esperado
```bash
1,15.4,10
2,15.6,0
3,16.50,200
4,16.59,20
```
