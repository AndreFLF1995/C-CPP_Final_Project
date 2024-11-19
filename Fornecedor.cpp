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
#include <regex>
using namespace std;

class Fornecedor
{
private:
    string nome;
    string morada;
    string email;
    string contacto;
    string nif;
    string marca;

public:
    string getNome() { return nome; }
    string getMorada() { return morada; }
    string getEmail() { return email; }
    string getContacto() { return contacto; }
    string getNIF() { return nif; }
    string getMarca() { return marca; }

    void setNome(string nome) { this->nome = nome; }
    void setMorada(string morada) { this->morada = morada; }
    void setEmail(string email) { this->email = email; }
    void setContacto(string contacto) { this->contacto = contacto; }
    void setNIF(string nif) { this->nif = nif; }
    void setMarca(string marca) { this->marca = marca; }

    Fornecedor() {
        nome = "";
        morada = "";
        email = "";
        contacto = "";
        nif = "";
        marca = "";
    }

    Fornecedor(string nome) {
        this->nome = nome;
        morada = "";
        email = "";
        contacto = "";
        nif = "";
        marca = "";
    }

    Fornecedor(string nome, string morada, string email) {
        this->nome = nome;
        this->morada = morada;
        this->email = email;
        contacto = "";
        nif = "";
        marca = "";
    }

    Fornecedor(string nome, string morada, string email, string telefone, string nif) {
        this->nome = nome;
        this->morada = morada;
        this->email = email;
        this->contacto = telefone;
        this->nif = nif;
        marca = "";
    }

    Fornecedor(string nome, string morada, string email, string telefone, string nif, string marca) {
        this->nome = nome;
        this->morada = morada;
        this->email = email;
        this->contacto = telefone;
        this->nif = nif;
        this->marca = marca;
    }

    static int numFornecedores;

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

    bool validaInputString(string input) {
        return !input.empty();
    }

    void leNome() {
        string nome;
        do {
            cout << "Insira o nome do fornecedor: ";
            fflush(stdin);
            cin >> nome;
            if (nome.empty()) {
                cout << "O nome não pode estar vazio. Tente novamente." << endl;
            }
        } while (nome.empty());
        setNome(nome);
    }

    // Função para ler e validar a morada
    void leMorada() {
        string morada;
        do {
            cout << "Insira a morada do fornecedor: ";
            fflush(stdin);
            cin >> morada;
            if (morada.empty()) {
                cout << "A morada não pode estar vazia. Tente novamente." << endl;
            }
        } while (morada.empty());
        setMorada(morada);
    }

    // Função para ler e validar o email (simplificação de validação)
    void leEmail() {
        string email;
        bool emailValido = false;
        do {
            cout << "Insira o email do fornecedor: ";
            cin.ignore();
            cin >> email;

            if (validarEmail(email)) {
                cout << "Email válido!" << endl;
                setEmail(email);
                emailValido = true;
            }
            else {
                cout << "Formato de email inválido!" << endl;
            }
        } while (!emailValido);
    }

    // Função para ler e validar o contacto (apenas números)
    void leContacto() {
        string contacto;
        bool contactoValido = false;
        do {
            cout << "Insira o contacto do fornecedor (apenas números): ";
            fflush(stdin);
            cin >> contacto;
            
            if (validarTelefone(contacto)) {
                cout << "Número de telefone válido!" << endl;
                setContacto(contacto);
                contactoValido = true;
            }
            else {
                cout << "Formato de número de telefone inválido!" << endl;
            }
        } while (!contactoValido);
    }

    // Função para ler e validar o NIF (apenas números e tamanho 9)
    void leNIF() {
        string nif;
        bool nifValido = false;
        do {
            cout << "Insira o NIF do fornecedor (apenas números): ";
            fflush(stdin);
            cin >> nif;

            if (validarNif(nif)) {
                cout << "Número de NIF válido!" << endl;
                setNIF(nif);
                nifValido = true;
            }
            else {
                cout << "Formato de número de NIF inválido!" << endl;
            }
        } while (!nifValido);
    }

    // Função para ler e validar a categoria (não vazia)
    void leMarca() {
        string marca;
        do {
            cout << "Insira a marca do fornecedor (Honda, BMW, etc...): ";
            fflush(stdin);
            cin >> marca;
            if (marca.empty()) {
                cout << "A marca não pode estar vazia. Tente novamente." << endl;
            }
        } while (marca.empty());
        setMarca(marca);
    }

    void mostraNome() {
        cout << "Nome       : " << getNome() << endl;
    }

    void mostraMorada() {
        cout << "Morada     : " << getMorada() << endl;
    }

    void mostraEmail() {
        cout << "Email      : " << getEmail() << endl;
    }

    void mostraContacto() {
        cout << "Contacto   : " << getContacto() << endl;
    }

    void mostraNIF() {
        cout << "NIF        : " << getNIF() << endl;
    }

    void mostraMarca() {
        cout << "Marca      : " << getMarca() << endl;
    }

    void novoFornecedor()
    {
        leNome();
        leMorada();
        leEmail();
        leContacto();
        leNIF();
        leMarca();
    }

    void mostraFornecedor()
    {
        mostraNome();
        mostraMorada();
        mostraEmail();
        mostraContacto();
        mostraNIF();
        mostraMarca();
    }

    bool validarTelefone(string telefone) {
        regex formato("^(2\\d{8}|9[1623]\\d{7})$");
        return regex_match(telefone, formato);
    }

    bool validarNif(string nif) {
        regex formato("^\\d{9}$");
        return regex_match(nif, formato);
    }

    bool validarEmail(string email) {
        // Expressão regular para validar o formato de email fornecido
        regex formato("[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?");
        return regex_match(email, formato);
    }

    friend istream& operator>> (istream& is, Fornecedor& forn)
    {
        char letra = '\0';
        const int DESLOCAMENTO = 3;

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            forn.setNome(forn.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            forn.setMorada(forn.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            forn.setContacto(forn.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            forn.setEmail(forn.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            forn.setNIF(forn.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            forn.setMarca(forn.desencripta(string(texto), DESLOCAMENTO));
        }

        is.ignore();
        return is;
    }


    //*************************************************************************************
    //* Redefinição do operador "<<"
    //**************************************************************************************
    friend ostream& operator<< (ostream& os, Fornecedor& forn)
    {
        const int DESLOCAMENTO = 3;
        os << forn.encripta(forn.getNome(), DESLOCAMENTO) << endl;
        os << forn.encripta(forn.getMorada(), DESLOCAMENTO) << endl;
        os << forn.encripta(forn.getContacto(), DESLOCAMENTO) << endl;
        os << forn.encripta(forn.getEmail(), DESLOCAMENTO) << endl;
        os << forn.encripta(forn.getNIF(), DESLOCAMENTO) << endl;
        os << forn.encripta(forn.getMarca(), DESLOCAMENTO) << endl;
        os << endl;
        return os;
    }
};


