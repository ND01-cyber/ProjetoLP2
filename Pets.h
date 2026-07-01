#ifndef PETS_H
#define PETS_H

#include <stdio.h>

typedef enum {

  BOA,
  ESTAVEL,
  GRAVE,
  CRITICA,

} Situacao;

typedef struct {

  char nome[50];
  int id;
  int idade;
  float peso;
  Situacao estado;
  int id_Cliente;

} Pet;

Pet *BuscaPet(Pet *lista, Pet bicho);
void CadastraPet(Pet bicho, FILE *arq);
void RemovePet(Pet bicho, FILE *arq);
void AtualizaPet(Pet *bicho);

#endif
