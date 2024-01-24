#ifndef CLIENTE_H
#define CLIENTE_H

#include "identificador.hpp"
#include "produto.hpp"
#include "pedido.hpp"
#include <vector>
#include <string>

/// Classe Cliente

class Cliente : public Identificador {
public:
    Cliente();
    
    Cliente(const std::string& nome);
    std::string getIdentificador() const override;
    void setIdentificador(const std::string& identificador) override;
    void listarSanduiches(const std::vector<Produto>& sanduiches);
    void listarSucos(const std::vector<Produto>& sucos);
    void adicionarAoPedido(const Produto& produto);
    double calcularValorPedido() const;
    void mostrarPedido() const;
    void excluirDoPedido(const std::string& nomeProduto);

private:
    Pedido pedido; /// Objeto Pedido substituindo o carrinho
};

#endif /// CLIENTE_H
