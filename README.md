# VSSS ERUS

Projeto de VSSS (Very Small Sized Soccer) da ERUS, desenvolvido em C++.


# Instalação de dependências

Para compilar o projeto e utilizar o simulador, é necessário instalar a seguinte lista de pacotes:

`g++ cmake libxmu-dev libxi-dev protobuf-compiler libprotobuf-dev pkg-config libzmq5 libzmq3-dev libboost-all-dev libbullet-dev freeglut3 freeglut3-dev`

Caso o pacote `pkg-config` esteja indisponível, instale o `pkgconf`.

Utilize o gerenciador de pacotes da sua distribuição, como `apt` ou `pacman`, para  instalar os pacotes listados.

Adicionalmente, é necessário compilar os subprojetos do simulador, o que pode ser feito por meio do script `vss-simulator/instalador.sh`. **Certifique-se de que todas as dependências de pacotes foram instaladas antes de rodar os scripts, ou você TERÁ erros de compilação**!

# Compilação

Para compilar o projeto, basta executar o script bash `compile.sh`. Ele utiliza o CMAKE para compilar o código fonte.

# Padrões de código

Primeiro comentário do arquivo

    /*
     * Nome do módulo
     * Ano de criação:
     * Descrição do módulo:
     * Versão:
     * Pré-requisitos (arquivos e bibliotecas necessárias para compilar)
     * Membros:
     */



 Comentário de protótipo de funções (.h)

    /*
     * Nome da função
     * Intenção da função:
     * Pré-requisitos:
     * Efeitos colaterais:
     * Parâmetros:
     * Retorno:
     */

**IMPORTANTE**: Comentários adicionais devem ser feitos no arquivo de implementação (.cpp) detalhando a implementação do código.

# Dados da Equipe:
O VSSS-ERUS é uma equipe dedicada a implementação do desafio Very Small Size Soccer para competições. É um projeto da ERUS - Equipe de Robótica da UFES, e diversos documentos sobre o projeto podem ser encontrados no site da equipe.
- Site da ERUS : erus.ufes.br/
- E-mail da ERUS : erus@inf.ufes.br
- E-mail do VSSS-ERUS : vssserus@gmail.com

## Membros Atuais
- Gabriel Pietroluongo
    - gabrielpietroluongo@gmail.com
- Gabriel Valdino
    - gvaldino@yahoo.com
- Mayke Wallace
    - mayke.ace@hotmail.com
- Lara de Luca
    - lara2058@hotmail.com
- Lorena Bassani
    - lorenabassani12@gmail.com

## Membros Antigos
- Ricardo Ramos
    - ricardobraun20006@gmail.com
- Victor de Oliveira
    - makkakie97@gmail.com
