#include "Pets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IniciaPet(Pet bicho) {

  printf("Id do tutor: \n"), scanf("%d", &bicho.id_Cliente);

  printf("Nome do Pet: \n");
  scanf("%s", bicho.nome);

  printf("Peso do Pet: \n");
  scanf("%f", &bicho.peso);
}

Pet *BuscaPet(Pet *lista, Pet bicho) {
  int i;

  if (lista == NULL) {
    return NULL;
  }

  for (i = 0; lista[i].nome[0] != '\0'; i++) {
    if (lista[i].id == bicho.id) {
      return &lista[i];
    }
  }

  return NULL; /* nao encontrado */
}

void CadastraPet(Pet *bicho, FILE *arq) {
  if (arq == NULL) {
    printf("Erro: arquivo invalido.\n");
    return;
  }

  fseek(arq, 0, SEEK_END);
  if (fwrite(&bicho, sizeof(Pet), 1, arq) != 1) {
    printf("Erro ao cadastrar o pet '%s'.\n", bicho->nome);
    return;
  }

  fflush(arq);
  printf("Pet '%s' (id %d) cadastrado com sucesso!\n", bicho->nome, bicho->id);
}

void RemovePet(Pet bicho, FILE *arq) {
  FILE *temp;
  Pet aux;
  int removido = 0;

  if (arq == NULL) {
    printf("Erro: arquivo invalido.\n");
    return;
  }

  temp = fopen("pets_temp.dat", "wb");
  if (temp == NULL) {
    printf("Erro ao criar arquivo temporario.\n");
    return;
  }

  rewind(arq);
  while (fread(&aux, sizeof(Pet), 1, arq) == 1) {
    if (aux.id == bicho.id && !removido) {
      removido = 1;
      continue; /* pula o pet a ser removido */
    }
    fwrite(&aux, sizeof(Pet), 1, temp);
    fclose(temp);

    if (!removido) {
      printf("Pet com id %d nao encontrado.\n", bicho.id);
      remove("pets_temp.dat");
      return;
    }

    fclose(arq);

    if (remove(NOME_ARQUIVO_PETS) != 0) {
      printf("Erro ao remover arquivo original.\n");
      return;
    }

    if (rename("pets_temp.dat", "pets.dat") != 0) {
      printf("Erro ao renomear arquivo temporario.\n");
      return;
    }

    printf("Pet '%s' (id %d) removido com sucesso!\n", bicho.nome, bicho.id);
  }

  void AtualizaPet(Pet * bicho) {
    int opcao;

    if (bicho == NULL) {
      printf("Erro: pet invalido.\n");
      return;
    }

    printf("\nAtualizando dados de '%s' (id %d):\n", bicho->nome, bicho->id);
    printf("1 - Nome\n");
    printf("2 - Idade\n");
    printf("3 - Peso\n");
    printf("4 - Estado (BOA, ESTAVEL, GRAVE, CRITICA)\n");
    printf("5 - ID do cliente\n");
    printf("0 - Cancelar\n");
    printf("Escolha o campo a atualizar: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Novo nome: ");
      scanf(" %49[^\n]", bicho->nome);
      break;

    case 2:
      printf("Nova idade: ");
      scanf("%d", &bicho->idade);
      break;

    case 3:
      printf("Novo peso: ");
      scanf("%f", &bicho->peso);
      break;

    case 4:
      int est;
      printf("Novo estado (0-BOA, 1-ESTAVEL, 2-GRAVE, 3-CRITICA): ");
      scanf("%d", &est);
      if (est >= BOA && est <= CRITICA) {
        bicho->estado = (Situacao)est;
      } else {
        printf("Valor invalido, estado nao alterado.\n");
      }
      break;

    case 5:
      printf("Novo ID do cliente: ");
      scanf("%d", &bicho->id_Cliente);
      break;

    case 0:
      printf("Atualizacao cancelada.\n");
      return;

    default:
      printf("Opcao invalida.\n");
      return;
    }

    printf("Pet '%s' atualizado com sucesso!\n", bicho->nome);
  }
