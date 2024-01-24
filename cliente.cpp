#include "cliente.hpp"
#include <iostream>
#include "gerente.hpp"
#include "pedido.hpp"

/// Classe Cliente

Cliente::Cliente() {
    /// Implementação do construtor, se necessário
}

Cliente::Cliente(const std::string& nome) {
    this->identificador = nome; /// Utilizando identificador da classe base
}
    /// definição do metodo getidentificador
std::string Cliente::getIdentificador() const {
    return this->identificador;
}
    /// definição do metodo setidentificador
void Cliente::setIdentificador(const std::string& identificador) {
    this->identificador = identificador;
}
    /// definição da função listarsanduíches
void Cliente::listarSanduiches(const std::vector<Produto>& sanduiches) { 
    std::cout << "Sanduíches disponíveis:" << std::endl;
    for (const Produto& sanduiche : sanduiches) {
        std::cout << sanduiche.nome << " - R$" << sanduiche.preco << std::endl;
    }
}
    /// definição da função listarsucos
void Cliente::listarSucos(const std::vector<Produto>& sucos) {
    std::cout << "Sucos disponíveis:" << std::endl;
    for (const Produto& suco : sucos) {
        std::cout << suco.nome << " - R$" << suco.preco << std::endl;
    }
}

    /// definição da função adicionaroaopedido
void Cliente::adicionarAoPedido(const Produto& produto) {
    pedido.adicionarProduto(produto, 1); /// Adiciona o produto ao pedido
    std::cout << produto.nome << " foi adicionado ao pedido." << std::endl;
}
    /// definição da função calcularvalordopedido
double Cliente::calcularValorPedido() const {
    return pedido.calcularTotal(); /// Calcula o total do pedido
}
    /// definição da função mostrarpedido
void Cliente::mostrarPedido() const {
    pedido.exibirPedido(); /// Mostra os itens no pedido
}
    /// definição da função excluirdopedido
void Cliente::excluirDoPedido(const std::string& nomeProduto) {
    pedido.removerProduto(nomeProduto); /// Remove o produto do pedido
    std::cout << nomeProduto << " foi removido do pedido." << std::endl;
}
