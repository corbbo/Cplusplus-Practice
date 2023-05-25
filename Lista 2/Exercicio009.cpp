// Exercicio 9, Lista 2
// Thiago Zilberknop
// Ultima Atualizacao: 3/24/23
// --- FINALIDADE ---
// Esse programa recebe do usuario uma matriz de numeros e retorna a mesma com cada linha multiplicada pelo maior numero daquela linha

#include <iostream>

using namespace std;

int main() {
  int mat[6][4];
  for (int i = 0; i < 6; i++) {
    int bignum = 0;
    for (int j = 0; j < 4; j++) {
      cin >> mat[i][j];
      int curnum = mat[i][j];
      if (curnum > bignum) bignum = curnum;
      if (j == 3) for (int k = 0; k < 4; k++) mat[i][k] *= bignum;
    }
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}