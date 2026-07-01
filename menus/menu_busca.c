#include <stdio.h>

#include "menu_busca.h"
#include "../utils/utilidades.h"

static void imprimirMenu(void)
{
    printf("\n========== BUSCA ==========\n");

    printf("1 - Buscar Pet\n");
    printf("2 - Buscar Veterinario\n");
    printf("3 - Buscar Produto\n");
    printf("4 - Voltar\n");
}

void MenuBusca(void)
{
    int opcao = 0;

    while(opcao != 4)
    {
        imprimirMenu();

        opcao = getOpcao();

        switch(opcao)
        {
            case 1:

                printf("\nBuscar Pet...\n");

                break;

            case 2:

                printf("\nBuscar Veterinario...\n");

                break;

            case 3:

                printf("\nBuscar Produto...\n");

                break;

            case 4:

                break;

            default:

                printf("\nOpcao invalida.\n");
        }
    }
}