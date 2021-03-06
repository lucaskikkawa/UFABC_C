#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

/*
  *           UNIVERSIDADE FEDERAL DO ABC
  * PROJETO 01 - PROGRAMAÇÃO ESTRUTURADA - PROF. DR. WAGNER TANAKA

  * GRUPO 06 - TURMA B1 NOTURNO
    JOÃO VICTOR RIBEIRO MARTINS VIEIRA  RA: 11201810775
    LUCAS KIKKAWA PERPETUA              RA: 11201810415
    LUCAS CAMARGO SPINELI               RA: 11201932454
    NATHALYA DOS SANTOS                 RA: 11201810440
    YASMIN MARTINEZ PERES               RA: 11201720162

  * Programa: Jogo da Memória em Linguagem C.

*/

/* Protótipos */
int inputUsuario_Resultados(int linha, int coluna, int jogo[4][4]);
void aleatorio(void);

int inputUsuario_Resultados(int linha, int coluna, int jogo[4][4]){ // linha e coluna vem da funcao NivelDificuldade
    //Linha 60 até 86 => Yasmin

    // matriz jogo -> gerado pela funcao nivelDificuldade e preenchida aleatoriamente
    int matriz_Usuario[linha][coluna]; // matriz preenchida pelo usuario, usada para comparar com matriz jogo
    int jogada = 0; // jogada do usuario
    int acertos = 0; // quantidade de acertos de pares de memoria do usuario
    int erros = 0;
    int c1, c2, c3, c4;

    for(int i=0; i<4;i++){
        for(int j = 0; j<4; j++){
            matriz_Usuario[i][j] = 0;
        }
    }

    while (jogada < 2*linha) // contpar foi inicializado com 0, ou seja, quando contpar/número de acertos chegar a 8, o jogo acaba
    {
        printf("Entre com uma coordenada (Exemplo: 4 4): ");
        scanf("%d %d", &c1, &c2);
        printf("O numero da posicao [%d] [%d] eh %d\n",c1,c2, jogo[c1 - 1][c2 -1]);
        printf("Entre com outra coordenada: ");
        scanf("%d %d", &c3, &c4);
        printf("O numero da posicao [%d] [%d] eh %d\n",c3,c4, jogo[c3 - 1][c4 -1]);
        // com isso foi pedido as coordenadas para localizar os pares na matriz jogo
        c1 = c1 - 1;
        c2 = c2 - 1;
        c3 = c3 - 1;
        c4 = c4 - 1;
// Linha 88 até 122 => João

        // Aqui nós temos nossas condições, se o valor da coordenada 1 for = a da coordenada 2 Ele vai somar um ponto pro jogador da vez,
        // substituir o valor certo na matriz escondida, para o jogador ver os acertos e somar um ponto para o número de acertos. Depois ele vai
        // reimprimir a matriz esc com os pares acertaos impressos
        if (jogo[c1][c2] == jogo[c3][c4] && matriz_Usuario[c1][c2] == 0 && matriz_Usuario[c3][c4] == 0)
        {
            acertos++;
            jogada++;
            matriz_Usuario[c1][c2] = jogo[c1][c2];
            matriz_Usuario[c3][c4] = jogo[c3][c4];

            for (int a = 0; a < linha; a++)
            {
                for (int b = 0; b < coluna; b++)
                {
                    printf("%d ", matriz_Usuario[a][b]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Errou, tente de novo\n");
            erros++;
        }
        if(erros == 3){
            printf("Numero maximo de erros atingidos. Voce perdeu :(\n");
            break;
        }
    }

    printf("Voce acertou %d pares e errou %d", acertos, erros);

    return 0;
}


int main(void){
    aleatorio();

    return 0;

    //funcao gerar numeros aleatorios do nivel que o usuario escolheu
}

void aleatorio(void){
    //Linha 130 até 168 => nathalya
    int matriz[4][4];
    int intervalo = 30, c;
    int contador = 0;
    int numAleatorio = 0;
    int temporaria = 0;
    int linhaAleat = 0;
    int colunaAleat = 0;
    int tam = 4;
    int tempo = 20;

    printf("Decore os numeros exibidos em ate 20 segundos e depois digite os numeros na \nordem que foram exibidos.\n");
    printf("Apos 3 tentativas incorretas o jogo sera encerrado\n");
    printf("Aperte ENTER para iniciar o jogo.\n");

    do{
        c = getch();//para o usuario apertar o enter
    }while (c != 13);//(13 é o código do enter), enquanto ele não apertar o enter, o jogo não comeca

    numAleatorio = (rand() % intervalo); // Definir o primeiro numero aleatorio, antes de entrar no for

    //For criado para preencher as posiçoes da matriz, preenchendo 1 numero aletorio em duas posições em sequencia
    for(int i=0;i<tam;i++){
       for(int j=0;j<tam; j++){
          if (contador < 2) // Contador para verificar se já há 1 par do numero aleatorio
          {
            matriz[i][j] = numAleatorio; // Atribuição do numero aleatorio
            contador = contador + 1;
          }
          else // Caso o contador esteja em 2, o numero ja esta em 2 posições
          {
            numAleatorio = (rand() % intervalo); // Gerar outro numero aleatorio
            matriz[i][j] = numAleatorio; // Atribuição do numero aleatorio
            contador = 1; // Reiniciar contador
          }

    }
}

//Linha 171 até 182 => Lucas
    // Trecho para embaralhar as posiçoes da matriz
    for ( int i = 0; i < tam; i++ ) { // Passar por todas as linhas
        for ( int j = 0; j < tam; j++ ) { // Passar por todas as colunas
            linhaAleat = rand( ) % tam; // Gerar uma posição de linha aleatoria na matriz
            colunaAleat = rand( ) % tam; // Gerar uma posição de coluna aleatoria na matriz
            temporaria = matriz[ i ][ j ]; // Guardar o numero posicionado na matriz (i e j)

            // Atribuir onde esta posicionado o valor da posição aleatoria
            matriz[ i ][ j ] = matriz[ linhaAleat ][ colunaAleat ];
            matriz[ linhaAleat ][ colunaAleat ] = temporaria; // Trocar o valor com a posição aleatoria
        }
    }
//Linha 184 até 198 => Lucas K. (falar do protótipo)
    do{
        system ("cls");//limpar a tela
        printf ("Decore os numeros abaixo em %d\n\n\n", tempo--);
        //diminuindo o tempo
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam; j++){
                printf ("%d\t", matriz[i][j]);
            }
            printf("\n");
        }

        sleep(1);
    }while(tempo>0);

    system ("cls");


    inputUsuario_Resultados(tam, tam, matriz);

    printf ("\n\n");

}
