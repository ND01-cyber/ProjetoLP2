#include <stdio.h>
#include "menus.h"
#include "utilidades.h"
#include "modulos.h"


void MenuPrincipal(void)
{
    int opcao;

    do
    {
        imprimirMenuPrincipal();

        opcao = getOpcao();

        switch (opcao)
        {
            case 1:
                MenuRealizarAtendimentos();
                break;

            case 2:
                // MenuRealizarCadastros();
                break;

            case 3:
                // MenuGerenciarEstoque();
                break;

            case 4:
                // MenuBusca();
                break;

            case 5:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != 5);
}


void MenuRealizarAtendimentos(void)
{
    imprimirMenuRealizarAtendimentos();

    int opcao = getOpcao();

    do {
        switch (opcao)
        {
            case 1:
                // Chamar função para realizar consulta
                break;

            case 2:
                // Chamar função para realizar venda
                break;

            default:
            // Caso de erro (opção inválida)
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 2);
}
