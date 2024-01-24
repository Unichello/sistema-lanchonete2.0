Sistema gerenciador de pedidos de uma lanchonete

Sobre o projeto: Foi desenvolvido um sistema de pedidos de lanches automático, onde a lanchonete realiza a venda de sanduíches e sucos. 

Como rodar o programa:
Utilize o comando "g++ main.cpp cliente.cpp gerente.cpp pedido.cpp -o programa", após compilar, utilize "./programa.exe"

Informações do desenvolvimento: O arquivo main.cpp gerencia a interação entre cliente e gerente;
Os arquivos cliente.cpp e cliente.hpp contém a classe "Cliente", onde é responsável pelas ações do cliente,  como listar os produtos, adicionar itens ao pedido, calcular o valor do pedido, mostrar o pedido e excluir itens do pedido;
Os arquivos gerente.cpp e gerente.hpp contém a classe "Gerente", onde é responsável pelas ações do gerente, como listar os produtos, adicionar novos produtos e seus preços, alterar preços de produtos existentes e excluir produtos do menu;
O arquivo produto.hpp define a estrtura de "Produto", usada para representar sanduiches e sucos. 

Sobre sua funcionalidade
Perfil do cliente: É possível listar os sanduíches disponíveis, listar os sucos disponíveis, adicionar produtos ao pedido, calcular o valor total do pedido, mostrar o conteúdo do pedido e excluir produtos presentes no pedido. 
Perfil do gerente: É possível fazer o login usando a senha já definida(senha: admin), caso digite de forma incorreta, o programa não permite o acesso ao perfil. Também é possível listar sanduíches disponíveis, listar os sucos disponíveis, adicionar novos sanduíches ao menu, adicionar novos sucos ao menu, alterar os preços dos sanduíches e dos sucos existentes e também excluir sanduíches e sucos do menu. 

Os produtos são salvos e carregador em um arquivo de texto(txt), eles são respectivamente: "sanduiches.txt" e "sucos.txt", permitindo que os dados se mantenham salvos e atualizados mesmo após o programa sendo encerrado. 

OBS: caso ocorra algum bug no carregamento dos arquivos .txt, no momento que você adiciona produtos(sanduíches ou sucos) através do perfil do gerente, seus respectivos arquivos são criados automaticamente. Até o momento, não ocorreu esse problema, mas caso ocorra, esse caminho contorna o erro. 
