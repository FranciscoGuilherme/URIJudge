# Exercício 1005

> Categoria iniciante

- [Requisitos](#requisitos)
- [Gerando o executável e a documentação](#executavel)

## <span id='requisitos'>Requisitos</span>

- Para que o projeto seja construído com sucesso, será necessário
  a instalação dos programas abaixo:
    - make
    - valgrind
    - doxygen
    - graphviz
    - cpputest

## <span id='executavel'>Gerando o executável e a documentação</span>

- Adicionar a variável PROJECT_DIR no seu arquivo .bashrc com o
  caminho completo até o diretório do projeto (src/) possibilitando
  a leitura e construção da documentação
    ``` sh
    export PROJECT_DIR=<caminho_src>
    ```
- Acessar o diretório _build_
- Executar o comando abaixo passando a língua na qual a documentação será exportada
    ``` sh
    $ make build.program LANGUAGE=<language>
    ```
- Lista de línguas suportadas atualmente no projeto
    - `_PT_BR`: Português
    - `_EN_US`: Inglês
