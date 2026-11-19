# cpp02

This repository contains my solutions for **42 C++ Module 02**, focused on fixed-point arithmetic, operator overloading, and geometry with immutable types.

## Overall Concepts

This module is about building a small fixed-point number system and using it in increasingly expressive ways:

- Orthodox Canonical Form — practice the default constructor, copy constructor, assignment operator, and destructor
- Fixed-point arithmetic — store numbers as integers with a constant fractional precision
- Type conversion — convert between `int`, `float`, and the custom `Fixed` representation
- Operator overloading — make `Fixed` behave naturally with comparisons, arithmetic, and increments
- Const correctness — return immutable data where appropriate and keep `Point` coordinates fixed after construction.
- Geometry basics — use `Point` and `Fixed` together to determine whether a point lies inside a triangle in `ex03`

## Project Structure

The module is split into four exercises:

- `ex00` — introduces the `Fixed` class and the Orthodox Canonical Form.
- `ex01` — adds constructors from `int` and `float`, plus conversion helpers.
- `ex02` — extends `Fixed` with comparison, arithmetic, increment/decrement, and `min`/`max` operators.
- `ex03` — introduces `Point` and uses the `Fixed` class to solve the `bsp` (binary space partitioning) point-in-triangle check.

## Requirements

- `c++` compiler with C++98 support
- `make`
- Linux/macOS shell

## Build

Build each exercise from its own directory:

    cd ex00 && make
    cd ex01 && make
    cd ex02 && make
    cd ex03 && make

## Run

The generated executables are:

- `ex00`, `ex01`, `ex02` → `fixed`
- `ex03` → `bsq`

Run them from the corresponding exercise folder after building:

    ./fixed
    ./bsq

## Clean

Use the usual `make` targets inside each exercise folder:

    make clean
    make fclean
    make re

## Notes

- The code is written for the C++98 standard.
- `ex03` reuses the `Fixed` class and adds a `Point` class for geometry computations.
