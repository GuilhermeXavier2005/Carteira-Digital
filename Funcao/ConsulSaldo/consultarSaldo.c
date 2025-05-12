#include "../opcoes.h"

//obtem o struct com as informacoes da moeda do usuario
void saldo(struct moedas *informacoes) {
  system("clear");
    int i;

    setlocale(LC_ALL, "");
    printf("-----------------------\nesses são seus saldos em respectivas "
           "moedas\n-----------------------\n");
  //exibe por referencias os respectivos valores das moedas do usuario
  printf("saldo em reais: %f\n", informacoes->saldo_reais);
  for(i=0;i<informacoes->total_moedas;i++){
      printf("%s : %.2f\n", informacoes->nome_moeda[i], informacoes->valor[i]);
    }
  
  sleep(5);
}
