#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int VerificaProduto(Produto *produto, FILE *arq) {
  Produto temp;

  rewind(arq);
  while (fread(&temp, sizeof(Produto), 1, arq) == 1) {
    if (temp.id == produto->id) {
      return 1;
    }
  }
  return 0;
}

int InsereProduto(Produto *produto, FILE *arq) {
  if (VerificaProduto(produto, arq)) {
    printf("Produto com ID %d ja existe!\n", produto->id);
    return 0;
  }

  fseek(arq, 0, SEEK_END);
  fwrite(produto, sizeof(Produto), 1, arq);
  fflush(arq);

  return 1;
}

/*

  Copia todos os registros, exceto o que sera removido,
   para um arquivo temporario; em seguida apaga o arquivo original e
   renomeia o temporario para o nome original.

   IMPORTANTE: como o arquivo original precisa ser fechado, apagado e
   recriado, o FILE* recebido em 'arq' fica invalido apos a chamada.
   O chamador deve reabrir o arquivo (fopen) logo depois de usar esta
   funcao, antes de fazer qualquer outra operacao com ele.

   Retorna 1 se removeu com sucesso, 0 caso o produto nao seja
   encontrado ou ocorra algum erro de arquivo. */

int RemoveProduto(Produto *produto, FILE *arq) {
  Produto atual;
  int encontrado = 0;

  if (!VerificaProduto(produto, arq)) {
    printf("Produto com ID %d nao encontrado!\n", produto->id);
    return 0;
  }

  FILE *temp = fopen(NOME_ARQUIVO_TEMP, "wb");
  if (temp == NULL) {
    perror("Erro ao criar arquivo temporario");
    return 0;
  }

  rewind(arq);
  while (fread(&atual, sizeof(Produto), 1, arq) == 1) {
    if (atual.id == produto->id) {
      encontrado = 1;
      continue;
    }
    fwrite(&atual, sizeof(Produto), 1, temp);
  }

  fclose(temp);
  fclose(arq);

  if (!encontrado) {
    remove(NOME_ARQUIVO_TEMP);
    return 0;
  }

  if (remove(NOME_ARQUIVO) != 0) {
    perror("Erro ao remover arquivo original");
    return 0;
  }

  if (rename(NOME_ARQUIVO_TEMP, NOME_ARQUIVO) != 0) {
    perror("Erro ao renomear arquivo temporario");
    return 0;
  }

  return 1;
}
