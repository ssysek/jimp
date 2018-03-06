//
// Created by syskmaci on 06.03.18.
//

#include <iostream>
#include "Array2D.h"

void ShowTab(int n_rows, int n_columns, int *const *tab);

int **Array2D(int n_rows, int n_columns){
    int **tab = new int *[n_rows];
    int licznik = 1;
    for(int i =0; i<n_rows;i++)
    {
        tab[i] = new int [n_columns];
        for ( int j = 0; j<n_columns;++j){
            tab[i][j]=licznik;
            licznik+=1;}
    }
    ShowTab(n_rows, n_columns, tab);

}

void DeleteArray2D(int **array, int n_rows, int n_columns) {

}

void ShowTab(int n_rows, int n_columns, int *const *tab) {
    for(int i =0; i < n_columns; i++){
        for (int j = 0; j <n_rows ; ++j) {
            std::cout << tab[i][j] << std::endl;
        }
    }
}