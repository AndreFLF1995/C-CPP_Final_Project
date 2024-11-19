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
#include <limits> // Para verificar erros de input
#include <sstream>
#include <regex>
#include "Mota.cpp"
using namespace std;

class Encomenda
{
private:
    string codigo;
    string data;
    string nomeFornecedor;
    string nifFornecedor;
    vector<Mota> motas;  // Várias motas associadas à encomenda
    string status;
    float valorTotal;

public:
    // Getters e Setters
    string getCodigo() { return codigo; }
    void setCodigo(string codigo) { this->codigo = codigo; }

    string getData() { return data; }
    void setData(string data) { this->data = data; }

    string getNomeFornecedor() { return nomeFornecedor; }
    void setNomeFornecedor(string fornecedor) { this->nomeFornecedor = fornecedor; }

    string getNifFornecedor() { return nifFornecedor; }
    void setNifFornecedor(string fornecedor) { this->nifFornecedor = fornecedor; }

    vector<Mota> getMotas() { return motas; }
    void setMotas(vector<Mota> motas) { this->motas = motas; }

    float getValorTotal() { return valorTotal; }
    void setValorTotal(float valorTotal) { this->valorTotal = valorTotal; }

    string getStatus() { return status; }
    void setStatus(string status) { this->status = status; }

    // 5 Construtores
    Encomenda()
    {
        codigo = "";
        data = "";
        nomeFornecedor = "";
        nifFornecedor = "";
        status = "";
        valorTotal = 0;
    }

    Encomenda(string codigo)
    {
        this->codigo = codigo;
        data = "";
        nomeFornecedor = "";
        nifFornecedor = "";
        status = "";
        valorTotal = 0;
    }

    Encomenda(string codigo, string data)
    {
        this->codigo = codigo;
        this->data = data;
        nomeFornecedor = "";
        nifFornecedor = "";
        status = "";
        valorTotal = 0;
    }

    Encomenda(string codigo, string data, string nomeFornecedor)
    {
        this->codigo = codigo;
        this->data = data;
        this->nomeFornecedor = nomeFornecedor;
        nifFornecedor = "";
        status = "";
        valorTotal = 0;
    }

    Encomenda(string codigo, string data, string nomeFornecedor, string nifFornecedor, string status, float valorTotal)
    {
        this->codigo = codigo;
        this->data = data;
        this->nomeFornecedor = nomeFornecedor;
        this->nifFornecedor = nifFornecedor;
        this->status = status;
        this->valorTotal = valorTotal;
    }

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

    static int numEncomendas;

    void leCodigo() {
        string codigo;
        bool codigoValido = false;
        do {
            cout << "Insira o código da encomenda (Ex. AA-00): ";
            getline(cin, codigo);

            if (codigo.empty()) 
            {
                cout << "Erro: o código não pode ser vazio!" << endl;
            }
            else if (validarFormato(codigo)) 
            {
                cout << "Formato válido!" << std::endl;
                setCodigo(codigo);
                codigoValido = true;
            }
            else 
            {
                std::cout << "Formato inválido! Deve inserir duas letras maiúsculas, um hífen e dois números (XX-00)" << std::endl;
            }
        } while (!codigoValido);
    }

    // Método para ler a data com validação
    void leData() {
        string data;
        bool dataValida = false;
        do {
            cout << "Insira a data da encomenda (formato DD/MM/AAAA): ";
            getline(cin, data);
            if (data.empty()) {
                cout << "Erro: a data não pode ser vazia!" << endl;
            }
            dataValida = validaData(data);
        } while (!dataValida);
        setData(data);
    }

    // Método para ler o status com validação
    void leStatus() {
        char status = '\0';
        const string ABERTA = "Aberta";
        const string TRAN = "Em Trânsito";
        const string ENTRE = "Entregue";
        bool statusValido = false;

        cout << "Insira o status da encomenda (não vazio, 1 - Aberta, 2 - Em Trânsito, 3 - Entregue): ";
        do
        {
            cin.ignore();
            cin >> status;

            switch (status)
            {
            case '1': setStatus(ABERTA);
                      statusValido = true; 
                      break;
            case '2': setStatus(TRAN);
                      statusValido = true; 
                      break;
            case '3': setStatus(ENTRE);
                      statusValido = true; 
                      break;
            default: cout << "Insira uma das três opções: 1 - Aberta, 2 - Em Trânsito, 3 - Entregue.";
            };
        } while (!statusValido);
    }

    void leFornecedor()
    {
        string nomeFornecedor = "";
        string nifFornecedor = "";

        cout << "Insira o nome do fornecedor que pretende: " << endl;
        cin >> nomeFornecedor;
        setNomeFornecedor(nomeFornecedor);

        bool nifValido = false;
        do {
            cout << "Insira o NIF do fornecedor (apenas números): ";
            fflush(stdin);
            cin >> nifFornecedor;

            if (validarNif(nifFornecedor)) {
                cout << "Número de NIF válido!" << endl;
                setNifFornecedor(nifFornecedor);
                nifValido = true;
            }
            else {
                cout << "Formato de número de NIF inválido!" << endl;
            }
        } while (!nifValido);
    }

    void leNovaMota() 
    {
        bool sair = false;
        int qtd = 0;
        float valorTotal = 0;
        char escolha = '\0';

        do 
        {
            Mota novaMota;
            cout << "Nova Mota" << endl;
            cout << "\nQuer encomendar novas(1) ou usadas(2)?" << endl;
            cin >> escolha;
            if (escolha == '1')
            {
                novaMota.leMarca();
                novaMota.leModelo();
                novaMota.leCor();
                novaMota.leCaixa();
                novaMota.leCombustivel();
                novaMota.leAnoMesRegisto();
                novaMota.lePotencia();
                novaMota.leCilindrada();
                novaMota.leNumUnidades();
                novaMota.leQuebra();
                novaMota.lePreco();
                motas.push_back(novaMota);
            }
            else
            {
                novaMota.novaMota();
                motas.push_back(novaMota);
            }

            cout << "Pretende adicionar mais motas à encomenda? S/N" << endl;
            cin >> escolha;
            if (escolha == 'N' || escolha == 'n')
            {
                sair = true;
            }
        } while (!sair);
        
        
        for (int i = 0; i < motas.size(); i++)
        {
            Mota novaMota;
            novaMota = motas[i];
            valorTotal += novaMota.getNumUnidades() * novaMota.getPreco();
        }

        setValorTotal(obtemPrecoComIVA(valorTotal));
    }

    void leAtualizaMota()
    {
        bool sair = false;
        int qtd = 0;
        float valorTotal = 0;
        char escolha = '\0';

        int index = -1;
        do {
            cout << "Escolha a mota para atualizar (1-" << motas.size() << "): ";
            cin >> index;
            cin.ignore();

            if (index < 1 || index > motas.size()) {
                cout << "Número inválido! Escolha entre 1 e " << motas.size() << "." << endl;
            }
        } while (index < 1 || index > motas.size());

        // Remover a mota selecionada
        motas.erase(motas.begin() + (index - 1));

        // Adicionar uma nova mota
        Mota novaMota;
        cout << "Insira os detalhes da nova mota:" << endl;
        novaMota.leMarca();
        novaMota.leModelo();
        novaMota.leCor();
        novaMota.leCaixa();
        novaMota.leCombustivel();
        novaMota.leAnoMesRegisto();
        novaMota.lePotencia();
        novaMota.leCilindrada();
        novaMota.leNumUnidades();
        novaMota.leQuebra();
        novaMota.lePreco();

        // Adicionar a nova mota à posição onde a anterior foi removida
        motas.insert(motas.begin() + (index - 1), novaMota);
    }

    // Método para exibir o código
    void mostraCodigo() {
        cout << "Código da Encomenda : " << getCodigo() << endl;
    }

    // Método para exibir a data
    void mostraData() {
        cout << "Data da Encomenda   : " << getData() << endl;
    }

    // Método para exibir o valor total
    void mostraValorTotal() {
        cout << "\nValor Total         : " << getValorTotal() << endl;
    }

    // Método para exibir o status
    void mostraStatus() {
        cout << "Status da Encomenda : " << getStatus() << endl;
    }

    void mostraMotas() {
        for (int i = 0; i < motas.size(); i++)
        {
            Mota novaMota;
            novaMota = motas[i];
            novaMota.mostraMota();
        }
    }

    void mostraFornecedor()
    {
        cout << "Nome Fornecedor     : " << getNomeFornecedor() << endl;
        cout << "NIF Fornecedor      : " << getNifFornecedor() << endl;
    }

    void novaEncomenda()
    {
        leCodigo();
        leData();
        leFornecedor();
        leNovaMota();
        leStatus();
    }

    void mostraEncomenda()
    {
        mostraCodigo();
        mostraData();
        mostraFornecedor();
        mostraStatus();
        mostraMotas();
        mostraValorTotal();
    }

    static float obtemPrecoComIVA(float psi)
    {
        const float IVAMOTA = 0.23;
        return (psi * (1 + IVAMOTA));
    }

    bool verificaInputInt(string numero)
    {
        regex formato(R"(^[0-9]+$)"); // Define a regex para números
        return regex_match(numero, formato);
    }

    bool validarNif(string nif) {
        regex formato("^[0-9]{9}$");
        return regex_match(nif, formato);
    }

    bool verificaInputFloat(string decimal)
    {
        regex formato(R"(^[0-9]+$)"); // Define a regex para números
        return regex_match(decimal, formato);
    }

    bool validarFormato(string input) {
        // Expressão regular para validar o formato AA-99
        regex formato("^[A-Z]{2}-\\d{2}$");
        return regex_match(input, formato);
    }

    bool validaData(string data) {
        if (data.length() != 10 || data[2] != '/' || data[5] != '/') {
            return false;
        }
        int dia, mes, ano;
        std::stringstream ss(data.substr(0, 2) + " " + data.substr(3, 2) + " " + data.substr(6, 4));

        if (!(ss >> dia >> mes >> ano)) {
            return false;
        }

        if (mes < 1 || mes > 12) {
            return false;
        }
        std::vector<int> diasPorMes = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            diasPorMes[1] = 29;
        }
        if (dia < 1 || dia > diasPorMes[mes - 1]) {
            return false;
        }

        return true;
    }

    friend istream& operator>> (istream& is, Encomenda& enc)
    {
        char letra = '\0';
        const int DESLOCAMENTO = 3;

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            enc.setCodigo(enc.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            enc.setData(enc.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            enc.setNomeFornecedor(enc.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
                texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            enc.setNifFornecedor(enc.desencripta(string(texto), DESLOCAMENTO));
        }

        int numMotas = 0;
        is >> numMotas; // Ler quantas motas existem
        is.ignore(); // Ignorar o resto da linha

        vector<Mota> motas;
        for (int i = 0; i < numMotas; ++i) {
            Mota mota;

            string marca, modelo, cor, caixa, combustivel, anoMesRegisto;
            int km, potencia, cilindrada, numUnidades, quebra;
            bool revisaoFeita;
            float preco;

            // Leitura e desencriptação dos atributos de cada Mota
            char texto[100] = { '\0' };

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

            // Adicionar ao vetor de motas
            motas.push_back(mota);
            enc.setMotas(motas); // Definir o vetor na Encomenda
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            enc.setStatus(enc.desencripta(string(texto), DESLOCAMENTO));
        }

        {
            const int MAXNOME = 40; char texto[MAXNOME];
            for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
            is.getline(texto, MAXNOME, '\n');
            strcpy_s(texto, enc.desencriptaII(texto, DESLOCAMENTO));
            enc.setValorTotal(atof(texto));
        }

        is.ignore();
        return is;
    }


    //*************************************************************************************
    //* Redefinição do operador "<<"
    //**************************************************************************************
    friend ostream& operator<< (ostream& os, Encomenda& enc)
    {
        const int DESLOCAMENTO = 3;
        os << enc.encripta(enc.getCodigo(), DESLOCAMENTO) << endl;
        os << enc.encripta(enc.getData(), DESLOCAMENTO) << endl;
        os << enc.encripta(enc.getNomeFornecedor(), DESLOCAMENTO) << endl;
        os << enc.encripta(enc.getNifFornecedor(), DESLOCAMENTO) << endl;
        
        vector<Mota> motas = enc.getMotas();
        os << motas.size() << endl;
        for (Mota mota : motas) {
            // Encriptação e gravação de cada campo de 'Mota' (exemplo para 'marca')
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
        }
        os << enc.encripta(enc.getStatus(), DESLOCAMENTO) << endl;
        os << enc.encripta(to_string(enc.getValorTotal()), DESLOCAMENTO) << endl;
        os << endl;
        return os;
    }
};


