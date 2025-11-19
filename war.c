// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.






//---------------------NIVEL-NOVATO-----------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição de constantes que serão usadas posteriormente------------------------------
#define MAX_STRING 30
#define MAX_MUNDO 5

//Criação da struct------------------------------
typedef struct
{
    //faço uso das constantes para deixar o codigo mais organizado
    char nome[MAX_STRING];
    char cor[MAX_STRING];
    int tropas;
} Territorio;

int main()
{
    Territorio territorios[MAX_MUNDO];//cria um vetor array com 5 elementos(MAX_MUNDO)
    char buffer[50];//usado para ler texto de quantidade de tropas antes de converter para numero

    printf("Vamos cadastrar o 5 territorios iniciais do nosso mundo.\n");


    //Loop para o cadastro de territórios ---------------------------------------
    for (int i = 0; i < MAX_MUNDO; i++)//faz o loop 5 vezes para cadastro dos territórios
    {

        //Repete esse bloco de código até atingir o valor máximo de territórios(5)-------------------------
        printf("--- Cadastro de territorio %d: ---\n", i + 1);


        //o "fgets" ta lendo os dados que o usuário digita e atribuindo a variavel correta
        printf("Nome: ");
        fgets(territorios[i].nome, sizeof territorios[i].nome, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';//essa linha está responsável por tirar o \n e colocar um \0 no lugar para evitar erros, ja que o "fgets" sempre salva o \n junto

        printf("Cor: ");
        fgets(territorios[i].cor, sizeof territorios[i].cor, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Tropas: ");
        fgets(buffer, sizeof buffer, stdin);//lê a linha como uma string
        territorios[i].tropas = atoi(buffer);//converte pra inteiro e salva na variável correta

        printf("\n");

    }

    printf("\n=== Territorios cadastrados ===\n");

    //Loop para exibir os territórios cadastrados--------------------------

    for (int i = 0; i < MAX_MUNDO; i++)//faz o loop 5 vezes, agora pra exibir os territórios cadastrados
    {
        //imprime cada território com seus respectivos atributos 
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);//esse [i] é o índice, que serve para identificar qual território terá de ser exibido
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }
    

    return 0;
}
