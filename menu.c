#include "Funcao/opcoes.h"

int alternativa(int num);
void menu();

void main() {
  setlocale(LC_ALL, "Portuguese");
  int entrada = 0;
  realizarLogin();
  while (1) {
    if (entrada != 5) {
      //system("clear");
      menu();
      scanf("%d", &entrada);
      alternativas(entrada);
    } else {
      break;
    }
  }
}

int alternativas(int num) {
  switch (num) {
  case 1:
    saldo();
    break;
  case 2:
    consulExtrato();
    break;

  case 3:
    comprarCripto();
    printf("escolheu comprar criptomoedas\n");
    break;

  case 4:
    venderCripto();
    printf("escolheu venda de criptomoeda\n");
    break;

  case 5:
    //system("clear");
    printf("saindo...\n");
    break;

  default:
    printf("escolheu nenhum dos outros\n");
    break;
  }
  return 0;
}

void menu() {
  char *alternativa[6] = {
      "Consultar Saldo",    "Extrato", "Comprar Criptomoeda",
      "Vender Criptomoeda", "Sair",
  };

  //printf("%s", usuarios.nomes);
  
  int l;
  printf("--------------| Menu de opções |-----------------\n\n");
  for (l = 0; l < sizeof(alternativa) / sizeof(alternativa[0]) - 1; l++) {
    printf("%d . %-3s \n", l + 1, alternativa[l]);
  }
}

// Função de login que usa importarInfo()
int realizarLogin() {
    char nome[50]; // nome digitado pelo usuário
    char senha[50]; // senha digitada pelo usuário

    while (1) {
        printf("----------------| Login |-------------------\n\n");
        printf("Digite o nome de usuario: ");
        scanf("%s", nome);
        printf("Digite sua senha: ");
        scanf("%s", senha);

        // Chama a função importarInfo para obter os dados do usuário
        char** dadosUsuario = importarInfo(nome);

        if (dadosUsuario != NULL) {
            // O índice 1 da matriz contém a senha do usuário
            if (strcmp(senha, dadosUsuario[1]) == 0) {
                printf("\nLogin realizado com sucesso!\n");

                struct dados{
                  char *nomes[30];
                  char *senhas[10];
                  int bitcoin;
                  int etherium;
                  int ripple;
                };

                struct dados usuario;

                //strcpy(usuario.nomes, dadosUsuario[0]);
                //strcpy(usuario.senhas, dadosUsuario[1]);
                usuario.bitcoin = atoi(dadosUsuario[2]);
                usuario.etherium = atoi(dadosUsuario[3]);
                usuario.ripple = atoi(dadosUsuario[4]);
              
                return 1;  // Retorna 1 se o login foi bem-sucedido
            } else {
                printf("\nSenha incorreta. Tente novamente.\n\n");
            }
        } else {
            printf("\nUsuario nao encontrado. Tente novamente.\n\n");
        }
    }
}
