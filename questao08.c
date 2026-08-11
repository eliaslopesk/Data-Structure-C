/* Questão 8: Um supermercado registrou o horário de chegada de 10 fornecedores em formato de
minutos
decorridos no dia (ex: 480 para 08:00). Use o Insertion Sort para ordenar esses horários em ordem
cronológica crescente. */
#include <stdio.h>
#define TAM 10
// Função para imprimir os horários em formato de minutos
void imprime_minutos(int n, int* v) {
 for (int i = 0; i < n; i++) {
 printf("%d min ", v[i]);
 }
 printf("\n");
}
// Função para imprimir os horários formatados em HH:MM
void imprime_formatado(int n, int* v) {
 for (int i = 0; i < n; i++) {
 int horas = v[i] / 60;
 int minutos = v[i] % 60;
 printf("%02d:%02d ", horas, minutos);
 }
 printf("\n");
}
// Função de ordenação por inserção (Insertion Sort)
// n: número de elementos// v: ponteiro para o vetor de horários */
void insertion_sort(int n, int* v) {
 int i, j, atual;
 for (i = 1; i < n; i++) {
 atual = v[i];
 j = i - 1;
// Move os elementos que são maiores que o 'atual' para uma posição à frente
// de sua posição atual para abrir espaço
 while (j >= 0 && v[j] > atual) {
 v[j + 1] = v[j];
 j--;
 }
// Insere o elemento na posição correta
 v[j + 1] = atual;
 }
}
int main(void) {
 int horarios[TAM];
 int i;
 printf("\n::: ORDENACAO DE FORNECEDORES :::\n\n");
 printf("Digite o horario de chegada de %d fornecedores (em minutos decorridos):\n", TAM);
 printf("(Exemplo: 480 para 08:00, 600 para 10:00)\n");
 for (i = 0; i < TAM; i++) {
 printf("Fornecedor %d: ", i + 1);
 if (scanf("%d", &horarios[i]) != 1) {
 printf("Entrada invalida! Por favor, insira um numero inteiro.\n");
 return 1;
 }
 }
 printf("\nHorarios antes da ordenacao (minutos):\n");
 imprime_minutos(TAM, horarios);
// Chama a função de ordenação
 insertion_sort(TAM, horarios);
 printf("\nHorarios ordenados (minutos):\n");
 imprime_minutos(TAM, horarios);
 printf("\nHorarios ordenados (formato HH:MM):\n");
 imprime_formatado(TAM, horarios);
 return 0;
}
