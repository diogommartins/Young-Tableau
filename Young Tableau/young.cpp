//
//  young.cpp
//  Young Tableau
//
//  Created by Diogo Martins on 5/20/15.
//  Copyright (c) 2015 Diogo Martins. All rights reserved.
//

#include "young.h"
#define INFINITO INT_MAX
/**
 1. O construtor cria um quadro vazio. Para tal, aloca espaço 
 para a matriz de inteiros Y, m × n e inicializa os valores com 
 a constante simbólica INT_MAX para representar ∞.
 */
young::young(int linhas, int colunas){
    m = linhas;
    n = colunas;
    
    Y = new int*[m];
    for (int i=0; i<m; i++)
        Y[i] = new int[n];
    
    for (int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            Y[i][j] = INFINITO;
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
            if (Y[i][j] != INFINITO)
                return false;       // Se achou pelo menos uma posição preenchida
    return true;                    // Não achou nenhuma posição preenchida
}

/**
4. Função bool cheio() retorna true se o quadro está cheio e false, caso contrário.
*/
bool young::cheio(){
    for (int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            if (Y[i][j] == INFINITO)
                return false;       // Se achou pelo menos uma posição vazia
    return true;                    // Não achou nenhuma posição vazia
}

bool tem_esquerda(int &coluna)
{
    return (coluna - 1 >= 0);
}

bool tem_direita(int &coluna, int &n)
{
    return (coluna + 1 <= n);
}

bool tem_topo(int &linha)
{
    return (linha - 1 >= 0);
}

bool tem_abaixo(int &linha, int &m)
{
    return (linha + 1 <= m);
}

void young::youngify(int i, int j){
    if (tem_topo(i) && (Y[i-1][j] > Y[i][j]))
    {
        int atual = Y[i][j];
        Y[i][j] = Y[i-1][j];
        Y[i-1][j] = atual;
        youngify(i-1, j);
    }
    if(tem_esquerda(j) && (Y[i][j-1] > Y[i][j]))
    {
        int atual = Y[i][j];
        Y[i][j] = Y[i][j-1];
        Y[i][j-1] = atual;
        youngify(i, j-1);
    }
}

void troca(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void youngfy_remove(int **Y, int i, int j, int &m, int &n)
{
    int menor_i = i;
    int menor_j = j;
    
    if (i+1 <= m && (Y[i][j] > Y[i+1][j]))
    {
        menor_i = i+1;
        menor_j = j;
    }
    if (j+1 <= n && (Y[menor_i][menor_j] > Y[i][j+1]))
    {
        menor_i = i;
        menor_j = j+1;
    }
    if ((menor_i != i) || (menor_j != j))
    {
        troca(Y[i][j], Y[menor_i][menor_j]);
        youngfy_remove(Y, menor_i, menor_j, m, n);
    }
}
/**
5. Função bool remove(int & elem) para extrair o menor elemento do quadro. Uma vez que o menor elemento está sempre na posição Y [1, 1] (no caso da linguagem C, Y [0, 0] ) a função pode retornar o elemento armazenado em Y [1, 1] e fazer Y [1, 1] = ∞ para indicar que o elemento não existe mais. Entretanto, tal fato pode deixar o quadro inconsistente. Isso acontece quando Y [1, 1] = ∞ e o quadro não está vazio.
*/
bool young::remove(int &elem){
    if (!vazio()){
        elem = Y[0][0];
        Y[0][0] = INFINITO;
        youngfy_remove(Y, 0, 0, m, n);
        return true;
    }
    return false;
}

/**
6. Função bool insere(int valor), para inserir um elemento no quadro. Se o quadro não estiver cheio, então Y [m, n] = ∞ (no caso da linguagem C, Y [m − 1, n − 1] ) e é possível colocar o novo elemento nesta posição. Entretanto, o quadro pode ficar inconsistente. Pode-se resolver este problema recursivamente retraindo o elemento novo e trocando-o com o elemento da esquerda ou do topo até conseguir um quadro de Young. A função retorna true se o elemento foi inserido com sucesso e false, caso contrário.
*/
bool young::insere(int valor){
    if (!cheio()){
        Y[m-1][n-1] = valor;
        youngify(m-1, n-1);
        return true;
    }
    return false;
}

string human_representation(int &valor){
    if (valor != INFINITO)
        return to_string(valor);
    return "∞";
}

void young::imprime(){
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout << human_representation(Y[i][j]) << "\t";
        cout << "\n";
    }
    cout << "\n";
}