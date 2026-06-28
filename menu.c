#include "menu.h"
#include <stdio.h>

int Menu() {

  int escolha = -1;

  printf("---CLINICA VETERINARIA---\n\n");

  printf("Opcoes(Digite o numero correspondente):\n\n1-Cadastro "
         "\n2-Atendimentos  \n3-Estoque "
         " \n0-Sair");

  while (escolha < 0 || escolha > 3) {
    scanf("%d", &escolha);
  }

  return escolha;
}
