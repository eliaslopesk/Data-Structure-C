/* Questão 5: No estoque de uma importadora, as caixas são empilhadas em um palete estreito
(LIFO). A última caixa colocada é a primeira a ser retirada. Implemente as funções
empilhar_caixa e desempilhar_caixa, registrando o codigo_rastreio de cada caixa.*/
#include <stdio.h>
#include <stdlib.h>
// Estrutura para representar uma caixa
struct caixa {
 int codigo_rastreio;
 struct caixa* prox;
};
typedef struct caixa Caixa;
// Estrutura para gerenciar a pilha
struct pilha {
 Caixa* topo;
};
typedef struct pilha Pilha;
// Função para criar e inicializar a pilha
Pilha* cria_pilha (void) {
 Pilha* p = (Pilha*) malloc(sizeof(Pilha)); if (p == NULL) exit(1);
 p->topo = NULL;
 return p;
}
// Função para empilhar uma nova caixa
void empilhar_caixa (Pilha* p, int codigo) {
 Caixa* novo = (Caixa*) malloc(sizeof(Caixa));
 if (novo == NULL) {
 printf("Erro de memoria!\n");
 return;
 }
 novo->codigo_rastreio = codigo;
 novo->prox = p->topo;
 p->topo = novo;
 printf("Caixa com codigo %d empilhada com sucesso.\n", codigo);
}
// Função para desempilhar a caixa do topo
void desempilhar_caixa (Pilha* p) {
 if (p->topo == NULL) {
 printf("A pilha esta vazia! Nenhuma caixa para retirar do palete.\n");
 return;
 }
 Caixa* temp = p->topo;
 int codigo = temp->codigo_rastreio;
 p->topo = temp->prox;
 free(temp);
 printf("Caixa com codigo %d retirada do topo do palete.\n", codigo);
}
int main (void) {
 Pilha* p = cria_pilha();
 int opcao, codigo;
 do {
 printf("\n::: SISTEMA DE ESTOQUE :::\n\n");
 printf("1. Empilhar caixa (empilhar_caixa)\n");
 printf("2. Retirar caixa do topo (desempilhar_caixa)\n");
 printf("3. Sair\n");
 printf("Escolha: ");
 if (scanf("%d", &opcao) != 1) break;
 if (opcao == 1) {
 printf("Digite o codigo de rastreio da caixa: ");
 scanf("%d", &codigo);
 empilhar_caixa(p, codigo);
 } else if (opcao == 2) { desempilhar_caixa(p);
 }
 } while (opcao != 3);
// Limpeza da memória antes de encerrar
 while (p->topo != NULL) {
 desempilhar_caixa(p);
 }
 free(p);
 return 0;
}
