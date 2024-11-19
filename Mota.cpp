#pragma once
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
#include <regex>
using namespace std;

class Mota
{
private:
    string marca;
    string modelo;
    string cor;
    string caixa;
    int km;
    string combustivel;
    string anoMesRegisto;
    int potencia;
    int cilindrada;
    bool revisaoFeita;
    int numUnidades;
    int quebra;
    float preco;

public:
    //****************************************************
    //* Função encripta()
    //****************************************************
    string  encripta(string mensagemO, int desl)
    {
        const int MAXCHARS = 100;
        char mensagem[MAXCHARS];
        for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
            mensagem[cLetra] = '\0';

        strcpy_s(mensagem, mensagemO.c_str());

        for (int cLetra = 0; cLetra < mensagemO.length(); cLetra++)
        {
            int valor = (int)mensagem[cLetra] + desl;
            if (((valor) > 90 && isupper(mensagem[cLetra]))
                || ((valor) > 122 && islower(mensagem[cLetra]))
                )
                valor = valor - 26;
            if (mensagem[cLetra] == '.')
                mensagem[cLetra] = '.';
            else if (!isalpha(mensagem[cLetra]))
                mensagem[cLetra] = mensagem[cLetra];
            else
                mensagem[cLetra] = valor;
        }
        //cout<<mensagem;	
        return mensagem;
    }


    //****************************************************
    //* Função desencripta()
    //****************************************************
    string  desencripta(string mensagemE, int desl)
    {
        const int MAXCHARS = 100;
        char mensagem[MAXCHARS];
        for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
            mensagem[cLetra] = '\0';

        strcpy_s(mensagem, mensagemE.c_str());

        for (int cLetra = 0; cLetra < mensagemE.length(); cLetra++)
        {
            int valor = (int)mensagem[cLetra] - desl;
            if (((valor) < 65 && isupper(mensagem[cLetra]))
                || ((valor) < 97 && islower(mensagem[cLetra]))
                )

                valor = valor + 26;
            if (mensagem[cLetra] == '.')
                mensagem[cLetra] = '.';
            else if (!isalpha(mensagem[cLetra]))
                mensagem[cLetra] = mensagemE[cLetra];
            else
                mensagem[cLetra] = valor;
        }
        //cout<<mensagem;	
        return mensagem;
    }

    char* desencriptaII(char mensagemE[], int desl)
    {
        const int MAXCHARS = 100;
        char mensagem[MAXCHARS];
        for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
            mensagem[cLetra] = '\0';

        strcpy_s(mensagem, mensagemE);

        for (int cLetra = 0; cLetra < strlen(mensagemE); cLetra++)
        {
            int valor = (int)mensagem[cLetra] - desl;
            if (((valor) < 65 && isupper(mensagem[cLetra]))
                || ((valor) < 97 && islower(mensagem[cLetra]))
                )
                valor = valor + 26;
            if (mensagem[cLetra] == '.')
                mensagem[cLetra] = '.';
            else if (!isalpha(mensagem[cLetra]))
                mensagem[cLetra] = mensagemE[cLetra];
            else
                mensagem[cLetra] = valor;
        }
        //cout<<mensagem;	
        return mensagem;
    }

    string encriptaBool(bool valor, int desl) {
        string boolStr = valor ? "sim" : "não";  // True -> "true", False -> "false"
        return encripta(boolStr, desl);  // Usar a função encripta para encriptar
    }

    bool desencriptaBool(string mensagemEncriptada, int desl) {
        string boolStr = desencripta(mensagemEncriptada, desl);  // Desencriptar a mensagem
        return (boolStr == "sim");  // Se for "sim", retorna true; se não, retorna "não"
    }

    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    string getCor() { return cor; }
    string getCaixa() { return caixa; }
    int getKm() { return km; }
    string getCombustivel() { return combustivel; }
    string getAnoMesRegisto() { return anoMesRegisto; }
    int getPotencia() { return potencia; }
    int getCilindrada() { return cilindrada; }
    bool getRevisaoFeita() { return revisaoFeita; }
    int getNumUnidades() { return numUnidades; }
    int getQuebra() { return quebra; }
    float getPreco() { return preco; }

    void setMarca(string marca) { this->marca = marca; }
    void setModelo(string modelo) { this->modelo = modelo; }
    void setCor(string cor) { this->cor = cor; }
    void setCaixa(string caixa) { this->caixa = caixa; }
    void setKm(int km) { this->km = km; }
    void setCombustivel(string combustivel) { this->combustivel = combustivel; }
    void setAnoMesRegisto(string anoMesRegisto) { this->anoMesRegisto = anoMesRegisto; }
    void setPotencia(int potencia) { this->potencia = potencia; }
    void setCilindrada(int cilindrada) { this->cilindrada = cilindrada; }
    void setRevisaoFeita(bool revisaoFeita) { this->revisaoFeita = revisaoFeita; }
    void setNumUnidades(int numUnidades) { this->numUnidades = numUnidades; }
    void setQuebra(int quebra) { this->quebra = quebra; }
    void setPreco(float preco) { this->preco = preco; }

    static int numMotas;

    Mota()
    {
        marca = "";
        modelo = "";
        cor = "";
        caixa = "";
        km = 0;
        combustivel = "";
        anoMesRegisto = "";
        potencia = 0;
        cilindrada = 0;
        revisaoFeita = true;
        numUnidades = 0;
        quebra = 0;
        preco = 0;
    }

    Mota(string marca)
    {
        this->marca = marca;
        modelo = "";
        cor = "";
        caixa = "";
        km = 0;
        combustivel = "";
        anoMesRegisto = "";
        potencia = 0;
        cilindrada = 0;
        revisaoFeita = true;
        numUnidades = 0;
        quebra = 0;
        preco = 0;
    }

    Mota(string marca, string modelo)
    {
        this->marca = marca;
        this->modelo = modelo;
        cor = "";
        caixa = "";
        km = 0;
        combustivel = "";
        anoMesRegisto = "";
        potencia = 0;
        cilindrada = 0;
        revisaoFeita = true;
        numUnidades = 0;
        quebra = 0;
        preco = 0;
    };

    Mota(string marca, string modelo, string cor)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->cor = cor;
        caixa = "";
        km = 0;
        combustivel = "";
        anoMesRegisto = "";
        potencia = 0;
        cilindrada = 0;
        revisaoFeita = true;
        numUnidades = 0;
        quebra = 0;
        preco = 0;
    };

    Mota(string marca, string modelo, string cor, string caixa)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->cor = cor;
        this->caixa = caixa;
        km = 0;
        combustivel = "";
        anoMesRegisto = "";
        potencia = 0;
        cilindrada = 0;
        revisaoFeita = true;
        numUnidades = 0;
        quebra = 0;
        preco = 0;
    };

    Mota(string marca, string modelo, string cor, string caixa, int km, string combustivel)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->cor = cor;
        this->caixa = caixa;
        this->km = km;
        this->combustivel = combustivel;
        anoMesRegisto = "";
        potencia = 0;
        cilindrada = 0;
        revisaoFeita = true;
        numUnidades = 0;
        quebra = 0;
        preco = 0;
    };

    Mota(string marca, string modelo, string cor, string caixa, int km, string combustivel, string anoMesRegisto, int potencia, int cilindrada, bool revisaoFeita, int numUnidades, int quebra, float preco)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->cor = cor;
        this->caixa = caixa;
        this->km = km;
        this->combustivel = combustivel;
        this->anoMesRegisto = anoMesRegisto;
        this->potencia = potencia;
        this->cilindrada = cilindrada;
        this->revisaoFeita = revisaoFeita;
        this->numUnidades = numUnidades;
        this->quebra = quebra;
        this->preco = preco;
    };

    ~Mota() {}

    void leMarca()
    {
        string marca = "";
        bool marcaValida = false;

        cout << "\nInsira a marca: ";

        do {
            fflush(stdin);
            cin >> marca;

            if (marca.empty())
            {
                cout << "Erro: a marca não pode ser vazia!" << endl;
            }
            else
            {
                marcaValida = true;
                setMarca(marca);
            }
        } while (!marcaValida);
    }

    void leModelo() {
        string modelo = "";
        bool modeloValido = false;

        cout << "Insira o modelo: ";

        do {
            cin.ignore();
            cin >> modelo;

            if (modelo.empty())
            {
                cout << "Erro: o modelo não pode ser vazio!" << endl;
            }
            else
            {
                modeloValido = true;
                setModelo(modelo);
            }
        } while (!modeloValido);
    }

    void leCor() {
        string cor = "";
        bool corValida = false;

        cout << "Insira a cor: ";

        do {
            cin.ignore();
            cin >> cor;

            if (cor.empty())
            {
                cout << "Erro: a cor não pode ser vazia!" << endl;
            }
            else
            {
                corValida = true;
                setCor(cor);
            }
        } while (!corValida);
    }

    void leCaixa() {
        char caixa = '\0';
        bool caixaValida = false;
        const string AUTO = "Automatica";
        const string MANUAL = "Manual";
        cout << "Insira o tipo de caixa (1 - Automática / 2 - Manual): ";
        do
        {
            cin.ignore();
            cin >> caixa;
            switch (caixa)
            {
            case '1': setCaixa(AUTO); 
                      caixaValida = true; 
                      break;
            case '2': setCaixa(MANUAL); 
                      caixaValida = true; 
                      break;
            default:
                {
                    cout << "Insira uma opção válida (1 - Automática / 2 - Manual).";
                    break;
                }
            };
        } while (!caixaValida);
    }

    void leKm() {
        string kmString = "";
        cout << "Insira os quilómetros: ";
        bool kmValido = false;
        do
        {
            cin.ignore();
            cin >> kmString;
            if (verificaInputInt(kmString))
            {
                int km = stoi(kmString);
                setKm(km);
                kmValido = true;
            }
            else
            {
                cout << "Insira números por favor.";
            }
        } while (!kmValido);
    }

    void leCombustivel() {
        const string GOTA = "Gasolina";
        const string DIESEL = "Diesel";
        const string ELET = "Elétrico";
        char combustivel = '\0';
        bool combustivelValido = false;

        cout << "Insira o tipo de combustível (1 - Gasolina, 2 - Diesel, 3 - Elétrico): ";

        do
        {
            cin.ignore();
            cin >> combustivel;
            switch (combustivel)
            {
            case '1': setCombustivel(GOTA); 
                      combustivelValido = true; 
                      break;
            case '2': setCombustivel(DIESEL); 
                      combustivelValido = true; 
                      break;
            case '3': setCombustivel(ELET); 
                      combustivelValido = true; 
                      break;
            default: 
            {
                cout << "Insira uma opção válida (1 - Gasolina, 2 - Diesel, 3 - Elétrico).";
                break;
            }
            };

        } while (!combustivelValido);
    }

    void leAnoMesRegisto() {
        string anoMesRegisto = "";
        cout << "Insira o ano/mês de registo (yyyy/mm): ";
        bool dataValida = false;
        
        do
        {
            cin.ignore();
            cin >> anoMesRegisto;
            dataValida = validarData(anoMesRegisto);
            if (!validarData(anoMesRegisto))
            {
                cout << "Insira o ano/mês de registo neste formato (yyyy/mm): ";
            }
        } while (!dataValida);

        setAnoMesRegisto(anoMesRegisto);
    }

    void lePotencia() {
        string potenciaString = "";
        cout << "Insira a potência (cv): ";
        bool potenciaValida = false;
        do
        {
            cin.ignore();
            cin >> potenciaString;
            if (verificaInputInt(potenciaString))
            {
                int potencia = stoi(potenciaString);
                setPotencia(potencia);
                potenciaValida = true;
            }
            else
            {
                cout << "Insira números por favor.";
            }
        } while (!potenciaValida);
    }

    void leCilindrada() {
        string cilindradaString = "";
        cout << "Insira a cilindrada (cm3): ";
        bool cilindradaValida = false;

        do
        {
            cin.ignore();
            cin >> cilindradaString;
            if (verificaInputInt(cilindradaString))
            {
                int cilindrada = stoi(cilindradaString);
                setCilindrada(cilindrada);
                cilindradaValida = true;
            }
            else
            {
                cout << "Insira números por favor.";
            }
        } while (!cilindradaValida);
    }

    void leRevisaoFeita() {
        bool revisaoFeita = true;
        cout << "Revisão feita (S/N): ";
        char escolha = '\0';

        do
        {
            cin.ignore();
            cin >> escolha;
            if (escolha == 'S' || escolha == 's')
            {
                revisaoFeita = true;
            }
            else if (escolha == 'N' || escolha == 'n')
            {
                revisaoFeita = false;
            }
            else
            {
                cout << "Tem de escrever S ou N" << endl;
            }
        } while (escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n');

        setRevisaoFeita(revisaoFeita);
    }

    void leNumUnidades() {
        string numUnidadesString = "";
        cout << "Insira o número de unidades: ";
        bool unidadesValidas = false;

        do {
            cin.ignore();
            cin >> numUnidadesString;
            if (verificaInputInt(numUnidadesString)) {
                int numUnidades = stoi(numUnidadesString);
                setNumUnidades(numUnidades);
                unidadesValidas = true;
            }
            else {
                cout << "Insira números por favor.";
            }
        } while (!unidadesValidas);
    }

    void leQuebra() {
        string quebraString = "";
        cout << "Insira a quebra: ";
        bool quebraValida = false;

        do {
            cin.ignore();
            cin >> quebraString;
            if (verificaInputInt(quebraString)) {
                int quebra = stoi(quebraString);
                setQuebra(quebra);
                quebraValida = true;
            }
            else {
                cout << "Insira números por favor.";
            }
        } while (!quebraValida);
    }

    void lePreco() {
        string precoString = "";
        cout << "Insira o preço: ";
        bool precoValido = false;

        do 
        {
            cin.ignore();
            cin >> precoString;
            if (verificaInputFloat(precoString)) 
            {
                float preco = stof(precoString);
                setPreco(preco);
                precoValido = true;
            }
            else {
                cout << "Insira um valor numérico válido para o preço.";
            }
        } while (!precoValido);
    }

    void mostraMarca() {
        cout << "\nMarca               : " << getMarca() << endl;
    }

    void mostraModelo() {
        cout << "Modelo              : " << getModelo() << endl;
    }

    void mostraCor() {
        cout << "Cor                 : " << getCor() << endl;
    }

    void mostraCaixa() {
        cout << "Caixa               : " << getCaixa() << endl;
    }

    void mostraKm() {
        cout << "Quilometragem       : " << getKm() << endl;
    }

    void mostraCombustivel() {
        cout << "Combustível         : " << getCombustivel() << endl;
    }

    void mostraAnoMesRegisto() {
        cout << "Ano/Mês de Registo  : " << getAnoMesRegisto() << endl;
    }

    void mostraPotencia() {
        cout << "Potência            : " << getPotencia() << endl;
    }

    void mostraCilindrada() {
        cout << "Cilindrada          : " << getCilindrada() << endl;
    }

    void mostraRevisaoFeita() {
        cout << "Revisão Feita       : " << (getRevisaoFeita() ? "Sim" : "Não") << endl;
    }

    void mostraPreco() {
        cout << "Preço               : " << fixed << setprecision(2) << getPreco() << endl;
        cout << "Preço com IVA       : " << fixed << setprecision(2) << obtemPrecoComIVA(getPreco()) << endl;
    }

    void mostraNumUnidades() {
        cout << "Número de Unidades  : " << getNumUnidades() << endl;
    }

    void mostraQuebra() {
        cout << "Quebra              : " << getQuebra() << endl;
    }


    void novaMota()
    {
        leMarca();
        leModelo();
        leCor();
        leCaixa();
        leKm();
        leCombustivel();
        leAnoMesRegisto();
        lePotencia();
        leCilindrada();
        leRevisaoFeita();
        leNumUnidades();
        leQuebra();
        lePreco();
    }

    void mostraMota()
    {
        mostraMarca();
        mostraModelo();
        mostraCor();
        mostraCaixa();
        mostraKm();
        mostraCombustivel();
        mostraAnoMesRegisto();
        mostraPotencia();
        mostraCilindrada();
        mostraRevisaoFeita();
        mostraNumUnidades();
        mostraQuebra();
        mostraPreco();
        cout << endl;
    }

    static float obtemPrecoComIVA(float psi)
    {
        const float IVAMOTA = 0.23;
        return (psi * (1 + IVAMOTA));
    }

    bool verificaInputInt(string numero)
    {
        regex formato(R"(^\d+$)"); // Define a regex para números
        return regex_match(numero, formato);
    }

    bool verificaInputFloat(string decimal)
    {
        regex formato(R"(^\d+$)"); // Define a regex para números
        return regex_match(decimal, formato);
    }

    bool validarData(string data) {
        // Expressão regular para o formato yyyy/mm
        regex formato("^\\d{4}/(0[1-9]|1[0-2])$");
        return regex_match(data, formato);
    }

    friend istream& operator>> (istream& is, Mota& mota)
    {
        char letra = '\0';
        const int DESLOCAMENTO = 3;

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            mota.setMarca(mota.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            mota.setModelo(mota.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            mota.setCor(mota.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            mota.setCaixa(mota.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, mota.desencriptaII(texto, DESLOCAMENTO));
            mota.setKm(atoi(texto));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            mota.setCombustivel(mota.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            mota.setAnoMesRegisto(mota.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, mota.desencriptaII(texto, DESLOCAMENTO));
            mota.setPotencia(atoi(texto));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, mota.desencriptaII(texto, DESLOCAMENTO));
            mota.setCilindrada(atoi(texto));
        }

        {
            const int MAXNOME = 40;
            char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';

            is.getline(texto, MAXNOME, '\n');
            string mensagemEncriptada = string(texto);
            bool revisaoFeita = mota.desencriptaBool(mensagemEncriptada, DESLOCAMENTO);  // Desencriptar o bool
            mota.setRevisaoFeita(revisaoFeita);  // Atribuir o valor booleano ao objeto
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, mota.desencriptaII(texto, DESLOCAMENTO));
            mota.setNumUnidades(atoi(texto));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, mota.desencriptaII(texto, DESLOCAMENTO));
            mota.setQuebra(atoi(texto));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, mota.desencriptaII(texto, DESLOCAMENTO));
            mota.setPreco(atof(texto));
        }

        is.ignore();
        return is;
    }


    //*************************************************************************************
    //* Redefinição do operador "<<"
    //**************************************************************************************
    friend ostream& operator<< (ostream& os, Mota& mota)
    {
        const int DESLOCAMENTO = 3;
        os << mota.encripta(mota.getMarca(), DESLOCAMENTO) << endl;
        os << mota.encripta(mota.getModelo(), DESLOCAMENTO) << endl;
        os << mota.encripta(mota.getCor(), DESLOCAMENTO) << endl;
        os << mota.encripta(mota.getCaixa(), DESLOCAMENTO) << endl;
        os << mota.encripta(to_string(mota.getKm()), DESLOCAMENTO) << endl;
        os << mota.encripta(mota.getCombustivel(), DESLOCAMENTO) << endl;
        os << mota.encripta(mota.getAnoMesRegisto(), DESLOCAMENTO) << endl;
        os << mota.encripta(to_string(mota.getPotencia()), DESLOCAMENTO) << endl;
        os << mota.encripta(to_string(mota.getCilindrada()), DESLOCAMENTO) << endl;
        os << mota.encriptaBool(mota.getRevisaoFeita(), DESLOCAMENTO) << endl;
        os << mota.encripta(to_string(mota.getNumUnidades()), DESLOCAMENTO) << endl;
        os << mota.encripta(to_string(mota.getQuebra()), DESLOCAMENTO) << endl;
        os << mota.encripta(to_string(mota.getPreco()), DESLOCAMENTO) << endl;
        os << endl;
        return os;
    }
};

