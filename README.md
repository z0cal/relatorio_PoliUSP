# Template LaTeX — Poli USP (LuaLaTeX)

Este repositório contém um template LaTeX (estilo/capa/cabeçalho) para documentos da Poli-USP, com compilação via **LuaLaTeX** e fontes locais (Copperplate).

A capa usa proporção áurea na composição, brasão em marca-d'água e filetes
com losango vazado ao redor dos autores. A Copperplate fica na capa e nos
títulos das seções principais. Veja [CAPA.md](CAPA.md) para as dimensões.

## Versão para Overleaf

O arquivo `overleaf-optin.zip` contém uma versão com recursos limitados, preparada para compilação no Overleaf. Para usar o projeto completo em uma instância self-hosted do Overleaf, entre em contato pelo e-mail [gabriel_zocal@usp.br](mailto:gabriel_zocal@usp.br).

O projeto completo exige **LuaLaTeX**; XeLaTeX não funciona (o pacote
`transparent` da capa não roda no XeTeX). Duas coisas garantem o motor certo
mesmo que o compilador do projeto no Overleaf esteja no padrão pdfLaTeX:

- o comentário `% !TeX program = lualatex` no início do `main.tex`, que o
  Overleaf self-hosted respeita; mantenha-o nas primeiras 20 linhas;
- o `latexmkrc`, lido tanto pelo latexmk local quanto pelo do Overleaf, que faz
  o modo pdfLaTeX rodar `lualatex -shell-escape`.

## Opções do pacote

O núcleo do `poliusp.sty` carrega só o que todo relatório usa: capa,
cabeçalho/rodapé, figuras e tabelas. O resto entra sob demanda, para que um
relatório curto não pague o custo de compilação de `amsthm`, `siunitx`, `tikz`
e `minted`:

```latex
\usepackage[math,units]{poliusp}   % só o que for usar
\usepackage[full]{poliusp}         % carrega todas as opções
```

| Opção | O que ativa |
|---|---|
| `math` | `amsmath`, `amssymb`, `amsthm` e os ambientes `teorema`, `lema`, `corolario`, `proposicao`, `definicao`, `exemplo`, `observacao` |
| `units` | `siunitx` com vírgula decimal e separador de milhar brasileiros |
| `localtoc` | `etoc` e a macro `\gerarSumarioLocal` |
| `subfigures` | `subcaption` |
| `smartrefs` | `cleveref` com todos os nomes em português |
| `floatbarriers` | `placeins` e a macro `\FloatBarrier` |
| `tikz` | `tikz` e as bibliotecas usadas pelo template |
| `code` | `minted` (exige `-shell-escape` e Pygments) e os ambientes `vhdlcode`, `verilogcode`, `pythoncode`, `ccode`, `bashcode`, `makecode`, `gascode` (assembly AT&T), `objdumpcode`, `terminal` (sessão de shell) e `diff`; `\inputtrecho[opções]{linguagem}{arquivo}{tag}`, que inclui as linhas entre dois comentários `--tag--` com a numeração do arquivo; e o ambiente `codigolongo` (`\begin{codigolongo}{legenda}\label{...}` … `\end{codigolongo}`), código com legenda fora de float, para arquivo longo que precisa quebrar página. As legendas de código ficam acima do bloco |
| `pseudo` | `algorithm` + `algpseudocode` (palavras-chave em inglês), com "Algoritmo" nas legendas e `\cref` para algoritmos e para linhas |
| `full` | todas as opções acima |

Opção desconhecida gera aviso na compilação, não erro silencioso.
O `main.tex` de exemplo usa `full`, porque demonstra todos os recursos.

## Estrutura do repositório

- `main.tex` — arquivo principal do documento (exemplo de uso do template)
- `poliusp.sty` — pacote do template (capa, cabeçalho/rodapé, estilos)
- `codigos/` — código-fonte lido por `\inputminted` no exemplo de `secoes/recursos.tex`
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
