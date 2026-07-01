#include "menu.h"
#include <stdio.h>

void Menu_Principal(int *escolha_principal) {

  int escolha = -1;

  printf("==============================\n");
  printf("  ---CLINICA VETERINARIA---\n");
  printf("==============================\n\n");

  printf("Opcoes(Digite o numero correspondente):\n");
  printf("1-Atendimentos\n");
  printf("2-Cadstro\n");
  printf("3-Busca\n");
  printf("4-Sair\n");

  while (escolha < 0 || escolha > 3) {
    scanf("%d", &escolha);
  }

  *escolha_principal = escolha;
}

void Menu_Atendimento(int *escolha_secundaria) {

  int escolha2 = -1;

  printf("======================\n");
  printf("  ---ATENDIMENTO---\n");
  printf("======================\n\n");

  printf("Opcoes de Atendimento:\n");
  printf("1-Consulta\n");
  printf("2-Venda\n");
  printf("3-Voltar\n");

  while (escolha2 < 1 || escolha2 > 3) {
    scanf("%d", &escolha2);
  }

  *escolha_secundaria = escolha2;
}

void Menu_Cadastro(int *escolha_secundaria) {

  int escolha2 = -1;

  printf("======================\n");
  printf("  ---CADASTROS---\n");
  printf("======================\n\n");

  printf("Opcoes de Cadastro:\n");
  printf("1-Pets\n");
  printf("2-Veterinarios\n");
  printf("3-Produtos\n");
  printf("4-Voltar\n");

  while (escolha2 < 1 || escolha2 > 3) {

    scanf("%d", &escolha2);
  }

  *escolha_secundaria = escolha2;
}
