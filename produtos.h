#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NOME_ARQUIVO "produtos.dat"
#define NOME_ARQUIVO_TEMP "produtos_temp.dat"

typedef struct {

  int id;
  float preco;
  int quantidade;

} Produto;

int VerificaProduto(Produto *produto, FILE *arq);
int InsereProduto(Produto *produto, FILE *arq);
int RemoveProduto(Produto *produto, FILE *arq);

#endif
