#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

struct informacoesProduto {
    char nome[100];
    int quantidadeVendida;
    float preco;
    char dataDaVenda[11];
};

vector<informacoesProduto> carregarDados(int opcaoDesejada);
void bubbleSort();
void insertionSort();
void selectionSort();
void countingSort();
void shellSort();
void quickSort();
int particaoQuickSort( vector<informacoesProduto> &produtos, int menor, int maior);
void quickSort(vector<informacoesProduto> &produtos, int menor, int maior);

int main() {
    vector<informacoesProduto> listaDeProdutos;
    int opcao = 0;
    do {
        cout<<"\t==[Seja bem vindo ao sistema de ordenacao de produtos, escolha um algoritmo]=="<<endl;
        cout<<"\t\t[1] - Bubble Sort\n\t\t[2] - Inserction Sort\n\t\t[3] - Selection Sort\n\t\t[4] - Couting Sort\n\t\t[5] - Shell Sort\n\t\t[6] - Quick Sort\n"<<endl;
        cout<<"\tDigite a opcao desejada:\n\t [>] ";
        cin>>opcao;
        if(opcao == 1){
            bubbleSort();
        }
        if(opcao == 2){
            insertionSort();
        }
        if(opcao == 3){
            selectionSort();
        }
        if(opcao == 4){
            countingSort();
        }
        if(opcao == 5){
            shellSort();
        }
        if (opcao == 6) {
            quickSort();
        }
    } while (opcao != 0);

    cout<<"\n==[Fim do programa]=="<<endl;
}

vector<informacoesProduto> carregarDados(int opcaoDesejada) {
    string caminhoArquivo;
    vector<informacoesProduto> produtos;
    if(opcaoDesejada == 1) {
        caminhoArquivo = "BaseDeDados/produtos1000.txt";
    }else if(opcaoDesejada == 2) {
        caminhoArquivo = "BaseDeDados/produtos100000.txt";
    }else if(opcaoDesejada == 3) {
        caminhoArquivo = "BaseDeDados/produtos1000000.txt";
    } else {
        cout<<"Opcao invalida"<<endl;
        return produtos;
    }

    ifstream arquivo(caminhoArquivo);
    string linha;
    while (getline(arquivo, linha)) {
        informacoesProduto produto{};
        stringstream ss(linha);

        ss >> produto.nome;
        ss >> produto.quantidadeVendida;
        ss >> produto.preco;
        ss >> produto.dataDaVenda;

        produtos.push_back(produto);
    }
    return produtos;
}

void bubbleSort() {
    system("cls");
    int opcao = 0;
    cout<<"\t==[Qual a quantidade de registros que deseja trabalhar]==\n\t\t[1] - 1.000 registros\n\t\t[2] - 100.000 registros\n\t\t[3] - 1.000.000 registros\n\n\t\t[0] - Voltar\n"<<endl;
    cout<<"\tDigite a opcao desejada:\n\t [>] ";
    cin>>opcao;
    cin.ignore();
    vector<informacoesProduto> produtos = carregarDados(opcao);
    cout<< "\t[Ordenando...]"<<endl;
    clock_t inicio = clock();
    int n = produtos.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (produtos[j].preco > produtos[j + 1].preco) {
                swap(produtos[j], produtos[j + 1]);
            }
        }
    }
    clock_t fim = clock();
    cout<<"\n\t[Ordenacao concluida]"<<endl;
    cout<<"\tTempo de execucao: "<<double(fim - inicio)/CLOCKS_PER_SEC<< " segundos"<< "\n1"<<endl;
    cout<<"\tDeseja ver os resultados ordenados?\n\t\t[1] - Sim\n\t\t[0] - Nao\n"<<endl;
    cout<<"\t [>] ";
    cin>>opcao;
    cin.ignore();
    if(opcao == 1) {
        cout<<"\t==[Produtos ordenados]==\n";
        cout<<"\t"<<setw(100)<<"Nome"<<setw(20)<<"Quantidade Vendida"<<setw(20)<<"Preco"<<setw(20)<<"Data da Venda"<<endl;
        for (int i = 0; i < n; i++) {
            cout<<"\t"<<setw(100)<<produtos[i].nome<<setw(20)<<produtos[i].quantidadeVendida<<setw(20)<<produtos[i].preco<<setw(20)<<produtos[i].dataDaVenda<<endl;
        }
    }
    system("pause");
    system("cls");
}
void insertionSort() {
    system("cls");
    int opcao = 0;
    cout<<"\t==[Qual a quantidade de registros que deseja trabalhar]==\n\t\t[1] - 1.000 registros\n\t\t[2] - 100.000 registros\n\t\t[3] - 1.000.000 registros\n\n\t\t[0] - Voltar\n"<<endl;
    cout<<"\tDigite a opcao desejada:\n\t [>] ";
    cin>>opcao;
    cin.ignore();
    vector<informacoesProduto> produtos = carregarDados(opcao);

    cout<< "\t[Ordenando...]"<<endl;
    clock_t inicio = clock();
    int n = produtos.size();
    for (int i = 1; i < n; i++) {
        informacoesProduto chave = produtos[i];
        int j = i - 1;
        while (j >= 0 && produtos[j].preco > chave.preco) {
            produtos[j + 1] = produtos[j];
            j = j - 1;
        }
        produtos[j + 1] = chave;
    }
    clock_t fim = clock();
    cout<<"\n\t[Ordenacao concluida]"<<endl;
    cout<<"\tTempo de execucao: "<<double(fim - inicio)/CLOCKS_PER_SEC<< " segundos"<< "\n1"<<endl;
    cout<<"\tDeseja ver os resultados ordenados?\n\t\t[1] - Sim\n\t\t[0] - Nao\n"<<endl;
    cout<<"\t [>] ";
    cin>>opcao;
    cin.ignore();
    if(opcao == 1) {
        cout<<"\t==[Produtos ordenados]==\n";
        cout<<"\t"<<setw(100)<<"Nome"<<setw(20)<<"Quantidade Vendida"<<setw(20)<<"Preco"<<setw(20)<<"Data da Venda"<<endl;
        for (int i = 0; i < n; i++) {
            cout<<"\t"<<setw(100)<<produtos[i].nome<<setw(20)<<produtos[i].quantidadeVendida<<setw(20)<<produtos[i].preco<<setw(20)<<produtos[i].dataDaVenda<<endl;
        }
    }
    system("pause");
    system("cls");
}
void selectionSort() {
    system("cls");
    int opcao = 0;
    cout<<"\t==[Qual a quantidade de registros que deseja trabalhar]==\n\t\t[1] - 1.000 registros\n\t\t[2] - 100.000 registros\n\t\t[3] - 1.000.000 registros\n\n\t\t[0] - Voltar\n"<<endl;
    cout<<"\tDigite a opcao desejada:\n\t [>] ";
    cin>>opcao;
    cin.ignore();
    vector<informacoesProduto> produtos = carregarDados(opcao);

    cout<< "\t[Ordenando...]"<<endl;
    clock_t inicio = clock();
    int n = produtos.size();
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (produtos[j].preco < produtos[menor].preco) {
                menor = j;
            }
        }
        swap(produtos[i], produtos[menor]);
    }
    clock_t fim = clock();
    cout<<"\n\t[Ordenacao concluida]"<<endl;
    cout<<"\tTempo de execucao: "<<double(fim - inicio)/CLOCKS_PER_SEC<< " segundos"<< "\n1"<<endl;
    cout<<"\tDeseja ver os resultados ordenados?\n\t\t[1] - Sim\n\t\t[0] - Nao\n"<<endl;
    cout<<"\t [>] ";
    cin>>opcao;
    cin.ignore();
    if(opcao == 1) {
        cout<<"\t==[Produtos ordenados]==\n";
        cout<<"\t"<<setw(100)<<"Nome"<<setw(20)<<"Quantidade Vendida"<<setw(20)<<"Preco"<<setw(20)<<"Data da Venda"<<endl;
        for (int i = 0; i < n; i++) {
            cout<<"\t"<<setw(100)<<produtos[i].nome<<setw(20)<<produtos[i].quantidadeVendida<<setw(20)<<produtos[i].preco<<setw(20)<<produtos[i].dataDaVenda<<endl;
        }
    }
    system("pause");
    system("cls");
}
void countingSort() {
    system("cls");
    int opcao = 0;
    cout<<"\t==[Qual a quantidade de registros que deseja trabalhar]==\n\t\t[1] - 1.000 registros\n\t\t[2] - 100.000 registros\n\t\t[3] - 1.000.000 registros\n\n\t\t[0] - Voltar\n"<<endl;
    cout<<"\tDigite a opcao desejada:\n\t [>] ";
    cin>>opcao;
    cin.ignore();
    vector<informacoesProduto> produtos = carregarDados(opcao);

    cout<< "\t[Ordenando...]"<<endl;
    clock_t inicio = clock();
    int quantidadeDeElementos = produtos.size();
    int maior = 0;

    for (int i = 0; i < quantidadeDeElementos; i++) {
        maior = max(maior, int(produtos[i].preco * 1000));
    }

    vector<int> vetorAuxiliar(maior + 1, 0);

    for (int i = 0; i < quantidadeDeElementos; i++) {
        vetorAuxiliar[(int)(produtos[i].preco * 1000)]++;
    }

    for (int i = 1; i <= maior; i++) {
        vetorAuxiliar[i] += vetorAuxiliar[i - 1];
    }

    std::vector<informacoesProduto> vetorOrdenado(quantidadeDeElementos);

    for (int i = quantidadeDeElementos - 1; i >= 0; i--) {
        int precoInt = (int)(produtos[i].preco * 1000);
        vetorOrdenado[vetorAuxiliar[precoInt] - 1] = produtos[i];
        vetorAuxiliar[precoInt]--;
    }

    clock_t fim = clock();
    cout<<"\n\t[Ordenacao concluida]"<<endl;
    cout<<"\tTempo de execucao: "<<double(fim - inicio)/CLOCKS_PER_SEC<< " segundos"<< "\n1"<<endl;
    cout<<"\tDeseja ver os resultados ordenados?\n\t\t[1] - Sim\n\t\t[0] - Nao\n"<<endl;
    cout<<"\t [>] ";
    cin>>opcao;
    cin.ignore();
    if(opcao == 1) {
        cout<<"\t==[Produtos ordenados]==\n";
        cout<<"\t"<<setw(100)<<"Nome"<<setw(20)<<"Quantidade Vendida"<<setw(20)<<"Preco"<<setw(20)<<"Data da Venda"<<endl;
        for (int i = 0; i < quantidadeDeElementos; i++) {
            cout<<"\t"<<setw(100)<<vetorOrdenado[i].nome<<setw(20)<<vetorOrdenado[i].quantidadeVendida<<setw(20)<<vetorOrdenado[i].preco<<setw(20)<<vetorOrdenado[i].dataDaVenda<<endl;
        }
    }
    system("pause");
    system("cls");

}
void shellSort() {
    system("cls");
    int opcao = 0;
    cout<<"\t==[Qual a quantidade de registros que deseja trabalhar]==\n\t\t[1] - 1.000 registros\n\t\t[2] - 100.000 registros\n\t\t[3] - 1.000.000 registros\n\n\t\t[0] - Voltar\n"<<endl;
    cout<<"\tDigite a opcao desejada:\n\t [>] ";
    cin>>opcao;
    cin.ignore();
    vector<informacoesProduto> produtos = carregarDados(opcao);

    cout<< "\t[Ordenando...]"<<endl;
    clock_t inicio = clock();
    for(int gap = produtos.size()/2; gap > 0; gap /= 2) {
        for(int i = gap; i < produtos.size(); i++) {
            informacoesProduto temporario = produtos[i];
            int j;
            for(j = i; j >= gap && produtos[j - gap].preco > temporario.preco; j -= gap) {
                produtos[j] = produtos[j - gap];
            }
            produtos[j] = temporario;
        }
    }
    clock_t fim = clock();
    cout<<"\n\t[Ordenacao concluida]"<<endl;
    cout<<"\tTempo de execucao: "<<double(fim - inicio)/CLOCKS_PER_SEC<< " segundos"<< "\n1"<<endl;
    cout<<"\tDeseja ver os resultados ordenados?\n\t\t[1] - Sim\n\t\t[0] - Nao\n"<<endl;
    cout<<"\t [>] ";
    cin>>opcao;
    cin.ignore();
    if(opcao == 1) {
        cout<<"\t==[Produtos ordenados]==\n";
        cout<<"\t"<<setw(100)<<"Nome"<<setw(20)<<"Quantidade Vendida"<<setw(20)<<"Preco"<<setw(20)<<"Data da Venda"<<endl;
        for (auto & produto : produtos) {
            cout<<"\t"<<setw(100)<<produto.nome<<setw(20)<<produto.quantidadeVendida<<setw(20)<<produto.preco<<setw(20)<<produto.dataDaVenda<<endl;
        }
    }
    system("pause");
    system("cls");
}

void quickSort() {
    system("cls");
    int opcao = 0;
    cout<<"\t==[Qual a quantidade de registros que deseja trabalhar]==\n\t\t[1] - 1.000 registros\n\t\t[2] - 100.000 registros\n\t\t[3] - 1.000.000 registros\n\n\t\t[0] - Voltar\n"<<endl;
    cout<<"\tDigite a opcao desejada:\n\t [>] ";
    cin>>opcao;
    cin.ignore();
    vector<informacoesProduto> produtos = carregarDados(opcao);

    cout<< "\t[Ordenando...]"<<endl;
    clock_t inicio = clock();

    int n = produtos.size();
    quickSort(produtos, 0, n-1);

    clock_t fim = clock();
    cout<<"\n\t[Ordenacao concluida]"<<endl;
    cout<<"\tTempo de execucao: "<<double(fim - inicio)/CLOCKS_PER_SEC<< " segundos"<< "\n1"<<endl;
    cout<<"\tDeseja ver os resultados ordenados?\n\t\t[1] - Sim\n\t\t[0] - Nao\n"<<endl;
    cout<<"\t [>] ";
    cin>>opcao;
    cin.ignore();
    if(opcao == 1) {
        cout<<"\t==[Produtos ordenados]==\n";
        cout<<"\t"<<setw(100)<<"Nome"<<setw(20)<<"Quantidade Vendida"<<setw(20)<<"Preco"<<setw(20)<<"Data da Venda"<<endl;
        for (int i = 0; i < n; i++) {
            cout<<"\t"<<setw(100)<<produtos[i].nome<<setw(20)<<produtos[i].quantidadeVendida<<setw(20)<<produtos[i].preco<<setw(20)<<produtos[i].dataDaVenda<<endl;
        }
    }
    system("pause");
    system("cls");
}
void quickSort(vector<informacoesProduto>& produtos, int menor, int maior) {
    if (menor < maior) {
        int pi = particaoQuickSort(produtos, menor, maior);
        quickSort(produtos, menor, pi - 1);
        quickSort(produtos, pi + 1, maior);
    }
}
int particaoQuickSort(vector<informacoesProduto>& produtos, int menor, int maior) {
    informacoesProduto pivoEscolhido = produtos[maior];
    int i = menor - 1;
    for (int j = menor; j <= maior - 1; j++) {
        if (produtos[j].preco < pivoEscolhido.preco) {
            i++;
            swap(produtos[i], produtos[j]);
        }
    }
    swap(produtos[i + 1], produtos[maior]);
    return i + 1;
}
