#include <stdio.h>

#include "menu_veterinario.h"
#include "../utils/utilidades.h"

static void imprimirMenuVeterinario(void)
{
    printf("\n========================================\n");
    printf("        MENU VETERINARIO\n");
    printf("========================================\n");

    printf("1 - Cadastrar Veterinario\n");
    printf("2 - Remover Veterinario\n");
    printf("3 - Atualizar Veterinario\n");
    printf("4 - Voltar\n");
}

static void cadastrarVeterinario(void)
{
    printf("\n[Cadastrar Veterinario]\n");
}

static void removerVeterinario(void)
{
    printf("\n[Remover Veterinario]\n");
}

static void atualizarVeterinario(void)
{
    printf("\n[Atualizar Veterinario]\n");
}

void MenuVeterinario(void)
{
    int opcao = 0;

    while(opcao != 4)
    {
        imprimirMenuVeterinario();

        opcao = getOpcao();

        switch(opcao)
        {
            case 1:
                cadastrarVeterinario();
                break;

            case 2:
                removerVeterinario();
                break;

            case 3:
                atualizarVeterinario();
                break;

            case 4:
                break;

            default:
                printf("\nOpcao invalida.\n");
        }
    }
}