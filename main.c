#include "Funcao/opcoes.h"

int alternativa(int num, char*cpf);
void menu();
//declara structs globais para acesso de outros arquivos e funções
struct dados usuario;
struct moedas moedas;

int alternativa(int num, char*cpf) {
  char senha[100];
  switch (num) {
  case 1:
    printf("Digite sua senha para consultar o saldo: ");
    scanf("%s", senha);
    if (verificarSenha(cpf, senha)) {
    saldo(&moedas);
    } else {
    printf("Senha incorreta.\n");
    }
    break;

  case 2:
    while(1){
    printf("Digite sua senha para efetuar o saque: ");
    scanf("%s", senha);
      if (verificarSenha(cpf, senha)) {
    saque(cpf);
    }   else {
        printf("\nSenha incorreta. Tente novamente.\n\n");
        sleep(2);
        }
        return 1;
        }

  case 3:
    while(1){
      printf("Digite sua senha para efetuar o deposito: ");
      scanf("%s", senha);
        if (verificarSenha(cpf, senha)) {
      deposito(cpf, &moedas);
      }   else {
          printf("\nSenha incorreta. Tente novamente.\n\n");
          sleep(2);
          }
          return 1;
          }

  case 4:
    consultarExtrato(cpf);
    break;

  case 5:
    while(1){
      printf("Digite sua senha para comprar criptomoeda: ");
      scanf("%s", senha);
        if (verificarSenha(cpf, senha)) {
          comprarCripto(cpf, &moedas);
      }   else {
          printf("\nSenha incorreta. Tente novamente.\n\n");
          sleep(2);
          }
          return 1;
          }
    break;

  case 6:
    while(1){
      printf("Digite sua senha para vender criptomoeda: ");
      scanf("%s", senha);
        if (verificarSenha(cpf, senha)) {
          venderCripto(cpf, &moedas);
      }   else {
          printf("\nSenha incorreta. Tente novamente.\n\n");
          sleep(2);
          }
          return 1;
          }

  case 7:
    while(1){
      printf("Digite sua senha para atualizar cotações: ");
      scanf("%s", senha);
        if (verificarSenha(cpf, senha)) {
          atualizarcotacao();
      }   else {
          printf("\nSenha incorreta. Tente novamente.\n\n");
          sleep(2);
          }
          return 1;
          }

  case 8:
    system("clear");
    printf("saindo...\n");
    exit(0);

  default:
    printf("escolheu nenhum dos outros\n");
    break;
  }
  return 0;
}

void menu() {
  char *alternativa[9] = {
    "Consultar Saldo",
    "Saque",
    "Depósito",
    "Extrato",
    "Comprar Criptomoeda",
    "Vender Criptomoeda",
    "Atualizar Cotação",
    "Sair",
  };
  int l;
  printf("--------------| Menu de opções |-----------------\n\n");
  for (l = 0; l < sizeof(alternativa) / sizeof(alternativa[0]) - 1; l++) {
    printf("%d . %-3s \n", l + 1, alternativa[l]);
  }
}

char* realizarLogin() { // Modificado para retornar o CPF
  char *cpf = malloc(15 * sizeof(char)); // Aloca memória para o CPF
  char senha[100];

  while (1) {
    printf("----------------| Login |-------------------\n\n");
    printf("Digite o CPF do usuario: ");
    scanf("%s", cpf);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    char **dadosUsuario = importarInfo(cpf); // Obtém os dados do usuário
  if (verificarSenha(cpf, senha)) {
    printf("\nLogin realizado com sucesso!\n");

    usuario.cpf = atoi(dadosUsuario[0]);
    usuario.senhas = atoi(dadosUsuario[1]);
    moedas.saldo_reais = atof(dadosUsuario[2]);
    moedas.total_moedas = 3;
    moedas.cpf_moedas = atoi(dadosUsuario[1]);
    moedas.nome_moeda[0] = "bitcoin";
    moedas.nome_moeda[1] = "ethereum";
    moedas.nome_moeda[2] = "ripple";
    moedas.valor[0] = atof(dadosUsuario[3]);
    moedas.valor[1] = atof(dadosUsuario[4]);
    moedas.valor[2] = atof(dadosUsuario[5]);
    
      return cpf; // Retorna o CPF alocado  
        } else {
          printf("\nCredenciais incorretas. Tente novamente.\n\n");
          free(cpf); // Libera a memória alocada para cpf
          cpf = malloc(15 * sizeof(char)); // Realoca memória para o CPF
        }
      }
    return NULL; // Retorna NULL em caso de falha no login
  }

int main() {
  setlocale(LC_ALL, "");
  int entrada = 0;
  char *cpfUsuario = realizarLogin(); // Recebe o CPF do usuário logado
  if (cpfUsuario == NULL){
    return 1;
  }
  while (1) {
    //system("clear");
    menu();
    scanf("%d", &entrada);
    alternativa(entrada, cpfUsuario); // Passa o CPF para a função alternativa
  }
  free(cpfUsuario); // Libera a memória alocada para cpfUsuario
  return 0;
 }