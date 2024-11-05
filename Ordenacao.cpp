#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct informacoesProduto {
    char nome[100];
    int quantidadeVendida;
    float preco;
    char dataDaVenda[11];
};

vector<informacoesProduto> carregarDados(int opcaoDesejada);
void bubbleSort(vector<informacoesProduto> produtos);
void inserctionSort(vector<informacoesProduto> produtos);
void selectionSort(vector<informacoesProduto> produtos);
void coutingSort(vector<informacoesProduto> produtos);
void shellSort(vector<informacoesProduto> produtos);
void quickSort(vector<informacoesProduto> produtos);

int main() {
    int opcao = 0;
    do {
        cout<<"\n\t\t==[Seja bem vindo ao sistema de ordenacao de produtos, escolha um algoritmo]=="<<endl;
        cout<<" [1] - Bubble Sort\n [2] - Inserction Sort\n [3] - Selection Sort\n [4] - Couting Sort\n [5] - Shell Sort\n [6] - Quick Sort\n"<<endl;
        cout<<"Digite a opcao desejada:\n [>] ";
        cin>>opcao;
        if(opcao == 1){
            cout<<"Bubble Sort"<<endl;
        }
    } while (opcao != 0);

    cout<<"\n==[Fim do programa]=="<<endl;
}

vector<informacoesProduto> carregarDados(int opcaoDesejada) {
    char caminhoArquivo[90];
    vector<informacoesProduto> produtos;
    if(opcaoDesejada == 1) {
        caminhoArquivo = 'BaseDeDados/produtos1000.txt';
    }else if(opcaoDesejada == 2) {
        caminhoArquivo = 'BaseDeDados/produtos100000.txt';
    }else if(opcaoDesejada == 3) {
        caminhoArquivo = 'BaseDeDados/produtos1000000.txt';
    } else {
        cout<<"Opcao invalida"<<endl;
        return produtos;
    }

    ifstream arquivo(caminhoArquivo);
    string linha;
    while (getline(arquivo, linha)) {
        informacoesProduto produto{};
        stringstream ss(linha);
        ss.getline(produto.nome, 100, '\t');
        cout<<produto.nome <<endl;
        ss >> produto.quantidadeVendida;
        ss.ignore(1);
        ss >> produto.preco;
        ss.ignore(1);
        ss.getline(produto.dataDaVenda, 11, '\t');
        produtos.push_back(produto);
    }
    return produtos;
}
