#include "gerente.hpp"
#include <iostream>
#include "cliente.hpp"
#include <fstream>

/// Classe Gerente
Gerente::Gerente() {
}

Gerente::Gerente(const std::string& senhaInicial) : senhaGerente(senhaInicial) {
    /// Construtor para definir senha inicial
}
    /// função fazerlogin do gerente    
bool Gerente::fazerLogin(const std::string& senha) {
    return senha == senhaGerente;
}
    /// função que define nova senha do gerente
void Gerente::definirSenha(const std::string& novaSenha) {
    this->senhaGerente = novaSenha;
}
    /// definição do metodo getidentificador
std::string Gerente::getIdentificador() const {
    return this->identificador;
}
    /// definição do metodo setidentificador
void Gerente::setIdentificador(const std::string& identificador) {
    this->identificador = identificador;
}

/// Função onde lista os sanduíches disponíveis
void Gerente::listarSanduiches(const std::vector<Produto>& sanduiches) {
    std::cout << "Sanduiches cadastrados:" << std::endl;
    for (const Produto& sanduiche : sanduiches) {
        std::cout << sanduiche.nome << " - R$" << sanduiche.preco << std::endl;
    }
}

/// Função onde lista os sucos disponíveis
void Gerente::listarSucos(const std::vector<Produto>& sucos) {
    std::cout << "Sucos cadastrados:" << std::endl;
    for (const Produto& suco : sucos) {
        std::cout << suco.nome << " - R$" << suco.preco << std::endl;
    }
}

/// Função onde adiciona um novo sanduíche à lista de sanduíches
void Gerente::adicionarSanduiche(std::vector<Produto>& sanduiches, const Produto& novoSanduiche) {
    sanduiches.push_back(novoSanduiche);
    std::cout << "Novo sanduiche adicionado: " << novoSanduiche.nome << std::endl;
}

/// Função onde adiciona um novo suco à lista de sucos
void Gerente::adicionarSuco(std::vector<Produto>& sucos, const Produto& novoSuco) {
    sucos.push_back(novoSuco);
    std::cout << "Novo suco adicionado: " << novoSuco.nome << std::endl;
}

/// Função onde altera o preço de um sanduíche existente
void Gerente::alterarPrecoSanduiche(std::vector<Produto>& sanduiches, const std::string& nome, double novoPreco) {
    for (Produto& sanduiche : sanduiches) {
        if (sanduiche.nome == nome) {
            sanduiche.preco = novoPreco;
            std::cout << "Preço de " << nome << " atualizado para R$" << novoPreco << std::endl;
            return;
        }
    }
    std::cout << "Sanduiche não encontrado: " << nome << std::endl;
}

/// Função onde altera o preço de um suco existente
void Gerente::alterarPrecoSuco(std::vector<Produto>& sucos, const std::string& nome, double novoPreco) {
    for (Produto& suco : sucos) {
        if (suco.nome == nome) {
            suco.preco = novoPreco;
            std::cout << "Preço de " << nome << " atualizado para R$" << novoPreco << std::endl;
            return;
        }
    }
    std::cout << "Suco não encontrado: " << nome << std::endl;
}

/// Função onde exclui um sanduíche da lista de produtos
void Gerente::excluirSanduiche(std::vector<Produto>& produtos, const std::string& nome) {
    for (auto it = produtos.begin(); it != produtos.end(); ) {
        if (it->nome == nome) {
            it = produtos.erase(it);
        } else {
            ++it;
        }
    }
}

/// Função onde exclui um suco da lista de produtos
void Gerente::excluirSuco(std::vector<Produto>& produtos, const std::string& nome) {
    for (auto it = produtos.begin(); it != produtos.end(); ) {
        if (it->nome == nome) {
            it = produtos.erase(it);
        } else {
            ++it;
        }
    }
}
