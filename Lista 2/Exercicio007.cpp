// Exercicio 7, Lista 2
// Thiago Zilberknop
// Ultima Atualizacao: 3/24/23
// --- FINALIDADE ---
// Esse programa recebe do usuario dados sobre dez pessoas e lhe retorna dados novos

#include <iostream>
#include <iomanip>

using namespace std;

struct pessoa {
  short int idade;
  float peso, altura;
};

int main() {
  struct pessoa pessoas[10];
  float idademedia = 0;
  int gordinhos = 0;
  float altoejovem = 0;
  float alto = 0;
  float percento;
  for (int i = 0; i < 10; i++) {
    cin >> pessoas[i].idade >> pessoas[i].peso >> pessoas[i].altura;
    cout << endl;
    idademedia += pessoas[i].idade * 0.1;
    if (pessoas[i].peso > 90 && pessoas[i].altura < 1.5) gordinhos++;
    if (pessoas[i].altura > 1.9) {
      alto++;
      if (pessoas[i].idade >= 10 && pessoas[i].idade <= 30) altoejovem++;
    }
  percento = (altoejovem/alto) * 100;
  }
  cout << fixed << setprecision(4) << idademedia << " " << gordinhos << " " << percento << endl;
}