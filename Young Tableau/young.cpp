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

/**
2. O destrutor libera a memória alocada para a matriz Y .
*/
young::~young(){
    delete Y;
}

/**
 3. Função bool vazio() retorna true se o quadro está vazio e false,
 caso contrário.
*/
bool young::vazio(){
    for (int i=0; i<=m; i++)
        for(int j=0; i<=n; i++)
            if (Y[i][j] != INT_MAX)
                return false;       // Se achou pelo menos uma posição preenchida
    return true;                    // Não achou nenhuma posição preenchida
}

/**
4. Função bool cheio() retorna true se o quadro está cheio e false, caso contrário.
*/
bool young::cheio(){
    for (int i=0; i<=m; i++)
        for(int j=0; i<=n; i++)
            if (Y[i][j] == INT_MAX)
                return false;       // Se achou pelo menos uma posição vazia
    return true;                    // Não achou nenhuma posição vazia
}

/**
5. Função bool remove(int & elem) para extrair o menor elemento do quadro. Uma vez que o menor elemento está sempre na posição Y [1, 1] (no caso da linguagem C, Y [0, 0] ) a função pode retornar o elemento armazenado em Y [1, 1] e fazer Y [1, 1] = ∞ para indicar que o elemento não existe mais. Entretanto, tal fato pode deixar o quadro inconsistente. Isso acontece quando Y [1, 1] = ∞ e o quadro não está vazio.
*/
bool young::remove(int &elem){
    return false;
}

/**
6. Função bool insere(int valor), para inserir um elemento no quadro. Se o quadro não estiver cheio, então Y [m, n] = ∞ (no caso da linguagem C, Y [m − 1, n − 1] ) e é possível colocar o novo elemento nesta posição. Entretanto, o quadro pode ficar inconsistente. Pode-se resolver este problema recursivamente retraindo o elemento novo e trocando-o com o elemento da esquerda ou do topo até conseguir um quadro de Young. A função retorna true se o elemento foi inserido com sucesso e false, caso contrário.
*/
bool young::insere(int valor){
    return false;
}