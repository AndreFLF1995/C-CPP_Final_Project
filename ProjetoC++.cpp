// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstring>
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
#include <vector>
#include <sstream>
#include <fstream>
#include "Mota.cpp"
#include "Fornecedor.cpp"
#include "Encomenda.cpp"
using namespace std;

//----------------Main----------------------
void header();
void menuMain();
void pausa();
char obtemEscolha(char escolha, int numOp);
bool processaEscolha(char escolha, bool queroSair, int numOp);
bool sairDoPrograma(bool queroSair);
void escolhaInvalida(int numOp);

//----------------Mota----------------------
void menuMota();
void opcoesMota();
char obtemEscolhaMota(char, int);
bool processaEscolhaMota(vector<Mota>*, char, bool, int);
void listarMotas(vector<Mota>);
void inserirMota(vector<Mota>*);
void apagarMota(vector<Mota>*);
void pesquisarMota(vector<Mota>);
void atualizarMota(vector<Mota>*);
void venderMota(vector<Mota>*);
void reporMota(vector<Mota>*);
void guardaFicheiroMota(vector<Mota> motas);
void lerFicheiroMota(vector<Mota>* motas);

//----------------Fornecedor----------------------
void menuFornecedor();
void opcoesFornecedor();
char obtemEscolhaForn(char, int);
bool processaEscolhaForn(vector<Fornecedor>*, char, bool, int);
void listarfornecedores(vector<Fornecedor>);
void inserirFornecedor(vector<Fornecedor>*);
void apagarFornecedor(vector<Fornecedor>*);
void pesquisarFornecedor(vector<Fornecedor>);
void atualizarFornecedor(vector<Fornecedor>*);
void guardaFicheiroForn(vector<Fornecedor> fornecedores);
void lerFicheiroForn(vector<Fornecedor>* fornecedores);

//----------------Encomenda----------------------
void menuEncomenda();
void opcoesEncomenda();
char obtemEscolhaEnc(char, int);
bool processaEscolhaEnc(vector<Encomenda>*, char, bool, int);
void listarEncomendas(vector<Encomenda>);
void inserirEncomenda(vector<Encomenda>*);
void apagarEncomenda(vector<Encomenda>*);
void pesquisarEncomenda(vector<Encomenda>);
void atualizarEncomenda(vector<Encomenda>*);
void guardaFicheiroEnc(vector<Encomenda> encomendas);
void lerFicheiroEnc(vector<Encomenda>* encomendas);

int Mota::numMotas = 0;
int Fornecedor::numFornecedores = 0;
int Encomenda::numEncomendas = 0;

vector<Mota> motas;
vector<Fornecedor> fornecedores;
vector<Encomenda> encomendas;

// biblioteca conyo
int main()
{
    setlocale(LC_ALL, "Portuguese");
    system("color b");

    char escolha = '\0';
    bool queroSair = false;
    const int NUMOPCOES = 4;
    do
    {
        system("cls");
        header();
        menuMain();
        escolha = obtemEscolha(escolha, NUMOPCOES);
        queroSair = processaEscolha(escolha, queroSair, NUMOPCOES);
    } while (!queroSair);
}

//------------------------------------ FUNÇÕES MAIN---------------------------------------

void header()
{
    cout << "********************************************************************" << endl;
    cout << "*    ______  ___     _____      _______                   _____    *" << endl;
    cout << "*    ___   |/  /_______  /________  __ \\___  _______________  /_   *" << endl;
    cout << "*    __  /|_/ /_  __ \\  __/  __ \\  / / /  / / /  _ \\_  ___/  __/   *" << endl;
    cout << "*    _  /  / / / /_/ / /_ / /_/ / /_/ // /_/ //  __/(__  )/ /_     *" << endl;
    cout << "*    /_/  /_/  \\____/\\__/ \\____/\\___\\_\\\\__,_/ \\___//____/ \\__/     *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << "********************************************************************" << endl;
}
void menuMain()
{
    cout << "*                                                                  *" << endl;
    cout << "*                        A. Menu Mota.                             *" << endl;
    cout << "*                        B. Menu Fornecedor.                       *" << endl;
    cout << "*                        C. Menu Encomenda.                        *" << endl;
    cout << "*                        D. Sair do programa.                      *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
}

char obtemEscolha(char escolha, int numOp)
{
    char ultimaOp = (char)(numOp + 64); // "A" - ASCII 65	
    cout << "Qual a sua escolha (A-" << ultimaOp << ")? ";
    cin >> escolha; cin.ignore();
    return escolha;
}

bool processaEscolha(char escolha, bool queroSair, int numOp)
{

    switch (escolha)
    {
    case 'A': case 'a': menuMota();
        break;
    case 'B': case 'b': menuFornecedor();
        break;
    case 'C': case 'c': menuEncomenda();
        break;
    case 'D': case 'd':
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch"

    return queroSair;
} // Fim da Função "processaEscolha()".

void escolhaInvalida(int numOp)
{
    char ultimaOp = (char)(64 + numOp);  // 68 -> 'D'
    cout << "Escolha inválida! Escolha deve ser de A a " << ultimaOp;
    cout << "." << endl;
    pausa();
} // Fim da função "escolhaInvalida()".

void pausa()
{
    cout << "Prima qualquer tecla para continuar ... " << endl;
    cin.get();
} // Fim da função "pausaMota()".

bool sairDoPrograma(bool queroSair)
{
    system("cls");
    header();
    char resposta = '\0';
    fflush(stdin);
    cout << "Tem a certeza (S/N)? ";
    cin >> resposta; cin.ignore();
    if (resposta == 'S' || resposta == 's')
        queroSair = true;
    return queroSair;
} // Fim da função "sairDoPrograma()".

//------------------------------------ FIM FUNÇÕES MAIN ---------------------------------------

//------------------------------------   FUNÇÕES MOTA   ---------------------------------------

void menuMota()
{
    char escolha = '\0';
    bool queroSair = false;
    const int NUMOPCOES = 8;

    do
    {
        system("cls");
        header();
        opcoesMota();
        lerFicheiroMota(&motas);
        escolha = obtemEscolhaMota(escolha, NUMOPCOES);
        queroSair = processaEscolhaMota(&motas, escolha, queroSair, NUMOPCOES);
    } while (!queroSair);
}

void opcoesMota()
{
    cout << "*                                                                  *" << endl;
    cout << "*                        A. Inserir Mota.                          *" << endl;
    cout << "*                        B. Listar Mota.                           *" << endl;
    cout << "*                        C. Pesquisar Mota.                        *" << endl;
    cout << "*                        D. Atualizar Mota.                        *" << endl;
    cout << "*                        E. Vender Mota.                           *" << endl;
    cout << "*                        F. Repor Mota.                            *" << endl;
    cout << "*                        G. Apagar Mota.                           *" << endl;
    cout << "*                        H. Sair do programa.                      *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
}

char obtemEscolhaMota(char escolha, int numOp)
{
    char ultimaOp = (char)(numOp + 64); // "A" - ASCII 65	
    cout << "Qual a sua escolha (A-" << ultimaOp << ")? ";
    cin >> escolha; cin.ignore();
    return escolha;
}

bool processaEscolhaMota(vector<Mota>* motas, char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a': inserirMota(motas);
        guardaFicheiroMota(*motas);
        break;
    case 'B': case 'b': listarMotas(*motas);
        break;
    case 'C': case 'c': pesquisarMota(*motas);
        break;
    case 'D': case 'd': atualizarMota(motas);
        guardaFicheiroMota(*motas);
        break;
    case 'E': case 'e': venderMota(motas);
        guardaFicheiroMota(*motas);
        break;
    case 'F': case 'f':
        reporMota(motas);
        guardaFicheiroMota(*motas);
        break;
    case 'G': case 'g': apagarMota(motas);
        guardaFicheiroMota(*motas);
        break;
    case 'H': case 'h':
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch"

    return queroSair;
}

void inserirMota(vector<Mota>* motas)
{
    system("cls");
    header();
    Mota* mota;
    mota = new Mota;
    mota->novaMota();

    int nMotas = motas->size();
    cout << "Número de motas: " << nMotas << "." << endl;

    motas->push_back(*mota);
    Mota::numMotas++;
    //motas.insert(motas.begin()+nMotas, mota);
    motas->at(nMotas).mostraMota();
    nMotas = motas->size();
    cout << "Número de motas: " << nMotas << "." << endl;
    cout << "Mota inserido com sucesso!" << endl;
    pausa();
}

void pesquisarMota(vector<Mota> motas)
{
    system("cls");
    header();
    int nMota = 0;
    int nMotas = motas.size();
    if (nMotas <= 0)
    {
        cout << "Não existem motas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o mota a pesquisar (1-" << nMotas << ")? ";
            cin >> nMota; cin.ignore();
            if (nMota < 1 || nMota > nMotas)
            {
                cout << "Número de motas entre 1 e " << nMotas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nMota < 1 || nMota > nMotas);

        motas[nMota - 1].mostraMota();
        pausa();
    }
}

void atualizarMota(vector<Mota>* motas)
{
    system("cls");
    header();
    int nMota = 0;
    int nMotas = motas->size();
    if (nMotas <= 0)
    {
        cout << "Não existem motas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o mota a atualizar (1-" << nMotas << ")? ";
            cin >> nMota; cin.ignore();
            if (nMota < 1 || nMota > nMotas)
            {
                cout << "Número de motas entre 1 e " << nMotas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nMota < 1 || nMota > nMotas);
        (*motas)[nMota - 1].mostraMota();

        cout << "O que quer alterar? Tudo(1) ou só um campo(2)? Prima para selecionar. " << endl;
        int escolha = 0;
        cin >> escolha;

        if (escolha == 2)
        {
            cout << "1 - Marca\n2 - Modelo\n3 - Cor\n4 - Caixa\n5 - Quilómetros\n6 - Combustível\n7 - Ano e Mês de Registo\n8 - Potência\n9 - Cilindrada\n10 - Revisão\n11 - Número de Unidades\n 12 - Quebra\n13 - Preço" << endl;
            cin >> escolha;
            switch (escolha)
            {
            case 1:
                cout << "Marca: "; (*motas)[nMotas - 1].leMarca();
                break;
            case 2:
                cout << "Modelo: "; (*motas)[nMotas - 1].leModelo();
                break;
            case 3:
                cout << "Cor: "; (*motas)[nMotas - 1].leCor();
                break;
            case 4:
                cout << "Caixa: "; (*motas)[nMotas - 1].leCaixa();
                break;
            case 5:
                cout << "Quilómetros: "; (*motas)[nMotas - 1].leKm();
                break;
            case 6:
                cout << "Combustível: "; (*motas)[nMotas - 1].leCombustivel();
                break;
            case 7:
                cout << "Ano e Mês de Registo: "; (*motas)[nMotas - 1].leAnoMesRegisto();
                break;
            case 8:
                cout << "Potência: "; (*motas)[nMotas - 1].lePotencia();
                break;
            case 9:
                cout << "Cilindrada: "; (*motas)[nMotas - 1].leCilindrada();
                break;
            case 10:
                cout << "Revisão: "; (*motas)[nMotas - 1].leRevisaoFeita();
                break;
            case 11:
                cout << "Número de Unidades: "; (*motas)[nMotas - 1].leNumUnidades();
                break;
            case 12:
                cout << "Quebra: "; (*motas)[nMotas - 1].leQuebra();
                break;
            case 13:
                cout << "Preço: "; (*motas)[nMotas - 1].lePreco();
                break;
            default: cout << "Insira uma opcao correta.";
            }
        }
        else
        {
            (*motas)[nMota - 1].novaMota();
        }

        (*motas)[nMota - 1].mostraMota();
        cout << "Atualização efetuada com sucesso!" << endl;
        pausa();
    }
}

void listarMotas(vector<Mota> motas)
{
    system("cls");
    header();
    int nMotas = motas.size();
    cout << "Número de motas: " << nMotas << "." << endl;
    if (nMotas <= 0)
    {
        cout << "Não existem motas!" << endl;
        pausa();
    }
    else
    {
        cout << "-> Listagem de motas: \n";
        for (int cMota = 0; cMota < nMotas; cMota++)
        {
            cout << "Mota " << cMota + 1 << ": ";
            cout << " -> "; motas[cMota].mostraMota();
        } // Fim do "for"
        pausa();
    }
}

void venderMota(vector<Mota>* motas)
{
    system("cls");
    header();
    int nMota = 0;
    int nMotas = motas->size();
    if (nMotas <= 0)
    {
        cout << "Não existem motas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o mota a vender (1-" << nMotas << ")? ";
            cin >> nMota; cin.ignore();
            if (nMota < 1 || nMota > nMotas)
            {
                cout << "Número de motas entre 1 e " << nMotas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nMota < 1 || nMota > nMotas);

        (*motas)[nMota - 1].mostraMota();
        int uVendidas = 0, nUnidades = 0;
        nUnidades = (*motas)[nMota - 1].getNumUnidades();
        cout << "Quantas unidades vendeu? ";
        cin >> uVendidas; cin.ignore();
        nUnidades -= uVendidas;
        (*motas)[nMota - 1].setNumUnidades(nUnidades);
        (*motas)[nMota - 1].mostraMota();
        cout << "Venda efetuada com sucesso!" << endl;
        pausa();
    }
}

void reporMota(vector<Mota>* motas)
{
    system("cls");
    header();
    int nMota = 0;
    int nMotas = motas->size();
    if (nMotas <= 0)
    {
        cout << "Não existem motas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o mota a repor (1-" << nMotas << ")? ";
            cin >> nMota; cin.ignore();
            if (nMota < 1 || nMota > nMotas)
            {
                cout << "Número de motas entre 1 e " << nMotas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nMota < 1 || nMota > nMotas);

        (*motas)[nMota - 1].mostraMota();
        int uRepostas = 0, nUnidades = 0;
        nUnidades = (*motas)[nMota - 1].getNumUnidades();
        cout << "Quantas unidades vai repor? ";
        cin >> uRepostas; cin.ignore();
        nUnidades += uRepostas;
        (*motas)[nMota - 1].setNumUnidades(nUnidades);
        (*motas)[nMota - 1].mostraMota();
        cout << "Reposição efetuada com sucesso!" << endl;
        pausa();
    }
}

void apagarMota(vector<Mota>* motas)
{
    system("cls");
    header();
    int nMota = 0;
    int nMotas = motas->size();
    cout << "Número de motas: " << nMotas << "." << endl;
    if (nMotas <= 0)
    {
        cout << "Não existem motas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o mota a apagar (1-" << nMotas << ")? ";
            cin >> nMota; cin.ignore();
            if (nMota < 1 || nMota > nMotas)
            {
                cout << "Número de motas entre 1 e " << nMotas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nMota < 1 || nMota > nMotas);

        motas->erase(motas->begin() + (nMota - 1));
        Mota::numMotas--;
        cout << "Mota apagado com sucesso!" << endl;
        pausa();
    }
}

void guardaFicheiroMota(vector<Mota> motas)
{
    string caminho = "", nomeFicheiro = "motas.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;
    Mota mota;
    // 4. Criar o objeto e abrir o ficheiro
    //ofstream ficheiro4(nomeCompleto.c_str());
    ofstream ficheiro;
    ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita

    if (!ficheiro) {
        cout << "Ficheiro não foi aberto!" << endl;
        pausa();
    }
    else {
        // 4. Escrever mensagem
        int nMotas = motas.size();
        cout << "Número de motas: " << nMotas << "." << endl;
        if (nMotas <= 0)
        {
            cout << "Não existem motas!" << endl;
            pausa();
        }
        else
        {
            cout << "-> Gravação dos motas: \n";
            for (int cMota = 0; cMota < nMotas; cMota++)
                ficheiro << motas[cMota];
            // 5. Fechar o ficheiro
            ficheiro.close();
            cout << "Dados gravados com sucesso!" << endl;
            pausa();
        }
    }

} // Fim da função "guardaFicheiroMota()".

//****************************************************************
//* LerFicheiro
//****************************************************************
void lerFicheiroMota(vector<Mota>* motas)
{

    string caminho = "", nomeFicheiro = "motas.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    motas->erase(motas->begin(), motas->end());

    cout << "-> Leitura dos motas: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
    ifstream ficheiroL;
    ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary

    if (ficheiroL.is_open()) {

        Mota mota;
        // 4. Leitura dos objetos
        int contaMotas = 0;
        while (ficheiroL >> mota && !ficheiroL.eof())
        {
            motas->push_back(mota);
            contaMotas++;
            cout << "Mota " << contaMotas << ": " << endl;
        }
        // 5. Fechar o ficheiro
        ficheiroL.close();
        cout << endl;
    }
}

//------------------------------------ FIM FUNÇÕES MOTA ---------------------------------------

//------------------------------------   FUNÇÕES FORNECEDOR   ---------------------------------
void menuFornecedor()
{
    char escolha = '\0';
    bool queroSair = false;
    const int NUMOPCOES = 6;

    do
    {
        system("cls");
        header();
        opcoesFornecedor();
        lerFicheiroForn(&fornecedores);
        escolha = obtemEscolhaForn(escolha, NUMOPCOES);
        queroSair = processaEscolhaForn(&fornecedores, escolha, queroSair, NUMOPCOES);
    } while (!queroSair);
}

void opcoesFornecedor()
{
    cout << "*                                                                  *" << endl;
    cout << "*                        A. Inserir Fornecedor.                    *" << endl;
    cout << "*                        B. Listar Fornecedor.                     *" << endl;
    cout << "*                        C. Pesquisar Fornecedor.                  *" << endl;
    cout << "*                        D. Atualizar Fornecedor.                  *" << endl;
    cout << "*                        E. Apagar Fornecedor.                     *" << endl;
    cout << "*                        F. Sair do programa.                      *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
}

char obtemEscolhaForn(char escolha, int numOp)
{
    char ultimaOp = (char)(numOp + 64); // "A" - ASCII 65	
    cout << "Qual a sua escolha (A-" << ultimaOp << ")? ";
    cin >> escolha; cin.ignore();
    return escolha;
}

bool processaEscolhaForn(vector<Fornecedor>* fornecedores, char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a': inserirFornecedor(fornecedores);
        guardaFicheiroForn(*fornecedores);
        break;
    case 'B': case 'b': listarfornecedores(*fornecedores);
        break;
    case 'C': case 'c': pesquisarFornecedor(*fornecedores);
        break;
    case 'D': case 'd': atualizarFornecedor(fornecedores);
        guardaFicheiroForn(*fornecedores);
        break;
    case 'E': case 'e': apagarFornecedor(fornecedores);
        guardaFicheiroForn(*fornecedores);
        break;
    case 'F': case 'f':
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch"

    return queroSair;
}

void inserirFornecedor(vector<Fornecedor>* fornecedores)
{
    system("cls");
    header();
    Fornecedor* fornecedor;
    fornecedor = new Fornecedor;
    fornecedor->novoFornecedor();

    int nfornecedores = fornecedores->size();
    cout << "Número de fornecedores: " << nfornecedores << "." << endl;

    fornecedores->push_back(*fornecedor);
    Fornecedor::numFornecedores++;
    //fornecedores.insert(fornecedores.begin()+nfornecedores, Fornecedor);
    fornecedores->at(nfornecedores).mostraFornecedor();
    nfornecedores = fornecedores->size();
    cout << "Número de fornecedores: " << nfornecedores << "." << endl;
    cout << "Fornecedor inserido com sucesso!" << endl;
    pausa();
} // Fim da função "InserirFornecedor()".

//**********************************************
//*  Função apagarFornecedor()"
//*    Entradas: vector<Fornecedor>& fornecedores, int numFornecedores.
//*    Saida(s): não tem.
//**********************************************
void apagarFornecedor(vector<Fornecedor>* fornecedores)
{
    system("cls");
    header();
    int nFornecedor = 0;
    int nfornecedores = fornecedores->size();
    cout << "Número de fornecedores: " << nfornecedores << "." << endl;
    if (nfornecedores <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o Fornecedor a apagar (1-" << nfornecedores << ")? ";
            cin >> nFornecedor; cin.ignore();
            if (nFornecedor < 1 || nFornecedor > nfornecedores)
            {
                cout << "Número de fornecedores entre 1 e " << nfornecedores << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nFornecedor < 1 || nFornecedor > nfornecedores);

        fornecedores->erase(fornecedores->begin() + (nFornecedor - 1));
        Fornecedor::numFornecedores--;
        cout << "Fornecedor apagado com sucesso!" << endl;
        pausa();
    }


} // Fim da função "apagarFornecedor()".


//**********************************************
//*  Função pesquisarFornecedor()"
//*    Entradas: vector<Fornecedor> *fornecedores, int numFornecedores.
//*    Saida(s): não tem.
//**********************************************
void pesquisarFornecedor(vector<Fornecedor> fornecedores)
{
    system("cls");
    header();
    int nFornecedor = 0;
    int nfornecedores = fornecedores.size();
    if (nfornecedores <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o Fornecedor a pesquisar (1-" << nfornecedores << ")? ";
            cin >> nFornecedor; cin.ignore();
            if (nFornecedor < 1 || nFornecedor > nfornecedores)
            {
                cout << "Número de fornecedores entre 1 e " << nfornecedores << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nFornecedor < 1 || nFornecedor > nfornecedores);

        fornecedores[nFornecedor - 1].mostraFornecedor();
        pausa();
    }
} // Fim da função "pesquisarFornecedor()".

//**********************************************
//*  Função atualizarFornecedor()"
//*    Entradas: vector<Fornecedor> *fornecedores, int numFornecedores.
//*    Saida(s): não tem.
//**********************************************
void atualizarFornecedor(vector<Fornecedor>* fornecedores)
{
    system("cls");
    header();
    int nFornecedor = 0;
    int nfornecedores = fornecedores->size();
    if (nfornecedores <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o Fornecedor a atualizar (1-" << nfornecedores << ")? ";
            cin >> nFornecedor; cin.ignore();
            if (nFornecedor < 1 || nFornecedor > nfornecedores)
            {
                cout << "Número de fornecedores entre 1 e " << nfornecedores << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nFornecedor < 1 || nFornecedor > nfornecedores);
        (*fornecedores)[nFornecedor - 1].mostraFornecedor();
        cout << "O que quer alterar? Tudo(1) ou um campo(2)? " << endl;
        char escolha = '\0';
        cin >> escolha;

        if (escolha == '2')
        {
            cout << "1 - Nome\n2 - Morada\n3 - Email\n4 - Contacto\n5 - NIF\n6 - Marca" << endl;
            cin >> escolha;
            switch (escolha)
            {
            case '1':
                cout << "Nome: "; (*fornecedores)[nFornecedor - 1].leNome();
                break;
            case '2':
                cout << "Morada: "; (*fornecedores)[nFornecedor - 1].leMorada();
                break;
            case '3':
                cout << "Email: "; (*fornecedores)[nFornecedor - 1].leEmail();
                break;
            case '4':
                cout << "Contacto: "; (*fornecedores)[nFornecedor - 1].leContacto();
                break;
            case '5':
                cout << "NIF: "; (*fornecedores)[nFornecedor - 1].leNIF();
                break;
            case '6':
                cout << "Marca: "; (*fornecedores)[nFornecedor - 1].leMarca();
                break;
            default: cout << "Insira uma opcao correta.";
            }
        }
        else
        {
            (*fornecedores)[nFornecedor - 1].novoFornecedor();
        }

        (*fornecedores)[nFornecedor - 1].mostraFornecedor();
        cout << "Atualização efetuada com sucesso!" << endl;
        pausa();
    }
} // Fim da função "atualizarFornecedor()".

//**************************************************
//* Função "listarfornecedores()"
//* Entrada(s): Fornecedor fornecedores[], int numFornecedores
//* Saida(s): não tem.
//**************************************************
void listarfornecedores(vector<Fornecedor> fornecedores)
{
    system("cls");
    header();
    int nfornecedores = fornecedores.size();
    cout << "Número de fornecedores: " << nfornecedores << "." << endl;
    if (nfornecedores <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        cout << "-> Listagem de fornecedores: \n";
        for (int cFornecedor = 0; cFornecedor < nfornecedores; cFornecedor++)
        {
            cout << "Fornecedor " << cFornecedor + 1 << ": " << endl;
            fornecedores[cFornecedor].mostraFornecedor();
        } // Fim do "for"
        pausa();
    }
}

void guardaFicheiroForn(vector<Fornecedor> fornecedores)
{
    string caminho = "", nomeFicheiro = "fornecedor.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;
    Fornecedor Fornecedor;
    // 4. Criar o objeto e abrir o ficheiro
    //ofstream ficheiro4(nomeCompleto.c_str());
    ofstream ficheiro;
    ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita

    if (!ficheiro) {
        cout << "Ficheiro não foi aberto!" << endl;
        pausa();
    }
    else {
        // 4. Escrever mensagem
        int nfornecedores = fornecedores.size();
        cout << "Número de fornecedores: " << nfornecedores << "." << endl;
        if (nfornecedores <= 0)
        {
            cout << "Não existem fornecedores!" << endl;
            pausa();
        }
        else
        {
            cout << "-> Gravação dos fornecedores: \n";
            for (int cFornecedor = 0; cFornecedor < nfornecedores; cFornecedor++)
                ficheiro << fornecedores[cFornecedor];
            // 5. Fechar o ficheiro
            ficheiro.close();
            cout << "Dados gravados com sucesso!" << endl;
            pausa();
        }
    }

} // Fim da função "guardaFicheiro()".

//****************************************************************
//* LerFicheiro
//****************************************************************
void lerFicheiroForn(vector<Fornecedor>* fornecedores)
{

    string caminho = "", nomeFicheiro = "fornecedor.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    fornecedores->erase(fornecedores->begin(), fornecedores->end());

    cout << "-> Leitura dos fornecedores: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
    ifstream ficheiroL;
    ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary

    if (ficheiroL.is_open()) {

        Fornecedor fornecedor;
        // 4. Leitura dos objetos
        int contaFornecedores = 0;
        while (ficheiroL >> fornecedor && !ficheiroL.eof())
        {
            fornecedores->push_back(fornecedor);
            contaFornecedores++;
            cout << "Fornecedor " << contaFornecedores << ": " << endl;
        }
        // 5. Fechar o ficheiro
        ficheiroL.close();
        cout << endl;
    }
}
//------------------------------------ FIM FUNÇÕES FORNECEDOR ---------------------------------

//------------------------------------   FUNÇÕES ENCOMENDA    ---------------------------------
void menuEncomenda()
{
    char escolha = '\0';
    bool queroSair = false;
    const int NUMOPCOES = 6;
    do
    {
        system("cls");
        header();
        opcoesEncomenda();
        lerFicheiroEnc(&encomendas);
        escolha = obtemEscolhaEnc(escolha, NUMOPCOES);
        queroSair = processaEscolhaEnc(&encomendas, escolha, queroSair, NUMOPCOES);
    } while (!queroSair);
}

void opcoesEncomenda()
{
    cout << "*                                                                  *" << endl;
    cout << "*                        A. Inserir Encomenda.                     *" << endl;
    cout << "*                        B. Listar Encomenda.                      *" << endl;
    cout << "*                        C. Pesquisar Encomenda.                   *" << endl;
    cout << "*                        D. Atualizar Encomenda.                   *" << endl;
    cout << "*                        E. Apagar Encomenda.                      *" << endl;
    cout << "*                        F. Sair do programa.                      *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
}

char obtemEscolhaEnc(char escolha, int numOp)
{
    char ultimaOp = (char)(numOp + 64); // "A" - ASCII 65	
    cout << "Qual a sua escolha (A-" << ultimaOp << ")? ";
    cin >> escolha; cin.ignore();
    return escolha;
}

bool processaEscolhaEnc(vector<Encomenda>* encomendas, char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a': inserirEncomenda(encomendas);
        guardaFicheiroEnc(*encomendas);
        break;
    case 'B': case 'b': listarEncomendas(*encomendas);
        break;
    case 'C': case 'c': pesquisarEncomenda(*encomendas);
        break;
    case 'D': case 'd': atualizarEncomenda(encomendas);
        guardaFicheiroEnc(*encomendas);
        break;
    case 'E': case 'e': apagarEncomenda(encomendas);
        guardaFicheiroEnc(*encomendas);
        break;
    case 'F': case 'f':
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch"

    return queroSair;
} // Fim da Função "processaEscolha()".


//**********************************************
//*  Função inserirEncomenda()"
//*    Entradas: vector<Encomenda>& encomendas, int numEncomendas.
//*    Saida(s): não tem.
//**********************************************
void inserirEncomenda(vector<Encomenda>* encomendas)
{
    system("cls");
    header();
    Encomenda* encomenda;
    encomenda = new Encomenda;
    encomenda->novaEncomenda();

    int nEncomendas = encomendas->size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;

    encomendas->push_back(*encomenda);
    Encomenda::numEncomendas++;
    //encomendas.insert(encomendas.begin()+nEncomendas, Encomenda);
    encomendas->at(nEncomendas).mostraEncomenda();
    nEncomendas = encomendas->size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;
    cout << "Encomenda inserido com sucesso!" << endl;
    pausa();
} // Fim da função "InserirEncomenda()".

//**********************************************
//*  Função apagarEncomenda()"
//*    Entradas: vector<Encomenda>& encomendas, int numEncomendas.
//*    Saida(s): não tem.
//**********************************************
void apagarEncomenda(vector<Encomenda>* encomendas)
{
    system("cls");
    header();
    int nEncomenda = 0;
    int nEncomendas = encomendas->size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o Encomenda a apagar (1-" << nEncomendas << ")? ";
            cin >> nEncomenda; cin.ignore();
            if (nEncomenda < 1 || nEncomenda > nEncomendas)
            {
                cout << "Número de encomendas entre 1 e " << nEncomendas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nEncomenda < 1 || nEncomenda > nEncomendas);

        encomendas->erase(encomendas->begin() + (nEncomenda - 1));
        Encomenda::numEncomendas--;
        cout << "Encomenda apagado com sucesso!" << endl;
        pausa();
    }


} // Fim da função "apagarEncomenda()".


//**********************************************
//*  Função pesquisarEncomenda()"
//*    Entradas: vector<Encomenda> *encomendas, int numEncomendas.
//*    Saida(s): não tem.
//**********************************************
void pesquisarEncomenda(vector<Encomenda> encomendas)
{
    system("cls");
    header();
    int nEncomenda = 0;
    int nEncomendas = encomendas.size();
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o Encomenda a pesquisar (1-" << nEncomendas << ")? ";
            cin >> nEncomenda; cin.ignore();
            if (nEncomenda < 1 || nEncomenda > nEncomendas)
            {
                cout << "Número de encomendas entre 1 e " << nEncomendas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nEncomenda < 1 || nEncomenda > nEncomendas);

        encomendas[nEncomenda - 1].mostraEncomenda();
        pausa();
    }
} // Fim da função "pesquisarEncomenda()".

//**********************************************
//*  Função atualizarEncomenda()"
//*    Entradas: vector<Encomenda> *encomendas, int numEncomendas.
//*    Saida(s): não tem.
//**********************************************
void atualizarEncomenda(vector<Encomenda>* encomendas)
{
    system("cls");
    header();
    int nEncomenda = 0;
    int nEncomendas = encomendas->size();
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o Encomenda a atualizar (1-" << nEncomendas << ")? ";
            cin >> nEncomenda; cin.ignore();
            if (nEncomenda < 1 || nEncomenda > nEncomendas)
            {
                cout << "Número de encomendas entre 1 e " << nEncomendas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nEncomenda < 1 || nEncomenda > nEncomendas);
        (*encomendas)[nEncomenda - 1].mostraEncomenda();
        cout << "O que quer alterar? Tudo(1) ou só um campo(2)? " << endl;
        char escolha = '\0';
        cin >> escolha;

        if (escolha == '2')
        {
            cout << "1 - Código\n2 - Data\n3 - Fornecedor\n4 - Estado\n5 - Mota" << endl;
            cin >> escolha;
            switch (escolha)
            {
            case '1':
                cout << "Código: "; (*encomendas)[nEncomenda - 1].leCodigo();
                break;
            case '2':
                cout << "Data: "; (*encomendas)[nEncomenda - 1].leData();
                break;
            case '3':
                cout << "Fornecedor: "; (*encomendas)[nEncomenda - 1].leFornecedor();
                break;
            case '4':
                cout << "Estado: "; (*encomendas)[nEncomenda - 1].leStatus();
                break;
            case '5':
                cout << "Mota: "; (*encomendas)[nEncomenda - 1].leAtualizaMota();
                break;
            default: cout << "Insira uma opcao correta.";
            }
        }
        else 
        {
            (*encomendas)[nEncomenda - 1].novaEncomenda();
        }

        (*encomendas)[nEncomenda - 1].mostraEncomenda();
        cout << "Atualização efetuada com sucesso!" << endl;
        pausa();
    }
} // Fim da função "atualizarEncomenda()".

//**************************************************
//* Função "listarEncomendas()"
//* Entrada(s): Encomenda encomendas[], int numEncomendas
//* Saida(s): não tem.
//**************************************************
void listarEncomendas(vector<Encomenda> encomendas)
{
    system("cls");
    header();
    int nEncomendas = encomendas.size();
    cout << "\nNúmero de encomendas: " << nEncomendas << "." << endl;
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas!" << endl;
        pausa();
    }
    else
    {
        cout << "\n-> Listagem de encomendas: \n";
        for (int cEncomenda = 0; cEncomenda < nEncomendas; cEncomenda++)
        {
            cout << "\nEncomenda " << cEncomenda + 1 << ": ";
            cout << " -> "<<endl; 
            encomendas[cEncomenda].mostraEncomenda();
        } // Fim do "for"
        pausa();
    }
} // Fim da função "listarEncomendas()".

//****************************************************************
//* GravarFicheiro
//****************************************************************
void guardaFicheiroEnc(vector<Encomenda> encomendas)
{
    string caminho = "", nomeFicheiro = "encomenda.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "\nNome do ficheiro: " << nomeCompleto.c_str() << "." << endl;
    Encomenda encomenda;
    // 4. Criar o objeto e abrir o ficheiro
    //ofstream ficheiro4(nomeCompleto.c_str());
    ofstream ficheiro;
    ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita

    if (!ficheiro) {
        cout << "Ficheiro não foi aberto!" << endl;
        pausa();
    }
    else {
        // 4. Escrever mensagem
        int nEncomendas = encomendas.size();
        cout << "Número de encomendas: " << nEncomendas << "." << endl;
        if (nEncomendas <= 0)
        {
            cout << "Não existem encomendas!" << endl;
            pausa();
        }
        else
        {
            cout << "\n-> Gravação dos encomendas: \n";
            for (int cEncomenda = 0; cEncomenda < nEncomendas; cEncomenda++)
                ficheiro << encomendas[cEncomenda];
            // 5. Fechar o ficheiro
            ficheiro.close();
            cout << "Dados gravados com sucesso!" << endl;
            pausa();
        }
    }

} // Fim da função "guardaFicheiroEnc()".

//****************************************************************
//* LerFicheiro
//****************************************************************
void lerFicheiroEnc(vector<Encomenda>* encomendas)
{

    string caminho = "", nomeFicheiro = "encomenda.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "\nNome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    encomendas->erase(encomendas->begin(), encomendas->end());

    cout << "\n-> Leitura dos encomendas: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
    ifstream ficheiroL;
    ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary

    if (ficheiroL.is_open()) {

        Encomenda encomenda;
        // 4. Leitura dos objetos
        int contaEncomendas = 0;
        while (ficheiroL >> encomenda && !ficheiroL.eof())
        {
            encomendas->push_back(encomenda);
            contaEncomendas++;
            cout << "Encomenda " << contaEncomendas << ": " << endl;
        }
        // 5. Fechar o ficheiro
        ficheiroL.close();
        cout << endl;
    }
}
//------------------------------------ FIM FUNÇÕES ENCOMENDA  ---------------------------------

