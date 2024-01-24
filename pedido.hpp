#ifndef PEDIDO_H
#define PEDIDO_H

#include "produto.hpp"
#include <vector>
#include <string>

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

#endif /// PEDIDO_H
