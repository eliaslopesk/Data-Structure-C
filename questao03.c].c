/* Questão 3: Um parque de diversões gerencia a entrada de uma montanha-russa usando uma fila
(FIFO).
 Implemente as funções enfileirar_turista (insere no fim) e atender_turista (remove do início),
 armazenando o nome e a idade do visitante. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Struct do nó do turista
struct turista {
 char nome[50];
 int idade;
 struct turista* prox;
};
typedef struct turista Turista;
// Struct da fila guardando ponteiro para o início e para o fim
struct fila {
 Turista* ini;
 Turista* fim;
};
typedef struct fila Fila;
// Cria a fila apontando ini e fim para NULL
Fila* cria_fila (void) {
 Fila* f = (Fila*) malloc(sizeof(Fila)); if (f == NULL) exit(1);
 f->ini = f->fim = NULL;
 return f;
}
// Enfileirar: bota o turista no final da fila (conforme pedido na questão)
void enfileirar_turista (Fila* f, char* nome, int idade) {
 Turista* novo = (Turista*) malloc(sizeof(Turista));
 if (novo == NULL) {
 printf("Erro de memoria!\n");
 return;
 }
 strcpy(novo->nome, nome);
 novo->idade = idade;
 novo->prox = NULL;
 if (f->fim != NULL) {
 f->fim->prox = novo; // Liga o último atual ao novo nó
 } else {
 f->ini = novo; // Se a fila estava vazia, o novo também é o início
 }
 f->fim = novo; // O novo nó passa a ser o fim da fila
 printf("Turista %s adicionado a fila.\n", nome);
}
// Atender turista: remove do início da fila (FIFO) (conforme pedido na questão)
void atender_turista (Fila* f) {
 if (f->ini == NULL) {
 printf("A fila esta vazia! Ninguem para atender.\n");
 return;
 }
 Turista* temp = f->ini; // Guarda o nó que vai ser removido
 printf("\n>>> Chamando turista: %s (%d anos) para a montanha-russa!\n", temp->nome, temp->idade);
 f->ini = temp->prox; // O início passa a ser o próximo da fila
 if (f->ini == NULL) {
 f->fim = NULL; // Se a fila ficou vazia, o fim também deve ser NULL
 }
 free(temp); // Libera a memória do turista atendido
}
int main (void) {
 Fila* f = cria_fila();
 int opcao, idade;
 char nome[50];
 do {
 printf("\n::: FILA MONTANHA-RUSSA :::\n\n"); printf("1. Entrar na fila (Enfileirar)\n");
 printf("2. Atender proximo (Atender)\n");
 printf("3. Sair\n");
 printf("Escolha: ");
 if (scanf("%d", &opcao) != 1) break;
 if (opcao == 1) {
 printf("Digite o nome do visitante: ");
 scanf(" %49[^\n]", nome); // Correção para aceitar nomes com espaços
 printf("Digite a idade: ");
 scanf("%d", &idade);
 enfileirar_turista(f, nome, idade);
 } else if (opcao == 2) {
 atender_turista(f);
 }
 } while (opcao != 3);
 // Liberação básica de memória antes de sair
 while (f->ini != NULL) {
 atender_turista(f);
 }
 free(f);
 return 0;
}
