# Sistema de Gerenciamento de Loja

Este é um programa desenvolvido em C para gerenciamento básico de produtos em uma loja. Ele permite cadastrar, listar e vender produtos. Funciona tanto no Windows quanto no Linux e utiliza arquivos binários para armazenar os dados dos produtos.  

## Funcionalidades

- **Cadastro de Produtos**  
  Permite inserir informações de novos produtos, como código, nome, preço e quantidade, que são salvos em um arquivo binário.  

- **Listagem de Produtos**  
  Exibe todos os produtos cadastrados, mostrando o código, nome, preço e quantidade em estoque.  

- **Venda de Produtos**  
  Possibilita realizar vendas com busca por código ou nome do produto.  

- **Interface Personalizada com Cores**  
  Oferece opções para personalizar as cores do terminal (dependente do suporte do terminal para ANSI Escape Codes).  

## Estrutura do Programa

- Utiliza uma estrutura `struct` para armazenar as informações dos produtos.
- As funções estão bem organizadas e incluem comentários explicativos.
- Gerencia o fluxo de entrada do usuário para evitar problemas com o buffer de entrada.  

## Requisitos

- **Compilador C**  
  Qualquer compilador compatível com C (como GCC no Linux ou MinGW no Windows).  

## Compilação e Execução

### No Linux:
1. Abra o terminal e navegue até o diretório do programa.
2. Compile o programa:  
   ```bash
   gcc main.c -o main
   ```bash
   Execute o programa:
   ./main
   
### No Windows:
1. Abra o PowerShell ou CMD e navegue até o diretório do programa.
2. Compile o programa:  
   ```bash
   gcc main.c -o main.exe
   ```bash
   Execute o programa:
   ./main.exe

## Notas
- O programa armazena os dados dos produtos no arquivo products.bin. Certifique-se de que você tenha permissão de leitura e escrita no diretório onde o programa será executado.
- Para uma melhor experiência visual, é recomendável usar um terminal com suporte a cores ANSI.

### Melhorias Futuras
- Adicionar suporte para exclusão de produtos.
- Implementar relatórios de vendas.
- Adicionar suporte para múltiplos usuários e permissões de acesso.

### Conceito
Desenvolvido para fins educacionais com foco em reforçar conceitos de programação em C.
