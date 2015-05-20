//
//  main.cpp
//  Young Tableau
//
//  Created by Diogo Martins on 5/20/15.
//  Copyright (c) 2015 Diogo Martins. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "young.h"

using namespace std;

int Menu(){
    int escolha;
    
    cout << "--------------------------\n";
    cout << "Selecione uma opcao:\n";
    cout << "1. Insere elemento (no. inteiro) no Quadro de Young.\n";
    cout << "2. Remove menor elemento do Quadro de Young.\n";
    cout << "3. Imprime elementos do Quadro de Young.\n";
    cout << "0. Fim.\n";
    cout << "Sua opcao: ";
    cin >> escolha;
    return escolha;
}

int main(int argc, const char * argv[]) {
    young young_table = young(4, 4);
    int item, escolha;
    bool fim = false;
    
    while ((!fim) && (escolha = Menu())){
        switch (escolha) {
            case 0:
                fim = true;
                break;
            case 1:
                cout << "Entre com elemento para inserir: ";
                cin >> item;
                if (young_table.insere(item))
                    cout << "Elemento inserido com sucesso\n";
                else
                    cout << "Erro ao inserir o elemento " << item << "\n";
                break;
            case 2:
                if (young_table.remove(item))
                    cout << "Elemento " << item << " removido\n";
                else
                    cout << "Erro ao remover elemento.\n";
                break;
            case 3:
                young_table.imprime();
                break;
            default:
                break;
        }
    }
    
    return 0;
}
