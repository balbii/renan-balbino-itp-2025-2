# Campo Minado em C

## Como compilar

No terminal, dentro da pasta `src`, execute:

```sh
gcc -o campo_minado main.c
```

## Como jogar

1. Execute o programa:

   ```sh
   ./campo_minado
   ```

2. O tabuleiro será exibido. Para jogar, digite o número da linha e a letra da coluna (exemplo: `2 B`).

3. Para sair do jogo, digite `-1` quando for solicitado o número da linha.

## Regras

- O objetivo é abrir todas as casas seguras sem revelar uma bomba.
- Se abrir uma bomba, o jogo termina.
- O número exibido indica quantas bombas existem nas casas vizinhas.

