// Exercicio 15, Lista 3
// Thiago Zilberknop
// Ultima Atualizacao: 3/24/23
// --- FINALIDADE ---
// Esse programa determina uma classe Pessoa e completa varias operaçoes com objetos dessa classe

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Pessoa {
private:
  string nome;
  int idade;
  float altura, cresce;

public:
  Pessoa() {
    nome = "";
    idade = 0;
    altura = 0;
    cresce = 0;
  }
  void newPeep(string n, int a, float h, float c) {
    nome = n;
    idade = a;
    altura = h;
    cresce = c;
  }
  string obtemNome() { return nome; }
  int obtemIdade() { return idade; }
  float obtemAltura() { return altura; }
  float obtemTaxaCrescimento() { return cresce; }
  void defineNome(string n) { nome = n; }
  void defineIdade(int a) { idade = a; }
  void defineAltura(float h) { altura = h; }
  void defineTaxaCrescimento(float c) { cresce = c; }
  void envelhece() {
    idade++;
    altura += cresce;
  }
};

void le_pessoa(Pessoa *p) {
  string s;
  getline(cin, s);
  p->defineNome(s);
  getline(cin, s);
  p->defineIdade(stoi(s));
  getline(cin, s);
  p->defineAltura(stod(s));
  getline(cin, s);
  p->defineTaxaCrescimento(stod(s));
}
void imprime_pessoa(Pessoa *p) {
  cout << p->obtemNome() << " (";
  cout << p->obtemIdade() << " anos; ";
  cout << fixed << setprecision(4);
  cout << p->obtemAltura() << " cm; ";
  cout << p->obtemTaxaCrescimento() << " cm)" << endl;
}
int main() {
  Pessoa *p1, *p2;
  // LEITURA
  p1 = new Pessoa();
  le_pessoa(p1);
  p2 = new Pessoa();
  le_pessoa(p2);
  // ENVELHECIMENTO
  for (int i = 0; i < 5; ++i) {
    p1->envelhece();
    p2->envelhece();
  }
  // RESULTADOS
  if (p1->obtemAltura() > p2->obtemAltura())
    imprime_pessoa(p1);
  else if (p1->obtemAltura() < p2->obtemAltura())
    imprime_pessoa(p2);
  else {
    imprime_pessoa(p1);
    imprime_pessoa(p2);
  }
  delete p2;
  delete p1;
  return 0;
}