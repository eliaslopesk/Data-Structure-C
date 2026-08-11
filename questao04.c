/*Questão 4: Um restaurante utiliza uma fila de impressão para os pedidos da cozinha.
Cada pedido tem um numero_pedido e o nome_prato. Implemente a estrutura e a função para
desenfileirar e exibir o próximo prato que a cozinha deve preparar.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Estrutura para representar um pedido
struct pedido {
 int numero_pedido;
 char nome_prato[50];
 struct pedido* prox;
};
typedef struct pedido Pedido;
// Estrutura para gerenciar a fila
struct fila_pedidos {
 Pedido* ini;
 Pedido* fim;
};
typedef struct fila_pedidos FilaPedidos;
// Função para criar e inicializar a fila
FilaPedidos* cria_fila_pedidos (void) { FilaPedidos* f = (FilaPedidos*) malloc(sizeof(FilaPedidos));
 if (f == NULL) exit(1);
 f->ini = f->fim = NULL;
 return f;
}
// Função para enfileirar um novo pedido (insere no fim)
void enfileirar_pedido (FilaPedidos* f, int num, char* prato) {
 Pedido* novo = (Pedido*) malloc(sizeof(Pedido));
 if (novo == NULL) {
 printf("Erro de memoria!\n");
 return;
 }
 novo->numero_pedido = num;
 strcpy(novo->nome_prato, prato);
 novo->prox = NULL;
 if (f->fim != NULL) {
 f->fim->prox = novo;
 } else {
 f->ini = novo;
 }
 f->fim = novo;
 printf("Pedido %d (%s) enviado para a cozinha.\n", num, prato);
}
// Função para desenfileirar e exibir o próximo prato
void desenfileirar_pedido (FilaPedidos* f) {
 if (f->ini == NULL) {
 printf("Nenhum pedido pendente para a cozinha.\n");
 return;
 }
 Pedido* temp = f->ini;
 // Exibe o próximo prato antes de remover
 printf("\n[COZINHA] Preparando agora o Pedido %d: %s\n", temp->numero_pedido, temp->nome_prato);
 f->ini = temp->prox;
 if (f->ini == NULL) {
 f->fim = NULL;
 }
 free(temp);
}
int main (void) {
 FilaPedidos* fp = cria_fila_pedidos();
 int opcao, num;
 char prato[50];
 do { printf("\n::: SISTEMA DE PEDIDOS DO RESTAURANTE :::\n\n");
 printf("1. Novo pedido (Enfileirar)\n");
 printf("2. Preparar proximo prato (Desenfileirar e Exibir)\n");
 printf("3. Sair\n");
 printf("Escolha: ");
 if (scanf("%d", &opcao) != 1) break;
 if (opcao == 1) {
 printf("Digite o numero do pedido: ");
 scanf("%d", &num);
 printf("Digite o nome do prato: ");
 scanf(" %49[^\n]", prato);
 enfileirar_pedido(fp, num, prato);
 } else if (opcao == 2) {
 desenfileirar_pedido(fp);
 }
 } while (opcao != 3);
 while (fp->ini != NULL) {
 Pedido* t = fp->ini;
 fp->ini = t->prox;
 free(t);
 }
 free(fp);
 return 0;
}
