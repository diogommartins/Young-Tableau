//
//  young.cpp
//  Young Tableau
//
//  Created by Diogo Martins on 5/20/15.
//  Copyright (c) 2015 Diogo Martins. All rights reserved.
//

#include "young.h"

/**
 1. O construtor cria um quadro vazio. Para tal, aloca espaço 
 para a matriz de inteiros Y, m × n e inicializa os valores com 
 a constante simb ́olica INT_MAX para representar ∞.
 */
young::young(int linhas, int colunas){
    m = linhas;
    n = colunas;
    
    for (int i=0; i<=m; i++)
        for(int j=0; i<=n; i++)
            Y[i][j] = INT_MAX;
}

