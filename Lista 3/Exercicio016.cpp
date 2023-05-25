// Exercicio 15, Lista 3
// Thiago Zilberknop
// Ultima Atualizacao: 3/24/23
// --- FINALIDADE ---
// Esse programa determina uma classe Elevador e completa diversas operações sobre um objeto da classe

#include <iostream>
#include <string>

using namespace std;

class Elevador {
private:
  int curFloor, totalFloor, maxOcu, curOcu;

public:
  Elevador() {
    curFloor = 0;
    totalFloor = 0;
    maxOcu = 0;
    curOcu = 0;
  }
  void newElevetor(int max, int floors) {
    curFloor = 0;
    totalFloor = floors;
    maxOcu = max;
    curOcu = 0;
  }
  // actions
  void entra() {
    if (curOcu < maxOcu)
      curOcu++;
  }
  void sai() {
    if (curOcu > 0)
      curOcu--;
  }
  void sobe() {
    if (curFloor < totalFloor)
      curFloor++;
  }
  void desce() {
    if (curFloor > 0)
      curFloor--;
  }
  // gets
  int obtemAndarAtual() { return curFloor; }
  int obtemTotalAndares() { return totalFloor; }
  int obtemCapacidade() { return maxOcu; }
  int obtemNumPessoas() { return curOcu; }
  // sets
  void defineTotalAndares(int n) { totalFloor = n; }
  void defineCapacidade(int n) { maxOcu = n; }
  // misc
  void movimenta(string str) {
    for (int i = 0; str[i] != '\0'; i++) {
      switch (str[i]) {
      case '^':
        sobe();
        break;
      case 'v':
        desce();
        break;
      case '+':
        entra();
        break;
      case '-':
        sai();
        break;
      }
    }
  }
};

int main() {
  Elevador *e;
  int capacidade, totalAndares;
  string operacao;
  // LEITURA
  cin >> capacidade;
  cin >> totalAndares;
  cin >> operacao;
  // TESTE DE FUNCIONAMENTO
  e = new Elevador();
  if (e->obtemAndarAtual() != 0 || e->obtemCapacidade() != 0 ||
      e->obtemNumPessoas() != 0 || e->obtemTotalAndares() != 0)
    return 1;
  e->defineCapacidade(capacidade);
  if (e->obtemAndarAtual() != 0 || e->obtemTotalAndares() != 0 ||
      e->obtemNumPessoas() != 0 || e->obtemCapacidade() != capacidade)
    return 1;
  e->defineTotalAndares(totalAndares);
  if (e->obtemAndarAtual() != 0 || e->obtemTotalAndares() != totalAndares ||
      e->obtemNumPessoas() != 0 || e->obtemCapacidade() != capacidade)
    return 1;
  for (int i = 0; i <= totalAndares + 2; ++i) {
    e->sobe();
    if (e->obtemAndarAtual() > totalAndares)
      return 1;
  }
  for (int i = 0; i <= totalAndares + 2; ++i) {
    e->desce();
    if (e->obtemAndarAtual() < 0)
      return 1;
  }
  for (int i = 0; i <= capacidade + 2; ++i) {
    e->entra();
    if (e->obtemNumPessoas() > capacidade)
      return 1;
  }
  for (int i = 0; i <= capacidade + 2; ++i) {
    e->sai();
    if (e->obtemNumPessoas() < 0)
      return 1;
  }
  // OPERACAO
  e->movimenta(operacao);
  // SAIDA
  cout << e->obtemNumPessoas() << " " << e->obtemAndarAtual() << endl;
  delete e;
  return 0;
}