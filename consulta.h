#ifndef CONSULTA_H
#define CONSULTA_H
#include "funcionario.h"
#include "pets.h"

typedef struct {

  Pet animal;
  Funcionario veterinario;
  float valor;
  char data[11];
  int horario;

} Consulta;

typedef struct NoConsulta {

  Consulta dados;
  struct NoConsulta *proximo;

} NoConsulta;

typedef struct {

  NoConsulta *inicio;
  int tamanho;

} ListaConsulta;

Consulta *MarcarConsulta(Consulta *consulta);
int ReallizarConsulta(Consulta *consulta);
int RegistrarConsulta(Consulta consulta);
void InicializarLista(ListaConsulta *lista);
int VerificarConflito(ListaConsulta *lista, Consulta consulta);
int InserirConsulta(ListaConsulta *lista, Consulta consulta);
int RemoverConsulta(ListaConsulta *lista, int indice);
Consulta *BuscarConsulta(ListaConsulta *lista, int indice);
void LiberarLista(ListaConsulta *lista);

#endif
