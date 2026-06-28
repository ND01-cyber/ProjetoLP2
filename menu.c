#include "menu.h"
#include <stdio.h>

int Menu() {

  int escolha = -1;

  printf("---CLINICA VETERINARIA---\n\n");

  printf("Opcoes(Digite o numero correspondente):\n\n1-Cadastro "
<<<<<<< HEAD
         "\n2-Atendimentos  \n3-Estoque "
         " \n0-Sair");
=======
         "\n2-Atendimentos \n3-Consultas \n4-Estoque"
         "\n0-Sair");
>>>>>>> 991e539 (Pets)

  while (escolha < 0 || escolha > 3) {
    scanf("%d", &escolha);
  }

  return escolha;
}
