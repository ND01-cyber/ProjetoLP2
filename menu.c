#include "menu.h"
#include <stdio.h>

int Menu() {

  int escolha = -1;

  printf("---CLINICA VETERINARIA---\n\n");

  printf("Opcoes(Digite o numero correspondente):\n\n1-Cadastro "
         "\n2-Agendamentos \n3-Consultas \n4-Vacinaçao \n5-Estoque "
         "\n6-Relaorios \n7-Configuraçoes \n0-Sair");

  while (escolha < 0 || escolha > 7) {
    scanf("%d", &escolha);
  }

  return escolha;
}
