#include "funcionario.h"
#include <stdio.h>
#include <string.h>

void CadastroFunc(FILE *arq) {
  Funcionario func;
  int i;

  if (arq == NULL) {
    printf("Erro: arquivo invalido.\n");
    return;
  }

  printf("=== Cadastro de Funcionario ===\n");

  printf("ID: ");
  scanf("%d", &func.id);
  getchar();

  printf("Nome: ");
  fgets(func.nome, sizeof(func.nome), stdin);
  func.nome[strcspn(func.nome, "\n")] = '\0';

  printf("Ocupacao (codigo): ");
  scanf("%d", &func.ocupacao);

  fseek(arq, 0, SEEK_END);
  fwrite(&func, sizeof(Funcionario), 1, arq);
  fflush(arq);

  printf("Funcionario '%s' (id %d) cadastrado com sucesso!\n", func.nome,
         func.id);
}

void RemoveFunc(Funcionario *func, FILE *arq) {
  FILE *temp;
  Funcionario aux;
  int removido = 0;

  if (arq == NULL || func == NULL) {
    printf("Erro: arquivo ou funcionario invalido.\n");
    return;
  }

  temp = fopen("funcs_temp.dat", "wb");
  if (temp == NULL) {
    printf("Erro ao criar arquivo temporario.\n");
    return;
  }

  rewind(arq);

  while (fread(&aux, sizeof(Funcionario), 1, arq) == 1) {
    if (aux.id == func->id && !removido) {
      removido = 1;
      continue; /* pula o funcionario a ser removido */
    }
    fwrite(&aux, sizeof(Funcionario), 1, temp);
  }

  fclose(temp);

  if (!removido) {
    printf("Funcionario com id %d nao encontrado.\n", func->id);
    remove("funcs_temp.dat");
    return;
  }

  fclose(arq);

  if (remove(NOME_ARQUIVO_FUNC) != 0) {
    printf("Erro ao remover arquivo original.\n");
    return;
  }

  if (rename("funcs_temp.dat", NOME_ARQUIVO_FUNC) != 0) {
    printf("Erro ao renomear arquivo temporario.\n");
    return;
  }

  printf("Funcionario '%s' (id %d) removido com sucesso!\n", func->nome,
         func->id);

  /* IMPORTANTE: 'arq' foi fechado dentro desta funcao.
   * usar (fopen(NOME_ARQUIVO_FUNC, "rb+")) para acessa-lo de
   * novo no restante do programa. */
}

int AlteraFunc(int id, const char *novoNome, int novaOcupacao,
               int *novosHorarios, FILE *arq) {

  Funcionario aux;
  long pos;
  int encontrado = 0;

  if (arq == NULL) {
    printf("Erro: arquivo invalido.\n");
    return 0;
  }

  rewind(arq);
  while (fread(&aux, sizeof(Funcionario), 1, arq) == 1) {
    if (aux.id == id) {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Funcionario com id %d nao encontrado.\n", id);
    return 0;
  }

  /* Atualiza somente os campos informados. */
  if (novoNome != NULL) {
    strncpy(aux.nome, novoNome, sizeof(aux.nome) - 1);
    aux.nome[sizeof(aux.nome) - 1] = '\0';
  }

  if (novaOcupacao != -1) {
    aux.ocupacao = novaOcupacao;
  }

  if (novosHorarios != NULL) {
    int i;
    for (i = 0; i < 5; i++) {
      aux.horarios[i] = novosHorarios[i];
    }
  }

  /* O fread acima avancou o cursor um registro para frente.
   * Volta exatamente um sizeof(Funcionario) para sobrescrever
   * o registro encontrado. */

  pos = ftell(arq) - (long)sizeof(Funcionario);
  if (pos < 0) {
    printf("Erro ao calcular posicao no arquivo.\n");
    return 0;
  }
  fseek(arq, pos, SEEK_SET);

  fwrite(&aux, sizeof(Funcionario), 1, arq);
  fflush(arq);

  printf("Funcionario '%s' (id %d) alterado com sucesso!\n", aux.nome, aux.id);
  return 1;
}
