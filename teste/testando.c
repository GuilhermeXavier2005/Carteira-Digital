#include "../Funcao/opcoes.h"

char* testesC(int g){
  char *Nomes[]={"guilherme", "joao", "maria", "pedro"};
  char *passagemString[] = {Nomes[g]};

  return *passagemString;
}