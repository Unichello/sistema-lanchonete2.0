#ifndef IDENTIFICADOR_H
#define IDENTIFICADOR_H

#include <string>

/// Classe Identificador

class Identificador {
public:
    virtual ~Identificador() {} /// Destrutor virtual

    virtual std::string getIdentificador() const = 0; /// Método get abstrato
    virtual void setIdentificador(const std::string& identificador) = 0; ///Método set abstrato

protected:
    std::string identificador; /// Atributo protegido
};

#endif // IDENTIFICADOR_H
