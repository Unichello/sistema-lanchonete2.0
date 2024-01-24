#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

/// Onde é definida a estrutura do produto (sanduíche ou suco)

struct Produto {
    std::string nome; /// Nome do produto.
    double preco;     /// Preço do produto em reais.
};

#endif 
