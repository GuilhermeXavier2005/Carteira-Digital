#include "../Funcao/opcoes.h"

int editaArquivo(char *identificadorUsuario, char *campo, float novoValor) {
  const char *nomeArquivo = "informacoesUsu.txt";
  const char *nomeArquivoTemporario = "temp_informacoesUsu.txt";

  FILE *arquivoOriginal =
      fopen(nomeArquivo, "r"); // Abre o arquivo original para leitura
  FILE *arquivoTemporario = fopen(
      nomeArquivoTemporario, "w"); // Abre o arquivo temporário para escrita
  if (!arquivoOriginal || !arquivoTemporario) {
    printf("Erro ao manipular arquivos.\n");
    return 0; // erro
  }

  char linha[256];
  int usuarioEncontrado = 0; // Verificação se o usuario foi encontrado

  while (fgets(linha, sizeof(linha), arquivoOriginal)) {
    size_t comprimento = strlen(linha);
    // Remove o caractere de nova linha do final da linha, se existir
    if (comprimento > 0 && linha[comprimento - 1] == '\n') {
      linha[comprimento - 1] = '\0';
    }

    char usuarioNaLinha[256];
    sscanf(linha, "%[^,],",
           usuarioNaLinha); // Pega o identificador do usuário da linha

    if (strcmp(usuarioNaLinha, identificadorUsuario) == 0) {
      char cpf[15], senha[100], bitcoin[20], ethereum[20], ripple[20];
      float saldo;
      sscanf(linha, "%[^,],%[^,],%f,%[^,],%[^,],%s", cpf, senha, &saldo,
             bitcoin, ethereum, ripple); // Pega os valores da linha

      if (strcmp(campo, "saldo") == 0) {
        fprintf(arquivoTemporario, "%s,%s,%.2f,%s,%s,%s\n", cpf, senha,
                novoValor, bitcoin, ethereum, ripple);
      } else if (strcmp(campo, "bitcoin") == 0) {
        fprintf(arquivoTemporario, "%s,%s,%.2f,%.2f,%s,%s\n", cpf, senha, saldo,
                novoValor, ethereum, ripple);
      } else if (strcmp(campo, "ethereum") == 0) {
        fprintf(arquivoTemporario, "%s,%s,%.2f,%s,%.2f,%s\n", cpf, senha, saldo,
                bitcoin, novoValor, ripple);
      } else if (strcmp(campo, "ripple") == 0) {
        fprintf(arquivoTemporario, "%s,%s,%.2f,%s,%s,%.2f\n", cpf, senha, saldo,
                bitcoin, ethereum, novoValor);
      }

      usuarioEncontrado = 1;
    } else {
      fprintf(arquivoTemporario, "%s\n", linha);
    }
  }
  // Fecha os arquivos
  fclose(arquivoOriginal);
  fclose(arquivoTemporario);

  if (!usuarioEncontrado) {
    remove(nomeArquivoTemporario);
    printf("Usuario nao encontrado.\n");
    return 0; // Indica falha
  }

  remove(nomeArquivo);
  rename(nomeArquivoTemporario, nomeArquivo);

  return 1; // Indica sucesso
}