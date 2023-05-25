// Exercicio 1, Lista 5
// Thiago Zilberknop
// Ultima Atualizacao: 3/20/23
// --- FINALIDADE ---
// Esse programa determina uma classe Hora que tem sobrecarga de operadores e realiza operações com objetos da classe (soma uma hora a outra, >> uma hora, << outra hora)

#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;
class Hora {
private:
  int hora, minuto, segundo;

public:
  Hora();
  Hora(int h, int m, int s);
  ~Hora();
  int obtemHora() const;
  int obtemMinuto() const;
  int obtemSegundo() const;
  void defineHora(int h);
  void defineMinuto(int m);
  void defineSegundo(int s);
  string str() const;
  Hora operator+(const Hora &hr);
  friend ostream &operator<<(ostream &out, const Hora &h);
  friend istream &operator>>(istream &in, Hora &h);
};
// Coloque a sua implementacao a partir deste ponto

int debug = 0;

Hora::Hora() {
  if (debug == 1) cout << "Objeto Hora criado." << endl;
}
Hora::Hora(int h, int m, int s) {
  hora = h;
  minuto = m;
  segundo = s;
}
Hora::~Hora() {
  if (debug == 1) cout << "Objeto Hora deletado." << endl;
}
int Hora::obtemHora() const {return hora;}
int Hora::obtemMinuto() const {return minuto;}
int Hora::obtemSegundo() const {return segundo;}
void Hora::defineHora(int h) {hora = h;}
void Hora::defineMinuto(int m) {minuto = m;}
void Hora::defineSegundo(int s) {segundo = s;}
string Hora::str() const {
  stringstream ss;
  if (hora < 10) ss << "0" << hora;
  else ss << hora;
  ss << ":";
  if (minuto < 10) ss << "0" << minuto;
  else ss << minuto;
  ss << ":";
  if (segundo < 10) ss << "0" << segundo;
  else ss << segundo;
  return ss.str();
}
Hora Hora::operator+(const Hora &hr) {
  int s = segundo + hr.segundo;
  int m = minuto + hr.minuto + s/60;
  int h = hora + hr.hora + m/60;
  s %= 60;
  m %= 60;
  h %= 24;
  return Hora(h, m, s);
}
ostream &operator<<(ostream &out, const Hora &h) {
  return out << h.str();
}
istream &operator>>(istream &in, Hora &h) {
  char ponto;
  in >> h.hora >> ponto >> h.minuto >> ponto >> h.segundo;
  return in;
}

int main() {
  Hora h1, h2;
  cin >> h1;
  cin >> h2;
  Hora h3 = h1 + h2;
  cout << h3 << endl;
  return 0;
}