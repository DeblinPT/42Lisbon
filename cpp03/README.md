# CPP Module 03

This repository contains the exercises for the 42 `cpp03` module. The module focuses on C++ inheritance, constructors/destructors, and class relationships through the `ClapTrap` family.

## Project Structure

- `ex00/` — basic `ClapTrap` class
- `ex01/` — `ScavTrap` inheritance from `ClapTrap`
- `ex02/` — `FragTrap` inheritance from `ClapTrap`
- `ex03/` — `DiamondTrap` and multiple inheritance behavior

## Build

Each exercise has its own `Makefile` and builds independently.

From inside an exercise folder:

```bash
make
```

Common targets:

- `make` — build the program
- `make clean` — remove object files
- `make fclean` — remove object files and the executable
- `make re` — rebuild everything

## Executables

- `ex00` → `claptrap`
- `ex01` → `scavtrap`
- `ex02` → `fragtrap`
- `ex03` → `diamondtrap`

## Notes

- The code is compiled with `-std=c++98`.
- The project uses `-Wall -Wextra -Werror`.
- Run the executable from the same exercise directory after building it.
