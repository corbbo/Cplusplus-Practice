// Exercicio 3, Lista 7
// Thiago Zilberknop
// Ultima Atualizacao: 5/23/23
// --- FINALIDADE ---
// Esse programa utiliza heranca para fazer uma classe equipe baseada numa classe clube e depois manipula objetos das classes

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Clube {
protected:
  string abrev, shortName, longName, city, state;

public:
  Clube(string a, string b, string c, string d, string e) {
    abrev = a;
    shortName = b;
    longName = c;
    city = d;
    state = e;
  }
  Clube() { abrev = shortName = longName = city = state = ""; }

  string obtemAbreviatura() { return abrev; }
  string obtemNome() { return shortName; }
  string obtemNomeCompleto() { return longName; }
  string obtemCidade() { return city; }
  string obtemEstado() { return state; }

  void defineAbreviatura(string a) { abrev = a; }
  void defineNome(string a) { shortName = a; }
  void defineNomeCompleto(string a) { longName = a; }
  void defineCidade(string a) { city = a; }
  void defineEstado(string a) { state = a; }
};

class Equipe : public Clube {
private:
  int points, games, wins, draws, losses, goals, evilGoals;

public:
  Equipe(string a = "", string b = "", string c = "", string d = "", string e = "", int um = 0, int dois = 0, int tres = 0, int quatro = 0, int cinco = 0, int seis = 0, int sete = 0)
      : Clube(a, b, c, d, e) {
    points = um;
    games = dois;
    wins = tres;
    draws = quatro;
    losses = cinco;
    goals = seis;
    evilGoals = sete;
  }
  int obtemPontos() { return points; }
  int obtemJogos() { return games; }
  int obtemVitorias() { return wins; }
  int obtemEmpates() { return draws; }
  int obtemDerrotas() { return losses; }
  int obtemGolsFeitos() { return goals; }
  int obtemGolsTomados() { return evilGoals; }
  void registraJogo(int gols, int golstomado) {
    games++;
    if (gols > golstomado) {
      points += 3;
      wins++;
    } else if (gols < golstomado) {
      losses++;
    } else {
      draws++;
      points++;
    }
    goals += gols;
    evilGoals += golstomado;
  }
};

void imprimeClube(Clube *c) {
  cout << "Abreviatura: " << c->obtemAbreviatura() << endl;
  cout << "Nome: " << c->obtemNome() << endl;
  cout << "Nome completo: " << c->obtemNomeCompleto() << endl;
  cout << "Cidade: " << c->obtemCidade() << endl;
  cout << "Estado: " << c->obtemEstado() << endl;
  cout << "----------" << endl;
}
void imprimeEquipe(Equipe *e) {
  cout << "Abreviatura: " << e->obtemAbreviatura() << endl;
  cout << "Nome: " << e->obtemNome() << endl;
  cout << "Nome completo: " << e->obtemNomeCompleto() << endl;
  cout << "Cidade: " << e->obtemCidade() << endl;
  cout << "Estado: " << e->obtemEstado() << endl;
  cout << "Pontos: " << e->obtemPontos() << endl;
  cout << "Jogos: " << e->obtemJogos() << endl;
  cout << "Vitorias: " << e->obtemVitorias() << endl;
  cout << "Empates: " << e->obtemEmpates() << endl;
  cout << "Derrotas: " << e->obtemDerrotas() << endl;
  cout << "Gols Feitos: " << e->obtemGolsFeitos() << endl;
  cout << "Gols Tomados: " << e->obtemGolsTomados() << endl;
  cout << "----------" << endl;
}
int main() {
  Clube bah("BAH", "Bahia", "Esporte Clube Bahia", "Salvador", "BA");
  imprimeClube(&bah);
  Clube fla;
  imprimeClube(&fla);
  fla.defineAbreviatura("FLA");
  fla.defineNome("Flamengo");
  fla.defineNomeCompleto("Clube de Regatas do Flamengo");
  fla.defineCidade("Rio de Janeiro");
  fla.defineEstado("RJ");
  imprimeClube(&fla);
  Equipe flu("FLU", "Fluminense", "Fluminense Football Club", "Rio de Janeiro", "RJ");
  flu.registraJogo(0, 0);
  flu.registraJogo(1, 0);
  flu.registraJogo(2, 2);
  flu.registraJogo(1, 0);
  flu.registraJogo(1, 1);
  flu.registraJogo(0, 1);
  flu.registraJogo(1, 1);
  flu.registraJogo(1, 4);
  flu.registraJogo(1, 0);
  flu.registraJogo(0, 0);
  flu.registraJogo(2, 1);
  flu.registraJogo(0, 1);
  flu.registraJogo(0, 1);
  flu.registraJogo(0, 1);
  flu.registraJogo(2, 4);
  flu.registraJogo(1, 1);
  flu.registraJogo(2, 0);
  flu.registraJogo(1, 1);
  flu.registraJogo(2, 1);
  flu.registraJogo(2, 1);
  flu.registraJogo(2, 2);
  flu.registraJogo(2, 1);
  flu.registraJogo(0, 2);
  flu.registraJogo(0, 0);
  imprimeEquipe(&flu);
  Equipe cap;
  imprimeEquipe(&cap);
  cap.defineAbreviatura("CAP");
  cap.defineNome("Athletico-PR");
  cap.defineNomeCompleto("Club Athletico Paranaense");
  cap.defineCidade("Curitiba");
  cap.defineEstado("PR");
  cap.registraJogo(1, 0);
  cap.registraJogo(3, 0);
  cap.registraJogo(1, 0);
  cap.registraJogo(2, 1);
  cap.registraJogo(1, 2);
  cap.registraJogo(2, 2);
  cap.registraJogo(4, 1);
  cap.registraJogo(2, 1);
  cap.registraJogo(1, 2);
  cap.registraJogo(2, 2);
  cap.registraJogo(0, 1);
  cap.registraJogo(2, 1);
  cap.registraJogo(0, 2);
  cap.registraJogo(1, 2);
  cap.registraJogo(0, 1);
  cap.registraJogo(0, 1);
  cap.registraJogo(1, 2);
  cap.registraJogo(0, 0);
  cap.registraJogo(0, 2);
  cap.registraJogo(2, 1);
  cap.registraJogo(4, 2);
  cap.registraJogo(0, 3);
  cap.registraJogo(2, 0);
  cap.registraJogo(0, 2);
  imprimeEquipe(&cap);
  return 0;
}