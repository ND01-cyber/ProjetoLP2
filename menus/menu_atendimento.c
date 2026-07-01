#include <stdio.h>

#include "menu_atendimento.h"
#include "../utils/utilidades.h"

static void imprimirMenu(void)
{
    printf("\n========== ATENDIMENTO ==========\n");

    printf("1 - Consulta\n");
    printf("2 - Venda\n");
    printf("3 - Voltar\n");
}

void MenuAtendimento(void)
{
    int opcao = 0;

    while(opcao != 3)
    {
        imprimirMenu();

        opcao = getOpcao();

        switch(opcao)
        {
            case 1:

                printf("\nConsulta...\n");

                break;

            case 2:

                printf("\nVenda...\n");

                break;

            case 3:

                break;

            default:

                printf("\nOpcao invalida.\n");
        }
    }
}