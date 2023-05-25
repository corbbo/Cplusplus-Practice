// Exercicio 8, Lista 2
// Thiago Zilberknop
// Ultima Atualizacao: 3/24/23
// --- FINALIDADE ---
// Esse programa recebe do usuario uma serie de numeros e informa quais deles sao primos e as posicoes na sequencia dos mesmos

#include <iostream>

using namespace std;

int primacy(int n) {
  if (n == 0 || n == 1) return 0;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int num;
  for (int i = 0; i < 9; i++) {
    cin >> num;
    if (primacy(num)) cout << num << " " << i << endl;
  }
}