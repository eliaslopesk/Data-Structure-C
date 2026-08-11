/*Crie uma lista encadeada para armazenar o carrinho de compras de um cliente.
Cada nó deve conter o ID_produto (int), quantidade (int) e preco (float). Implemente uma função
para inserir um novo item e outra para calcular o valor total do carrinho. */
#include <stdio.h>
#include <stdlib.h>
/* Definição da struct do nó da lista. Cada item guarda
 o ID do produto, quantidade, preço e o ponteiro pro próximo nó */
struct carrinho {
 int id_produto;
 int quantidade;
 float preco;
 struct carrinho* prox;
};
typedef struct carrinho Carrinho;
// Função que inicia a lista vazia, apenas retornando NULL
Carrinho* inicializa (void) {
 return NULL;
}
// Função para inserir um novo item
Carrinho* insere (Carrinho* l, int id, int qtd, float preco) {
 Carrinho* novo = (Carrinho*) malloc(sizeof(Carrinho));
 if (novo == NULL) {
 printf("Erro: memoria insuficiente!\n");
 exit(1);
 }
 novo->id_produto = id;
 novo->quantidade = qtd;
 novo->preco = preco;
 novo->prox = l; // O novo nó aponta para o antigo primeiro
 return novo; // Retorna o novo endereço da lista
}
// Função que percorre a lista multiplicando qtd * preço e somando tudo
float calcula_total (Carrinho* l) {
 float total = 0.0;
 Carrinho* p;
 for (p = l; p != NULL; p = p->prox) {
 total += (p->quantidade * p->preco);
 }
 return total;
}
//Função para liberar a memória alocada dinamicamente, evitando vazamento
void libera (Carrinho* l) {
 Carrinho* p = l;
 while (p != NULL) {
 Carrinho* t = p->prox;
 free(p);
 p = t; }
}
int main (void) {
 Carrinho* meu_carrinho = inicializa();
 int opcao, id, qtd;
 float preco;
 // Laço do-while para criar um menu interativo para o usuário
 do {
 printf("\n::: CARRINHO DE COMPRAS :::\n\n");
 printf("1. Adicionar item\n");
 printf("2. Ver valor total e sair\n");
 printf("Escolha uma opcao: ");
 scanf("%d", &opcao);
 if (opcao == 1) {
 printf("Digite o ID do produto: ");
 scanf("%d", &id);
 printf("Digite a quantidade: ");
 scanf("%d", &qtd);
 printf("Digite o preco unitario: ");
 scanf("%f", &preco);
 meu_carrinho = insere(meu_carrinho, id, qtd, preco);
 printf("Item adicionado com sucesso!\n");
 }
 } while (opcao != 2);
// Mostra o resultado final e libera a memória antes de fechar
 printf("\nValor total do carrinho: R$ %.2f\n", calcula_total(meu_carrinho));
 libera(meu_carrinho);
 return 0;
}
