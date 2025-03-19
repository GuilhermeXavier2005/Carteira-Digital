#include "../Funcao/opcoes.h"

//O objetivo principal desse arquivo é importar as informações do arquivo txt, cada usuario tem uma linha dedicada para suas informações

#define MaxLinha 100
#define MaxCampos 10

char** importarInfo(char* usuarioProcurado) {
    FILE *arquivoUsu = fopen("informacoesUsu.txt", "r");
    if (arquivoUsu == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    static char* informacoes[MaxCampos];  // Array estático para armazenar os dados do usuário
    char linha[MaxLinha];

    // Percorre cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivoUsu) != NULL) {
        char* tempLinha = strdup(linha); // Faz uma cópia da linha para não alterar a original
        char* nome = strtok(tempLinha, ",");

        // Se encontrou o usuário, armazena os valores e retorna
        if (nome != NULL && strcmp(nome, usuarioProcurado) == 0) {
            int i = 0;
            informacoes[i++] = strdup(nome);  //Duplica o Nome do usuário

            // Pega os demais valores da linha
            char* token;
            while ((token = strtok(NULL, ",")) != NULL && i < MaxCampos) {
                informacoes[i++] = strdup(token);
            }
            free(tempLinha);
            fclose(arquivoUsu);
            return informacoes;  // Retorna um array contendo as informações do usuário
        }
        free(tempLinha);
    }
    fflush(arquivoUsu);
    fclose(arquivoUsu);
    
    return NULL;  // Retorna NULL caso o usuário não seja encontrado
}