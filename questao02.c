/*Uma empresa de entregas gerencia rotas usando uma lista sequencial de paradas.Cada parada
possui o nome do bairro (string) e prazo_minutos (int). Implemente uma função
para remover uma parada da rota quando a entrega for concluída.
Vetores e listas sequenciais */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
// Struct que guarda os dados de uma parada
struct parada {
 char bairro[50];
 int prazo_minutos;
};
typedef struct parada Parada;
// Struct da rota, usando um vetor estático e uma variável 'n'// para controlar quantos elementos estão cadastrados de fato
struct rota {
 int n;
 Parada vet[MAX];
};
typedef struct rota Rota;
// Função para criar a rota alocando dinamicamente a struct
Rota* cria_rota (void) {
 Rota* r = (Rota*) malloc(sizeof(Rota));
 r->n = 0; /* Começa com 0 paradas */
 return r;
}
// Função para inserir uma parada no final da lista sequencial
void insere_parada (Rota* r, char* bairro, int prazo) {
 if (r->n >= MAX) {
 printf("A rota esta cheia!\n");
 return;
 }
 strcpy(r->vet[r->n].bairro, bairro);
 r->vet[r->n].prazo_minutos = prazo;
 r->n++; // Incremento o tamanho lógico da lista
}
// Função para remover uma parada quando a entrega for concluída
void remove_parada (Rota* r, char* bairro_concluido) {
 int i, pos = -1;
// Primeiro acho em qual índice do vetor está o bairro
 for (i = 0; i < r->n; i++) {
 if (strcmp(r->vet[i].bairro, bairro_concluido) == 0) {
 pos = i;
 break;
 }
}
 if (pos == -1) {
 printf("Bairro '%s' nao encontrado na rota.\n", bairro_concluido);
 return;
}
// Desloco todos os elementos seguintes uma casa para a esquerda
// para tapar o buraco deixado pelo item removido
 for (i = pos; i < r->n - 1; i++) {
 r->vet[i] = r->vet[i + 1];
 }
 r->n--; //Reduzo o tamanho lógico
 printf("Parada no bairro '%s' concluida e removida da rota!\n", bairro_concluido);
}
void libera_rota (Rota* r) {
 free(r);
}
int main (void) {
 Rota* rota = cria_rota();
 int opcao, prazo; char bairro[50];do {
 printf("\n::: GERENCIAMENTO DE ROTAS :::\n\n");
 printf("1. Adicionar parada\n");
 printf("2. Concluir/remover entrega\n");
 printf("3. Sair\n");
 printf("Escolha: ");
 scanf("%d", &opcao);
 if (opcao == 1) {
 printf("Digite o nome do bairro: ");
 scanf(" %49[^\n]", bairro);
 printf("Digite o prazo em minutos: ");
 scanf("%d", &prazo);
 insere_parada(rota, bairro, prazo);
 } else if (opcao == 2) {
 printf("Digite o bairro da entrega concluida: ");
 scanf(" %49[^\n]", bairro);
 remove_parada(rota, bairro);
 }
 } while (opcao != 3); printf("\nParadas restantes na rota: %d\n", rota->n);
 libera_rota(rota);
 return 0;
}
