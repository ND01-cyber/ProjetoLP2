#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {

  char *id;
  float preco;

} Produto;

int VerificaProduto(Produto produto, FILE *arq);
void InserirProduto(Produto produto, FILE *arq);
void RemoverProduto(Produto produto, FILE *arq);

#endif
