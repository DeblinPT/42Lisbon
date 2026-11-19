# CPP Module 01

This repository contains the exercises for 42 C++ Module 01.

## Overall Concepts

- Memory management: heap/stack, lifetimes, new/delete, new[]/delete[]
- References and pointers: when to use each and how they behave
- Class design basics: objects interacting through references/pointers
- Input/output fundamentals: CLI args, stream-based file processing
- Structured control flow: dispatching behavior from string levels

## Project layout

- `ex00` — BraiiiiiiinnnzzzZ
- `ex01` — Moar brainz!
- `ex02` — HI THIS IS BRAIN
- `ex03` — Unnecessary violence
- `ex04` — Sed is for losers
- `ex05` — Harl 2.0
- `ex06` — Harl filter

Each exercise is independent and has its own `Makefile`.

## Requirements

- `c++` compiler with C++98 support
- `make`
- Linux/macOS shell

## Build & run

### ex00

cd ex00
make
./zombie_test_00

### ex01

cd ex01
make
./zombie_test_01

### ex02

cd ex02
make
./brain

### ex03

cd ex03
make
./battle

### ex04

cd ex04
make
./replace <filename> <s1> <s2>

This creates a new file named `<filename>.replace` where all occurrences of `s1` are replaced by `s2`.

### ex05

cd ex05
make
./harl
./harl DEBUG INFO WARNING ERROR

Accepted levels: `DEBUG`, `INFO`, `WARNING`, `ERROR`.

### ex06

cd ex06
make
./harlFilter DEBUG
./harlFilter INFO
./harlFilter WARNING
./harlFilter ERROR

`ex06` takes exactly one level and prints that level plus all higher-severity messages.

## Common Make targets

Inside any `ex0X` folder:

make        # build
make clean  # remove object files
make fclean # remove objects + binary
make re     # rebuild from scratch

## Notes

- Exercises are intentionally small and focused on specific C++ concepts.
- Run each executable from its own folder after building.
