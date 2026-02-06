# Template LaTeX — Poli USP (LuaLaTeX)

Este repositório contém um template LaTeX (estilo/capa/cabeçalho) para documentos da Poli-USP, com compilação via **LuaLaTeX** e fontes locais (Copperplate).

## Estrutura do repositório

- `main.tex` — arquivo principal do documento (exemplo de uso do template)
- `poliusp.sty` — pacote do template (capa, cabeçalho/rodapé, estilos)
- `fontes/` — fontes usadas pelo template
  - `copperplate_gothic_bt.ttf` (Regular)
  - `CopperplateGothicBT-Bold.otf` (Bold)
- `logospoli/` — logos e assets em PDF usados na capa/cabeçalho
- `Makefile` — comandos de build (PDF, watch, clean)

## Requisitos

### TeX / LaTeX
- TeX Live com suporte a **LuaLaTeX**
- `latexmk` (recomendado, usado pelo Makefile)

No Arch Linux:
```bash
sudo pacman -S texlive latexmk
### 2) Compilar o PDF

Na raiz do repositório, execute:

```bash
make

Para recompilar automaticamente toda vez que mudar o main.tex

```bash
make watch

Para remover a pasta build

```bash
make clean

Para remover os arquivos auxiliares

```bash
make distclean


