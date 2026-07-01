#include "vendas.h"
#include "produtos.h"

#define ARQUIVO_VENDAS "vendas.txt"

int RealizarVenda(Produto produto) {

  int res;

  FILE *arq = fopen(NOME_ARQUIVO, "rb");

  if (arq) {

    res = VerificaProduto(&produto, arq);

    if (res == 1) {
      printf("Produto encontrado!");

      RemoveProduto(&produto, arq);

      printf("Venda Realizada!\n");
      printf("Valor: %f\n", produto.preco);

      RegistraVenda(produto);

      return 1;
    }
    printf("produto nao encontrado\n");
  }
  printf("Nao foi possivel abrir arquivo de produtos\n");
  return 0;
}

void RegistrarVenda(Produto produto) {

  FILE *arq = fopen(ARQUIVO_VENDAS, "w");

  fprintf(arq, " %s : %fR$", produto.nome, produto.preco)
}
