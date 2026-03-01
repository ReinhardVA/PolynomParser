# PolynomParser

A desktop mathematical graph plotting application built with C++. Enter a polynomial expression and instantly visualize it on an interactive 2D coordinate grid.

## Features

- **Expression Parsing** — Type mathematical expressions (e.g., `2*x^2 + 3*x - 5`) into the input field and see them plotted in real time.
- **Custom Lexer & Parser** — Hand-written lexer tokenizes input into numbers, variables, operators, and parentheses; a recursive parser builds an Abstract Syntax Tree (AST).
- **Expression Evaluation** — The evaluator walks the AST and computes *y* for each *x* in the range **[−10, 10]** with a step of **0.1**.
- **2D Graph Rendering** — Plots the resulting curve on a zoomable coordinate grid with labeled axes.
- **Immediate-Mode UI** — Uses Dear ImGui (via imgui-SFML) for the input text box and controls.

## Architecture

| Layer | Key Files |
|---|---|
| **App** | `src/app/Application.cpp/.h` |
| **Lexer** | `src/core/lexer/Lexer.h`, `TokenType.h` |
| **Parser** | `src/core/parser/Parser.h`, `ASTNode.h` |
| **Evaluator** | `src/core/evaluator/Evaluator.h` |
| **Graphics** | `src/graphics/Plotter.cpp/.h` |

## Tech Stack

- **C++17**
- **[SFML 3](https://www.sfml-dev.org/)** — Window management & 2D rendering
- **[Dear ImGui](https://github.com/ocornut/imgui)** (+ imgui-SFML) — GUI widgets
- Custom linked-list data structure (`DS/LinkedList.h`)