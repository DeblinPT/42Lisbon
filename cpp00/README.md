# CPP Module 00

This repository contains the 42 C++ Module 00 exercises, focused on basic C++98 syntax, classes, and simple program structure.

## Overall concepts

- C++98 syntax and style
- Basic OOP design
- Input/output streams
- Data validation and formatting
- Writing small, testable programs

## Project Structure

- `ex00/` — `megaphone`: prints all arguments in uppercase.
- `ex01/` — `phonebook`: simple interactive phonebook with `ADD`, `SEARCH`, and `EXIT` commands.
- `ex02/` — `test`: bank account exercise using the provided `tests.cpp` scenario.

## Requirements

- `c++` compiler with C++98 support
- `make`
- Linux/macOS shell

## Build

Build each exercise from its folder:
    cd ex00 && make
    cd ../ex01 && make
    cd ../ex02 && make

## Run

### ex00 — megaphone

cd ex00
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."


If no arguments are provided:
./megaphone

Expected output:
* LOUD AND UNBEARABLE FEEDBACK NOISE *

### ex01 — phonebook

cd ex01
./phonebook

Available commands in the prompt:
- `ADD`
- `SEARCH`
- `EXIT`

Notes:
- The phonebook stores up to 8 contacts.
- When full, adding a new contact overwrites the oldest one (circular behavior).

### ex02 — account test

cd ex02
./test

This runs the provided account simulation in `tests.cpp`.

## Cleaning

From each exercise directory:
    make clean
    make fclean
    make re


## Quick Start

From repo root:
    cd ex00 && make && ./megaphone "hello world"
    cd ../ex01 && make && ./phonebook
    cd ../ex02 && make && ./test
