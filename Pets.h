#ifndef PETS_H
#define PETS_H

#include <stdio.h>

typedef struct {

  char nome[50];
  int id;
  int idade;
  float peso;

} Pet;

Pet *BuscaPet(Pet *lista, Pet bicho);
void CadastraPet(Pet bicho, FILE *arq);
void RemovePet(Pet bicho, FILE *arq);

#endif
