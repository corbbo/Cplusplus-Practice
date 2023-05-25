// Exercicio 3, Lista 4
// Thiago Zilberknop
// Ultima Atualizacao: 4/12/23
// --- FINALIDADE ---
// Esse programa define duas classes, produto e estoque, e roda uma serie de testes com objetos dessas classes


#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#define MAX_PRODUTOS 10

using namespace std;

class Produto {
private:
  int codigo;
  string descricao;
  int stock;
  double value;

public:
  Produto(int cod = 0, string desc = "", int stk = 0, double val = 0.0) {
    codigo = cod;
    descricao = desc;
    stock = stk;
    value = val;
  }
  int obtemCodigo() { return codigo; }
  int obtemQuantidade() { return stock; }
  string obtemDescricao() { return descricao; }
  double obtemValorUnitario() { return value; }
  void defineCodigo(int i) { codigo = i; }
  void defineQuantidade(int i) { stock = i; }
  void defineDescricao(string i) { descricao = i; }
  void defineValorUnitario(double i) { value = i; }
  string str() {
    stringstream ss;
    ss << "[" << codigo << "]" << " " << descricao << ": " << stock << "x" << fixed << setprecision(2) << value;
    return ss.str();
  }
};

class Estoque {
private:
  string deposito;
  Produto * produtos[10];
  int totalStock;

public:
  Estoque(string depos = "", int total = 0) {
    deposito = depos;
    totalStock = total;
  }
  string obtemDeposito() { return deposito; }
  int obtemNumProdutos() { return totalStock; }
  Produto * obtemProduto(int i) {
    if (i < 0 || i >= totalStock) return nullptr;
    else return produtos[i];
  }
  void defineDeposito(string dep) { deposito = dep; }
  bool adicionaProduto(Produto * p) {
    if (totalStock < 10) {
      produtos[totalStock++] = p;
      return true;
    } else return false;
  }
  double calculaTotalEstoque() {
    double retorno = 0;
    for (int i = 0; i < totalStock; i++) {
      int qnt = produtos[i]->obtemQuantidade();
      double val = produtos[i]->obtemValorUnitario();
      retorno += val*qnt;
    }
    return retorno;
  }
  string str() {
    stringstream ss;
    ss << "Deposito: " << deposito << endl;
    if (totalStock > 0) {
      for (int i = 0; i < totalStock; i++) {
        ss << produtos[i]->str() << endl;
      }
      double stk = calculaTotalEstoque();
      ss << "TOTAL DO ESTOQUE = " << fixed << setprecision(2) << stk << endl;
    }
    return ss.str();
  }
};

int main() {
  Produto *produto[] = {
      new Produto(1, "Cimento CP IV 32 25kg Votoran", 500, 17.29),
      new Produto(2, "Cimento CPB-40 Branco Estrutural 15kg Axton", 100, 72.90),
      new Produto(3, "Rejunte Ceramica Ceramfix Marfim 1kg", 50, 7.00),
      new Produto(4, "Luva PVC Branco Rosca 1/2\" 20mm Plastilit", 60, 1.47),
      new Produto(5, "Luva PVC Marrom Solda 1\" 32mm Tigre", 30, 2.79),
      new Produto(6, "Meio Bloco Ceramico 6 Furos 9x14x12cm Olaria Estancia", 10000, 0.76),
      new Produto(7, "Bloco de Concreto Celular Autoclavado 60x30x10cm Sical", 1000, 13.99),
      new Produto(8, "Telha Ceramica 40x22,5cm Francesa Esmaltada Chumbo Vogel", 300, 2.79),
      new Produto(9, "Telha Ceramica 41x24cm Portuguesa Natural Claudio Vogel", 1000, 0.94),
      new Produto(10, "Janela de Correr Aluminio Pintado Preto Fosco 1,00x1,50m" "Linha Confort Brimak", 10, 574.90),
      new Produto(11, "Folha de Porta de Giro Branco 2,10x0,70m Artens", 5, 219.90)};

  int numProdutos = sizeof(produto) / sizeof(Produto *);
  Estoque *estoque = new Estoque("Provisorio");
  cout << estoque->str() << endl;
  estoque->defineDeposito("Deposito Geral");
  int p;
  // Insere 5 produtos
  for (p = 0; p < 5; ++p)
    if (!estoque->adicionaProduto(produto[p])) {
      cerr << "ERRO";
      exit(1);
    }
  // Testa se os 5 produtos foram inseridos
  for (p = 0; p < 5; ++p)
    if (estoque->obtemProduto(p) != produto[p]) {
      cerr << "ERRO";
      exit(1);
    }
  // Testa se ha outros itens no estoque
  for (; p < numProdutos; ++p)
    if (estoque->obtemProduto(p) != nullptr) {
      cerr << "ERRO";
      exit(1);
    }
  cout << estoque->str() << endl;
  // Adiciona mais 5 produtos
  for (p = 5; p < MAX_PRODUTOS; ++p)
    if (!estoque->adicionaProduto(produto[p])) {
      cerr << "ERRO";
      exit(1);
    }
  // Tenta adicionar produtos alem do limite
  for (; p < numProdutos; ++p)
    if (estoque->adicionaProduto(produto[p])) {
      cerr << "ERRO";
      exit(1);
    }
  // Testa se os 10 produtos estao inseridos
  for (p = 0; p < MAX_PRODUTOS; ++p)
    if (estoque->obtemProduto(p) != produto[p]) {
      cerr << "ERRO";
      exit(1);
    }
  cout << estoque->str() << endl;
  delete estoque;
  for (int p = 0; p < numProdutos; ++p)
    delete produto[p];
  return 0;
}