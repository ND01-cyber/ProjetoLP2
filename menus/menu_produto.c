#include <stdio.h>

#include "menu_produto.h"
#include "../utils/utilidades.h"

static void imprimirMenuProduto(void)
{
    printf("\n========================================\n");
    printf("          MENU PRODUTO\n");
    printf("========================================\n");

    printf("1 - Cadastrar Produto\n");
    printf("2 - Remover Produto\n");
    printf("3 - Atualizar Produto\n");
    printf("4 - Voltar\n");
}

static void cadastrarProduto(void)
{
    printf("\n[Cadastrar Produto]\n");
}

static void removerProduto(void)
{
    printf("\n[Remover Produto]\n");
}

static void atualizarProduto(void)
{
    printf("\n[Atualizar Produto]\n");
}

void MenuProduto(void)
{
    int opcao = 0;

    while(opcao != 4)
    {
        imprimirMenuProduto();

        opcao = getOpcao();

        switch(opcao)
        {
            case 1:
                cadastrarProduto();
                break;

            case 2:
                removerProduto();
                break;

            case 3:
                atualizarProduto();
                break;

            case 4:
                break;

            default:
                printf("\nOpcao invalida.\n");
        }
    }
}