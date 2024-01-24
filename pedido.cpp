#ifndef PEDIDO_H
#define PEDIDO_H

#include "produto.hpp"
#include <vector>
#include <string>
#include <iostream>

/// Classe Pedido

class Pedido {
public:
    void adicionarProduto(const Produto& produto, int quantidade);
    void removerProduto(const std::string& nomeProduto);
    double calcularTotal() const;
    void exibirPedido() const;

private:
    std::vector<std::pair<Produto, int>> itens; /// Pares de Produto e quantidade
};
/// definição de função adicionarproduto
void Pedido::adicionarProduto(const Produto& produto, int quantidade) {
    for (auto& item : itens) {
        if (item.first.nome == produto.nome) {
            item.second += quantidade;
            return;
        }
    }
    itens.push_back(std::make_pair(produto, quantidade));
}
/// definição de função removerproduto
void Pedido::removerProduto(const std::string& nomeProduto) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if (it->first.nome == nomeProduto) {
            if (--it->second <= 0) {
                itens.erase(it);
            }
            return;
        }
    }
}
/// definição de função calculartotal
double Pedido::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : itens) {
        total += item.first.preco * item.second;
    }
    return total;
}
/// definição de função exibirpedido
void Pedido::exibirPedido() const {
    for (const auto& item : itens) {
        std::cout << item.first.nome << " - " << item.second << " x R$" << item.first.preco << std::endl;
    }
    std::cout << "Total do Pedido: R$" << calcularTotal() << std::endl;
}

#endif /// PEDIDO_H
