# URIJudge
:coffee: Soluções em linguagem C dos problemas URI Online Judge

> Read this documentation in English: [Click here](https://github.com/FranciscoGuilherme/URIJudge/blob/master/README.en.md)

## Sumário

- [Requisitos](#requisitos)
    - [Guia de instalação](#instalacao)
- [Orientações iniciais](#orientacoes)
- [Gerando o executável](#executavel)
- [Testes no projeto](#testes)

## <span id='requisitos'>Requisitos</span>

- Para que o projeto seja construído com sucesso, será necessário
  a instalação dos programas abaixo:
    - __make__ para automatizar a compilação do projeto,
      gerar a documentação e compilar os testes
    - __valgrind__ para, durante a compilação, gerar estatísticas
      de uso memória e processamento
    - __doxygen__ para gerar a documentação do projeto através de
      comentários codificados nos arquivos de código
    - __cpputest__ para a codificação dos testes do projeto
    -

### <span id='instalacao'>Guia de instalação</span>

- O processo de instalação é relativamente simples
    - Para quem usa alguma distribuição derivada do Debian, como
      Ubuntu e Elementary, basta executar os comandos:
      ``` sh
      $ sudo apt-get update
      $ sudo apt-get install build-essential
      $ sudo apt-get install valgrind
      $ sudo apt-get install doxygen
      $ sudo apt-get install graphviz
      $ sudo apt-get install cpputest
      ```
    - Para o Fedora, você terá que executar os comandos:
      ``` sh
      $ yum install make automake gcc gcc-c++ kernel-devel
      $ yum install valgrind
      $ dnf copr enable rspanton/cpputest
      $ dnf install cpputest
      ```
      - Para a instalação do _doxygen_ recomendo o guia de
        instalação fornecido em no [site oficial](http://www.doxygen.nl/manual/install.html)

## <span id='orientacoes'>Orientações iniciais</span>

- Cada exercício possui sua própria documentação
- Atualmente o projeto possui a seguinte lista de línguas suportadas
- O comando de compilação tem como opção a especificação de um idioma
  para extração da documentação através do argumento __LANGUAGE=<language>__
- Abaixo a lista de idiomas suportados atualmente:
    - `_PT_BR`: Português
    - `_EN_US`: Inglês

## <span id='executavel'>Gerando o executável</span>

- Acessar o diretório _build_ do exercício escolhido
- Executar o comando abaixo com a opção de especificar ou não
  um idioma para a extração da documentação
``` sh
$ make build.program [LANGUAGE=<language>]
```
- Caso não queira que o processo de gerar a documentação pare, será
  necessário a configuração de uma variável de ambiente
    - Adicione a variável PROJECT_DIR no arquivo ~/.bashrc com o
      caminho completo do diretório src/ do exercício
        ``` sh
        export PROJECT_DIR=<caminho_src>
        ```

## <span id='testes'>Testes no projeto</span>

- Para gerar os testes execute, após ter gerado o executável
  (passo anterior), dentro do diretório _build_:
``` sh
$ make build.tests
```
- Execute os testes:
``` sh
$ ../bin/tests
```
