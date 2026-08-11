/* Questão 6: Implemente o sistema de "Desfazer" (Undo) do painel de cadastro de produtos de uma
loja.
 Cada ação realizada guarda o preco_antigo (float). Use uma pilha para restaurar o último preço
 modificado caso o usuário clique em desfazer. */
#include <stdio.h>
#include <stdlib.h>
// Estrutura para representar cada elemento da pilha
struct acao {
 float preco_antigo;
 struct acao* prox;
};
typedef struct acao Acao;
// Estrutura para representar a Pilha
struct pilha_undo {
 Acao* topo;
};
typedef struct pilha_undo PilhaUndo;
// Função para criar a pilha
PilhaUndo* cria_undo(void) {
 PilhaUndo* p = (PilhaUndo*) malloc(sizeof(PilhaUndo));
 if (p == NULL) {
 printf("Erro de alocacao!\n");
 exit(1);
 }
 p->topo = NULL;
 return p;
}
// Função para verificar se a pilha está vazia
int pilha_vazia(PilhaUndo* p) {
 return (p->topo == NULL);
}
// Função para empilhar
void registrar_acao(PilhaUndo* p, float preco_antigo) { Acao* nova = (Acao*) malloc(sizeof(Acao));
 if (nova == NULL) {
 printf("Erro de alocacao!\n");
 exit(1);
 }
 nova->preco_antigo = preco_antigo;
 nova->prox = p->topo;
 p->topo = nova;
}
// Função para desempilhar
// Retorna o preço antigo restaurado ou -1 se a pilha estiver vazia
float desfazer(PilhaUndo* p) {
 if (pilha_vazia(p)) {
 printf("Nao ha acoes para desfazer.\n");
 return -1.0f;
 }
 Acao* t = p->topo;
 float restaurado = t->preco_antigo;
 p->topo = t->prox;
 free(t);
 return restaurado;
}
// Função para liberar toda a memória da pilha
void libera_pilha(PilhaUndo* p) {
 Acao* t = p->topo;
 while (t != NULL) {
 Acao* aux = t->prox;
 free(t);
 t = aux;
 }
 free(p);
}
int main(void) {
 PilhaUndo* undo = cria_undo();
 int opcao;
 float preco_atual = 0.0f;
 float novo_preco;
 do {
 printf("\n:::PAINEL DE PRODUTOS :::\n\n");
 printf("Preco Atual: R$ %.2f\n", preco_atual);
 printf("1. Alterar preco\n");
 printf("2. Desfazer ultima alteracao\n");
 printf("3. Sair\n");
 printf("Escolha: ");
 if (scanf("%d", &opcao) != 1) {
 printf("Entrada invalida!\n");
 break;
 } if (opcao == 1) {
 printf("Digite o novo preco: ");
 scanf("%f", &novo_preco);
// Antes de alterar, salvamos o preço atual na pilha de undo
 registrar_acao(undo, preco_atual);
 preco_atual = novo_preco;
 printf("Preco alterado com sucesso!\n");
 } else if (opcao == 2) {
 float aux = desfazer(undo);
 if (aux != -1.0f) {
 preco_atual = aux;
 printf("Acao desfeita! Preco restaurado para: R$ %.2f\n", preco_atual);
 }
 }
 } while (opcao != 3);
 libera_pilha(undo);
 printf("Sistema encerrado.\n");
 return 0;
}
