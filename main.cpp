#include <iostream>
#include <vector>
#include <fstream>
#include "cliente.hpp"
#include "gerente.hpp"
#include "pedido.hpp"
#include <stdexcept>


/// função onde salva produtos em um arquivo txt na pasta do programa
void salvarProdutos(const std::vector<Produto>& produtos, const std::string& arquivo) {
    std::ofstream file(arquivo);
    if (file.is_open()) {
        for (const Produto& produto : produtos) {
            file << produto.nome << "\n" << produto.preco << "\n";
        }
        file.close();
        std::cout << "Produtos salvos com sucesso em " << arquivo << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo " << arquivo << " para salvar produtos." << std::endl;
    }
}

/// função onde carrega produtos de um arquivo txt que está na pasta do programa
void carregarProdutos(std::vector<Produto>& produtos, const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (file.is_open()) {
        produtos.clear();
        std::string line;
        Produto product;
        while (std::getline(file, line)) {
            product.nome = line;
            if (std::getline(file, line)) {
                product.preco = std::stod(line);
                produtos.push_back(product);
            }
        }
        file.close();
        std::cout << "Produtos carregados com sucesso de " << arquivo << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo " << arquivo << " para carregar produtos." << std::endl;
    }
}

int main() {
    std::vector<Produto> sanduiches;
    std::vector<Produto> sucos;

    /// carrega produtos dos arquivos txt referentes, caso não encontre, são criados arquivos txt quando adiciona novos produtos nas funções do gerente. 
    carregarProdutos(sanduiches, "sanduiches.txt");
    carregarProdutos(sucos, "sucos.txt");

    int errorCount = 0;
    
    Gerente gerente;
    std::string senha;
    std::string nomeCliente;

    std::cout << "Defina a senha do gerente: ";
    std::getline(std::cin, senha);
    gerente.definirSenha(senha);

    std::cout << "Bem-vindo à Lanchonete!" << std::endl;
    std::cout << "Por favor, insira seu nome: ";
    std::getline(std::cin, nomeCliente);
    Cliente cliente(nomeCliente);

    while (true) {
        int perfil;
    /// tratamento de erro caso o limite de tentativas seja excedido ao inserir a senha incorreta do gerente
    try {
        if (errorCount > 2) {
            throw std::runtime_error("Limite de tentativas excedido, finalizando o programa!");
        }
        else {
            /// Tentativa de login
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        std::exit(EXIT_FAILURE); // Encerra o programa imediatamente
    }
        std::cout << "Escolha o perfil (1 - Cliente, 2 - Gerente, 0 - Sair): ";
        std::cin >> perfil; ///escolha dos perfis ou sair do programa

        if (perfil == 0) { ///se for 0, para o programa
            break;
        } else if (perfil == 1) { //se for 1, inicia o perfil do cliente
            std::cout << "Perfil do Cliente" << std::endl;
            cliente.listarSanduiches(sanduiches);
            cliente.listarSucos(sucos);

            int opcao;
            while (true) { ///menu do perfil do cliente
                std::cout << "Nome do cliente: " << cliente.getIdentificador() << std::endl;
                std::cout << "Escolha uma opção (1-5):" << std::endl;
                std::cout << "1. Adicionar ao Pedido" << std::endl;
                std::cout << "2. Calcular Valor do Pedido" << std::endl;
                std::cout << "3. Mostrar Pedido" << std::endl;
                std::cout << "4. Excluir do Pedido" << std::endl;
                std::cout << "5. Sair do Perfil de Cliente" << std::endl;
                std::cin >> opcao;

                if (opcao == 1) { ///se escolher a opção 1 no menu, entra nesse outro menu onde se escolhe o tipo do produto
                    int tipoProduto;
                    std::cout << "Escolha o tipo de produto (1 - Sanduíche, 2 - Suco): ";
                    std::cin >> tipoProduto;

                    if (tipoProduto == 1) {
                        /// se escolher o tipo 1 (sanduíche) mostra a lista de sanduíches e permite que o cliente escolha digitando o nome do produto.
                        cliente.listarSanduiches(sanduiches);
                        std::string nomeSanduiche;
                        std::cout << "Digite o nome do sanduíche desejado: ";
                        std::cin >> nomeSanduiche;

                        /// encontra o sanduíche pelo nome na lista.
                        bool encontrado = false;
                        for (const Produto& sanduiche : sanduiches) {
                            if (sanduiche.nome == nomeSanduiche) {
                                cliente.adicionarAoPedido(sanduiche);
                                encontrado = true;
                                break;
                            }
                        }

                        if (!encontrado) { ///se não encontrar, imprime o cout de erro
                            std::cout << "Sanduíche não encontrado na lista." << std::endl;
                        }
                    } else if (tipoProduto == 2) {
                        ///se escolher o tipo 2(sucos) mostra a lista de sucos e permite que o cliente escolha digitando o nome do produto.
                        cliente.listarSucos(sucos);
                        std::string nomeSuco;
                        std::cout << "Digite o nome do suco desejado: ";
                        std::cin >> nomeSuco;

                        /// encontra o suco pelo nome na lista.
                        bool encontrado = false;
                        for (const Produto& suco : sucos) {
                            if (suco.nome == nomeSuco) {
                                cliente.adicionarAoPedido(suco);
                                encontrado = true;
                                break;
                            }
                        }

                        if (!encontrado) { ///se não encontrar, imprime o cout de erro
                            std::cout << "Suco não encontrado na lista." << std::endl;
                        }
                    }
                } else if (opcao == 2) { ///opção 2 do menu, onde calcula o valor do carrinho atual
                    double valor = cliente.calcularValorPedido();
                    std::cout << "Valor total do carrinho: R$" << valor << std::endl;
                } else if (opcao == 3) { ///opção 3 do menu, onde mostra os produtos do carrinho atual
                    cliente.mostrarPedido();
                } else if (opcao == 4) { ///opção 4 do menu, onde você pode remover algum produto do carrinho digitando o seu nome
                    std::string nomeProduto;
                    std::cout << "Digite o nome do produto a ser removido do carrinho: ";
                    std::cin >> nomeProduto;
                    cliente.excluirDoPedido(nomeProduto);
                } else if (opcao == 5) { ///sair do perfil do cliente e retorna pro menu geral.
                    break;
                }
            }
        } else if (perfil == 2) { ///escolhe no menu geral do perfil do gerente
            std::cout << "Perfil do Gerente" << std::endl;

            std::cout << "Digite a senha do gerente: ";
            std::cin >> senha; 

            if (gerente.fazerLogin(senha)) { ///se foi digitada corretamente, o menu do gerente é exibido
                int opcao;
                while (true) {
                    std::cout << "Escolha uma opção (1-8):" << std::endl;
                    std::cout << "1. Listar Sanduiches" << std::endl;
                    std::cout << "2. Listar Sucos" << std::endl;
                    std::cout << "3. Adicionar Sanduiche" << std::endl;
                    std::cout << "4. Adicionar Suco" << std::endl;
                    std::cout << "5. Alterar Preço de Sanduiche" << std::endl;
                    std::cout << "6. Alterar Preço de Suco" << std::endl;
                    std::cout << "7. Excluir Sanduiche" << std::endl;
                    std::cout << "8. Excluir Suco" << std::endl;
                    std::cout << "9. Sair do Perfil de Gerente" << std::endl;
                    std::cin >> opcao;

                    if (opcao == 1) { ///opção 1, onde a lista dos sanduiches disponiveis é exibida
                        gerente.listarSanduiches(sanduiches);
                    } else if (opcao == 2) { ///opção 2, onde a lista de sucos disponiveis é exibida
                        gerente.listarSucos(sucos);
                    } else if (opcao == 3) { ///opção 3, onde é possível adicionar um novo sanduiche e o seu valor
                        Produto novoSanduiche;
                        std::cout << "Nome do novo sanduíche: ";
                        std::cin >> novoSanduiche.nome;
                        std::cout << "Preço do novo sanduíche: ";
                        std::cin >> novoSanduiche.preco;
                        sanduiches.push_back(novoSanduiche);///push_back, onde adiciona um novo elemento no final do vetor
 
                        salvarProdutos(sanduiches, "sanduiches.txt"); // salva os sanduíches atualizados no arquivo txt referente à sanduiches
                    } else if (opcao == 4) { ///opção 4, onde é possível adicionar um novo suco e o seu valor
                        Produto novoSuco;
                        std::cout << "Nome do novo suco: ";
                        std::cin >> novoSuco.nome;
                        std::cout << "Preço do novo suco: ";
                        std::cin >> novoSuco.preco;
                        sucos.push_back(novoSuco);

                        salvarProdutos(sucos, "sucos.txt"); /// salva os sucos atualizados no arquivo txt referente à sucos
                    } else if (opcao == 5) { ///opção 5, onde é possível alterar o valor de um sanduiche disponível
                        std::string nomeProduto;
                        double novoPreco;
                        std::cout << "Nome do sanduíche para alterar o preço: ";
                        std::cin >> nomeProduto;
                        std::cout << "Novo preço: ";
                        std::cin >> novoPreco;

                        /// encontra o sanduíche pelo nome na lista e atualiza o seu preço
                        for (Produto& sanduiche : sanduiches) {
                            if (sanduiche.nome == nomeProduto) {
                                sanduiche.preco = novoPreco;
                                break;
                            }
                        }

                        /// salvar os sanduíches atualizados no arquivo txt referente à sanduiches
                        salvarProdutos(sanduiches, "sanduiches.txt");
                    } else if (opcao == 6) { ///opção 6, onde é possível alterar o valor de um suco disponível
                        std::string nomeProduto;
                        double novoPreco;
                        std::cout << "Nome do suco para alterar o preço: ";
                        std::cin >> nomeProduto;
                        std::cout << "Novo preço: ";
                        std::cin >> novoPreco;

                        /// encontra o suco pelo nome na lista e atualiza o seu preço
                        for (Produto& suco : sucos) {
                            if (suco.nome == nomeProduto) {
                                suco.preco = novoPreco;
                                break;
                            }
                        }

                        /// salva os sucos atualizados no arquivo txt referente à sucos
                        salvarProdutos(sucos, "sucos.txt");
                    } else if (opcao == 7) { ///opção 7, onde é possível excluir um sanduíche que está listado
                        std::string nomeProduto;
                        std::cout << "Nome do sanduíche para excluir: ";
                        std::cin >> nomeProduto;

                        /// encontrar e exclui o sanduíche pelo nome na lista
                        for (auto it = sanduiches.begin(); it != sanduiches.end(); ) {
                            if (it->nome == nomeProduto) {
                                it = sanduiches.erase(it);
                            } else {
                                ++it;
                            }
                        }

                        /// salva os sanduíches atualizados no arquivo txt referente à sanduiches
                        salvarProdutos(sanduiches, "sanduiches.txt");
                    } else if (opcao == 8) { ///opção 8, onde é possível excluir um suco que está listado
                        std::string nomeProduto;
                        std::cout << "Nome do suco para excluir: ";
                        std::cin >> nomeProduto;

                        /// encontra e exclui o suco pelo nome na lista
                        for (auto it = sucos.begin(); it != sucos.end(); ) {
                            if (it->nome == nomeProduto) {
                                it = sucos.erase(it);
                            } else {
                                ++it;
                            }
                        }

                        /// salva os sucos atualizados no arquivo txt referente à sucos
                        salvarProdutos(sucos, "sucos.txt");
                    } else if (opcao == 9) {
                        break;
                    }
                }
            } else { ///caso digite a senha errada do perfil do gerente, exibe esse erro. 
                std::cout << "Senha incorreta. Acesso negado." << std::endl;
                errorCount++;
            }
        }
    }

    return 0;
}
