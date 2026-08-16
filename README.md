# Template LaTeX — Poli USP (LuaLaTeX)

Este repositório contém um template LaTeX (estilo/capa/cabeçalho) para documentos da Poli-USP, com compilação via **LuaLaTeX** e fontes locais (Copperplate).

## Versão para Overleaf

O arquivo `overleaf-optin.zip` contém uma versão com recursos limitados, preparada para compilação no Overleaf. Para usar o projeto completo em uma instância self-hosted do Overleaf, entre em contato pelo e-mail [gabriel_zocal@usp.br](mailto:gabriel_zocal@usp.br).

## Estrutura do repositório

- `main.tex` — arquivo principal do documento (exemplo de uso do template)
- `poliusp.sty` — pacote do template (capa, cabeçalho/rodapé, estilos)
- `fontes/` — fontes usadas pelo template
  - `copperplate_gothic_bt.ttf` (Regular)
  - `CopperplateGothicBT-Bold.otf` (Bold)
- `logospoli/` — logos e assets em PDF usados na capa/cabeçalho
- `Makefile` — comandos de build (PDF, watch, clean)

## Requisitos

- TeX Live com suporte a **LuaLaTeX** e aos pacotes utilizados pelo template
- `latexmk`, usado pelo Makefile
- Python com Pygments, usado pelo pacote `minted`

No Arch Linux:

```bash
sudo pacman -S texlive texlive-langportuguese python-pygments
```

O grupo `texlive` inclui o pacote `texlive-binextra`, que fornece o `latexmk`.

## Compilar o PDF

Na raiz do repositório, execute:

```bash
make
```

O PDF será gerado em `build/main.pdf`.

Para recompilar automaticamente quando algum arquivo do projeto for alterado:

```bash
make watch
```

Para remover a pasta `build`, incluindo o PDF gerado:

```bash
make clean
```

Para também remover eventuais arquivos auxiliares gerados na raiz do projeto:

```bash
make distclean
```
