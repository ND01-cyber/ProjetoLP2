#include <stdio.h>

#include "menu_pet.h"
#include "../utils/utilidades.h"

static void imprimirMenuPet(void)
{
    printf("\n========================================\n");
    printf("            MENU PET\n");
    printf("========================================\n");

    printf("1 - Cadastrar Pet\n");
    printf("2 - Remover Pet\n");
    printf("3 - Atualizar Pet\n");
    printf("4 - Voltar\n");
}

static void cadastrarPet(void)
{
    printf("\n[Cadastrar Pet]\n");
}

static void removerPet(void)
{
    printf("\n[Remover Pet]\n");
}

static void atualizarPet(void)
{
    printf("\n[Atualizar Pet]\n");
}

void MenuPet(void)
{
    int opcao = 0;

    while(opcao != 4)
    {
        imprimirMenuPet();

        opcao = getOpcao();

        switch(opcao)
        {
            case 1:
                cadastrarPet();
                break;

            case 2:
                removerPet();
                break;

            case 3:
                atualizarPet();
                break;

            case 4:
                break;

            default:
                printf("\nOpcao invalida.\n");
        }
    }
}