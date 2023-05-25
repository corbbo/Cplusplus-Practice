// Exercicio 4, Lista 6
// Thiago Zilberknop
// Ultima Atualizacao: 5/17/23
// --- FINALIDADE ---
// Esse programa cria uma estrutura de dados de lista duplamente linkada de clubes de futebol, inserindo novos nodos em ordem de campeonatos, vice-campeonatos, e finalmente alfabética


#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Clube
{
private:
    string nome;
    int campeonatos;
    int viceCampeonatos;

public:
    Clube(string n = "", int c = 0, int v = 0)
    {
        nome = n;
        campeonatos = c;
        viceCampeonatos = v;
    }
    string obtemNome() { return nome; }
    void defineNome(string n) { nome = n; }
    int obtemCampeonatos() { return campeonatos; }
    void defineCampeonatos(int c) { campeonatos = c; }
    int obtemViceCampeonatos() { return viceCampeonatos; }
    void defineViceCampeonatos(int c) { viceCampeonatos = c; }
    string toString()
    {
        stringstream ss;
        ss << nome << ": " << campeonatos << " campeonato(s), ";
        ss << viceCampeonatos << " vice-campeonato(s)";
        return ss.str();
    }
    string toCSV()
    {
        stringstream ss;
        ss << nome << ";" << campeonatos << ";" << viceCampeonatos;
        return ss.str();
    }
    bool operator<(Clube &c)
    {
        if (campeonatos < c.obtemCampeonatos())
            return true;
        if (campeonatos > c.obtemCampeonatos())
            return false;
        if (viceCampeonatos < c.obtemViceCampeonatos())
            return true;
        if (viceCampeonatos > c.obtemViceCampeonatos())
            return false;
        return nome >= c.obtemNome();
    }
};
class Campeoes
{
private:
    class Nodo
    {
    public:
        Clube *clube;
        Nodo *prox, *ant;
        Nodo(Clube *c);
    };
    Nodo *primeiro;
    int numClubes;

public:
    Campeoes();
    ~Campeoes();
    int obtemNumClubes();
    Clube *obtemClube(int indice);
    void insere(string n, int nc, int nv);
    void limpa();
};
// --- SOLUCAO (inicio) ---
Campeoes::Nodo::Nodo(Clube *c) {
    clube = c;
    prox = ant = nullptr;
}
Campeoes::Campeoes() {
    primeiro = new Nodo(nullptr);
    numClubes = 0;
}
void Campeoes::limpa() {
    Campeoes::Nodo *aux = primeiro;
    while (primeiro != nullptr) {
        primeiro = primeiro->prox;
        delete aux->clube;
        delete aux;
        aux = primeiro;
    }
}
Campeoes::~Campeoes() {limpa();}
int Campeoes::obtemNumClubes()          {return numClubes;}
Clube *Campeoes::obtemClube(int indice) {
    int i = 0;
    if (indice > numClubes || indice < 0) return nullptr;
    else for (Campeoes::Nodo *aux = primeiro; aux != nullptr && i <= numClubes; aux = aux->prox, i++) if (indice == i) return aux->clube;
}
void Campeoes::insere(string n, int nc, int nv) {
    Clube *newClub = new Clube(n, nc, nv);
    Campeoes::Nodo *newNode = new Nodo(newClub);
    if (numClubes == 0) {
        primeiro = newNode;
        numClubes++;
        return;
    } else if (numClubes == 1) {
        if (!(*newClub < *(primeiro->clube))) {
            primeiro->ant = newNode;
            newNode->prox = primeiro;
            newNode->ant = nullptr;
            primeiro = newNode;
        } else {
            primeiro->prox = newNode;
            newNode->ant = primeiro;
            newNode->prox = nullptr;
        }
        numClubes++;
        return;
    } else if (numClubes > 1) {
        Campeoes::Nodo *aux = primeiro;
        while (aux != nullptr) {
            if (!(*newClub < *(aux->clube))) break;
            else aux = aux->prox;
        }
        if (aux == primeiro) {
            primeiro->ant = newNode;
            newNode->prox = primeiro;
            newNode->ant = nullptr;
            primeiro = newNode;
        } else if (aux == nullptr) {
            Campeoes::Nodo *ultimo = primeiro;
            while (ultimo->prox != nullptr) ultimo = ultimo->prox;
            ultimo->prox = newNode;
            newNode->ant = ultimo;
            newNode->prox = nullptr;
        } else {
            newNode->prox = aux;
            newNode->ant = aux->ant;
            aux->ant->prox = newNode;
            aux->ant = newNode;
        }
        numClubes++;
        return;
    }
}

// --- SOLUCAO (fim) ---
void mostraCampeoes(Campeoes *c)
{
    int tam = c->obtemNumClubes();
    for (int i = 0; i < tam; ++i)
    {
        Clube *clube = c->obtemClube(i);
        cout << clube->toString() << endl;
    }
    cout << "------------------" << endl;
}
int main()
{
    Campeoes *copaDoBrasil = new Campeoes();
    mostraCampeoes(copaDoBrasil);
    copaDoBrasil->insere("Atletico Mineiro", 2, 1);
    mostraCampeoes(copaDoBrasil);
    copaDoBrasil->insere("Brasiliense", 0, 1);
    copaDoBrasil->insere("Palmeiras", 4, 1);
    copaDoBrasil->insere("Fluminense", 1, 2);
    mostraCampeoes(copaDoBrasil);
    copaDoBrasil->insere("Vitoria", 0, 1);
    copaDoBrasil->insere("Goias", 0, 1);
    copaDoBrasil->insere("Gremio", 5, 4);
    copaDoBrasil->insere("Athletico Paranaense", 1, 2);
    copaDoBrasil->insere("Juventude", 1, 0);
    copaDoBrasil->insere("Cruzeiro", 6, 2);
    mostraCampeoes(copaDoBrasil);
    copaDoBrasil->insere("Internacional", 1, 2);
    copaDoBrasil->insere("Santos", 1, 1);
    copaDoBrasil->insere("Figueirense", 0, 1);
    copaDoBrasil->insere("Coritiba", 0, 2);
    copaDoBrasil->insere("Vasco", 1, 1);
    copaDoBrasil->insere("Flamengo", 4, 4);
    copaDoBrasil->insere("Criciuma", 1, 0);
    copaDoBrasil->insere("Corinthians", 3, 4);
    copaDoBrasil->insere("Santo Andre", 1, 0);
    copaDoBrasil->insere("Paulista", 1, 0);
    copaDoBrasil->insere("Ceara", 0, 1);
    copaDoBrasil->insere("Botafogo", 0, 1);
    copaDoBrasil->insere("Sao Paulo", 0, 1);
    copaDoBrasil->insere("Sport", 1, 1);
    mostraCampeoes(copaDoBrasil);
    delete copaDoBrasil;
    return 0;
}
