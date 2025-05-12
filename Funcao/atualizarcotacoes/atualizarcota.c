#include "../opcoes.h"

char **obterCotacoes(){
  // abre o arquivo de cotacoes.txt para obter os valores das cotacoes das moedas
  FILE *cotacoes = fopen("cotacoes.txt", "r");
  if(cotacoes == NULL){
    printf("Erro ao abrir o arquivo.\n");
    return NULL;
  }

  char *valores[255];
  int cotas=0;

  //um buffer para armazernar o valor da linha
  char buffer[255];
  while(fgets(buffer, sizeof(buffer), cotacoes)){
    //delimitador para separar por virgula e por quebra da linha
    char *delimitador = strtok(buffer, ",\n");
    //verifica se o delimitador não acabou
    while(delimitador != NULL){
      valores[cotas] = strdup(delimitador);
      //faz uma copia e remove ultimas quebras de linha e virgulas
      delimitador = strtok(NULL, ",\n");
      cotas++;
    }
    free(delimitador);
  }
  //retorna os valores das cotacoes das moedas e seus nomes
  return valores;
  fclose(cotacoes);
}

int atualizarcotacao(){
  //array com os nomes e valores das moedas em cada indice em formato de string
  char **cotacoes = {obterCotacoes()};
  int cotacao;
    int contador;

  //abre o arquivo de cotacoes.txt para atualizar os valores das cotacoes das moedas
    FILE *cotacoesatualizadas = fopen("cotacoes.txt", "w");
      if(cotacoesatualizadas == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
      }
      else{
      printf("----------| Acesso as novas cotações |----------------\n");
      for(contador=0; contador<6; contador++){

        //identifica se o indice é par ou impar para saber se é o nome ou o valor da moeda
        if(contador%2 != 1){
          fprintf(cotacoesatualizadas, "%s,", cotacoes[contador]);
        }
          //atualiza o valor da moeda
        else{
          printf("cotação da moeda %s anteriormente: %s\n", cotacoes[contador-1],cotacoes[contador]);
          cotacao = atoi(cotacoes[contador]);
          cotacao = cotacao + cotacao * (rand()%4)/100.0; 
          printf("Cotação atualizada: %d\n", cotacao);
          fprintf(cotacoesatualizadas, "%d\n", cotacao);
        }
      }
    }
  printf("-------------------------------------------------------\n");
  fclose(cotacoesatualizadas);
}