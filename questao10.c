/* Questão 10: Uma grande rede de lojas possui um vetor com 1000 IDs de clientes rigorosamente
ordenados
 de forma crescente. Implemente uma busca binária para localizar rapidamente se um determinado
ID de
 cliente está ativo na base de dados. */
#include <stdio.h>
#include <stdlib.h>
// Definindo o tamanho v[1000]
#define TAM 1000
// Função para verificar se o vetor está realmente ordenado
int esta_ordenado(int n, int* v) {
 for (int i = 0; i < n - 1; i++) {
 if (v[i] > v[i + 1]) return 0;
 }
 return 1;
}
/* Busca binária iterativa: divide o campo de busca pela metade a cada passo
 n: número de elementos
 vet: vetor ordenado
 elem: ID que estamos procurando */
int busca_binaria(int n, int* vet, int elem) {
 int ini = 0;
 int fim = n - 1;
 int meio;
 while (ini <= fim) {
 meio = (ini + fim) / 2;
 if (elem < vet[meio]) {
 fim = meio - 1;
 } else if (elem > vet[meio]) {
 ini = meio + 1;
 } else {
 return meio;
 } }
 return -1;
}
int main(void) {
 int* clientes = (int*) malloc(TAM * sizeof(int));
 if (clientes == NULL) {
 printf("Erro de alocacao de memoria!\n");
 return 1;
 }
 int i, id_busca, total_clientes;
 printf("\n::: SISTEMA DE BUSCA DE CLIENTES (BINARIA) :::\n");
 printf("Quantos clientes deseja cadastrar agora (max %d)? ", TAM);
 scanf("%d", &total_clientes);
 if (total_clientes > TAM) total_clientes = TAM;
 printf("Digite os %d IDs em ordem CRESCENTE:\n", total_clientes);
 for (i = 0; i < total_clientes; i++) {
 printf("ID Cliente %d: ", i + 1);
 scanf("%d", &clientes[i]);
 }
// Validação de segurança
 if (!esta_ordenado(total_clientes, clientes)) {
 printf("\nERRO: Os IDs nao foram digitados em ordem crescente!\n");
 printf("A busca binaria nao funcionara corretamente.\n");
 } else {
 printf("\nDigite o ID do cliente que deseja localizar: ");
 scanf("%d", &id_busca);
// Realiza a busca binária
 int pos = busca_binaria(total_clientes, clientes, id_busca);
 if (pos != -1) {
 printf("\n>>> SUCESSO: Cliente ID %d encontrado na posicao %d da base.\n", id_busca,
pos);
 } else {
 printf("\n>>> AVISO: Cliente ID %d nao encontrado na base de dados.\n", id_busca);
 }
 }
 free(clientes);
 return 0;
}
