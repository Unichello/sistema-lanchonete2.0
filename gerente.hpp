#ifndef GERENTE_H
#define GERENTE_H
#include "cliente.hpp"
#include "produto.hpp"
#include "identificador.hpp"
#include <vector>
#include <string>

/// Classe Gerente

class Gerente : public Identificador {
public:
    
    Gerente();
    Gerente(const std::string& senhaInicial);
    /// Funções do gerente que são fornecidas no gerente.cpp
    bool fazerLogin(const std::string& senha);
    void definirSenha(const std::string& novaSenha);
    std::string getIdentificador() const override;
    void setIdentificador(const std::string& identificador) override;
    void listarSanduiches(const std::vector<Produto>& sanduiches);
    void listarSucos(const std::vector<Produto>& sucos);
    void adicionarSanduiche(std::vector<Produto>& sanduiches, const Produto& novoSanduiche);
    void adicionarSuco(std::vector<Produto>& sucos, const Produto& novoSuco);
    void alterarPrecoSanduiche(std::vector<Produto>& sanduiches, const std::string& nome, double novoPreco);
    void alterarPrecoSuco(std::vector<Produto>& sucos, const std::string& nome, double novoPreco);
    void excluirSanduiche(std::vector<Produto>& produtos, const std::string& nome);
    void excluirSuco(std::vector<Produto>& produtos, const std::string& nome);

private:
    std::string senhaGerente;
};

#endif 
