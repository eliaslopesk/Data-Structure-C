/* Questão 9: Um galpão possui 15 posições de armazenamento não ordenadas, cada uma com um
codigo_barras (int). Implemente uma busca linear que retorne o índice do vetor onde o códigodigitado pelo operador se encontra, ou -1 se não existir. */
#include <stdio.h>
#define TAM 15
// Função para exibir o estado atual do galpão
void exibir_galpao(int n, int* vet) {
 printf("\n::: ESTADO ATUAL DO GALPAO :::\n");
 for (int i = 0; i < n; i++) {
 printf("[Posicao %02d]: Codigo %d\n", i, vet[i]);
 }
}
/* Busca linear: percorre o vetor elemento por elemento
 n: número de elementos
 vet: ponteiro para o vetor de códigos
 elem: o código de barras que estamos procurando */
int busca_linear(int n, int* vet, int elem) {
 int i;
 for (i = 0; i < n; i++) {
 if (elem == vet[i]) {
 return i; // Retorna o índice exato onde encontrou o elemento
 }
 }
 return -1; // Retorna -1 se percorreu todo o vetor e não achou
}
int main(void) {
 int galpao[TAM];
 int i, codigo_busca;
 printf("\n::: SISTEMA DE BUSCA DO GALPAO :::\n\n");
 printf("Por favor, cadastre o codigo de barras das %d posicoes:\n", TAM);
 for (i = 0; i < TAM; i++) {
 printf("Posicao %02d: ", i);
 if (scanf("%d", &galpao[i]) != 1) {
 printf("Erro: Entrada invalida!\n");
 return 1;
 }
 }
// Opcional: Mostra o que foi cadastrado
 exibir_galpao(TAM, galpao);
 printf("\nDigite o codigo de barras que deseja localizar: ");
 if (scanf("%d", &codigo_busca) != 1) {
 printf("Erro: Entrada invalida!\n");
 return 1;
 }// Realiza a busca
 int resultado = busca_linear(TAM, galpao, codigo_busca);
 if (resultado != -1) {
 printf("\n>>> SUCESSO: Codigo %d encontrado na Posicao %d do galpao.\n", codigo_busca,
resultado);
 } else {
 printf("\n>>> AVISO: Codigo %d nao encontrado em nenhuma posicao do galpao.\n",
codigo_busca);
 }
 return 0;
}
