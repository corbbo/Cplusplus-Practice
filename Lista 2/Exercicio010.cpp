// Exercicio 10, Lista 2
// Thiago Zilberknop
// Ultima Atualizacao: 3/24/23
// --- FINALIDADE ---
// Esse programa recebe do usuario uma serie de datas e determina quais sao validas e, se pelo menos uma for, qual delas é a mais antiga

#include <iostream>

using namespace std;

struct data {
  int dia, mes, ano;
};

int leapyear(int n) {
    return (((n % 4 == 0) && (n % 100 != 0)) || (n  % 400 == 0));
}

int datavalida(struct data p) {
  if (p.ano < 0) return 0;
  if (p.mes < 1 || p.mes > 12) return 0;
  if (p.dia <= 0 || p.dia > 31) return 0;
  if (p.mes == 2) { //fevereiro
    if (leapyear(p.ano)) return p.dia <= 29;
    else return p.dia <= 28;
    }
  if (p.mes == 4 || p.mes == 6 || p.mes == 9 || p.mes == 11) { //meses com 30 dias
    return p.dia <= 30;
  }
  return 1; //todos os cheques nao dispararam entao a data é valida
}

int main() {
  struct data datas[5];
  int maisvelho = 0, erno = 0;
  for (int i = 0; i < 5; i++) cin >> datas[i].dia >> datas[i].mes >> datas[i].ano;
  for (int i = 0; i < 5; i++) {
    if (datavalida(datas[i])) {
      cout << "+" << endl;
      if (datas[i].ano < datas[maisvelho].ano) maisvelho = i;
      else if (datas[i].mes < datas[maisvelho].mes && datas[i].ano == datas[maisvelho].ano) maisvelho = i;
      else if (datas[i].dia <= datas[maisvelho].dia && datas[i].mes == datas[maisvelho].mes) maisvelho = i;
    }else {
      cout << "-" << endl;
      erno++;
      }
    }
  bool heehoo = datas[maisvelho].mes < 10;
  bool hoohee = datas[maisvelho].dia < 10;
  if (erno == 5) cout << "*" << endl;
  else {
    if (hoohee) cout << "0" << datas[maisvelho].dia << "/";
    else cout << datas[maisvelho].dia << "/";
    if (heehoo) cout << "0" << datas[maisvelho].mes << "/";
    else cout << datas[maisvelho].mes << "/";
    cout << datas[maisvelho].ano << endl;
  }
}