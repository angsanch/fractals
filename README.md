# Fractals

Create simple text fractals based on a pattern.

Project for semester 2 of the Stumpers module. Stumpers are 4 hour long, exam-like projects developed by 2 people.

### Description

This project is a coding challenge that focuses on generating fractals. The input consists of a number representing the size and detail of the fractal, and the 2 patterns representing the 2 possible tiles. This project requires you to develop complex algorythms in a short time.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [LibC](https://www.gnu.org/software/libc/)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`

## Usage

`./fractals size hash_pattern dot_pattern`

### Patterns

Patterns must only contain `#`, `.` and `@`. The `@` acts as a line break. Both patterns must be the same size and must form a rectangle. To increment the detail of the fractal each `.` is replaced by **dot_pattern** and `#` by **hash_pattern**. Every size 0 fractal is just a `#`, the replacement ocurs as many times as the size indicates.

### Examples
#### Sierpinski triangle
`$./fractals 5 ".#@##" "..@.."`
```
...............................#
..............................##
.............................#.#
............................####
...........................#...#
..........................##..##
.........................#.#.#.#
........................########
.......................#.......#
......................##......##
.....................#.#.....#.#
....................####....####
...................#...#...#...#
..................##..##..##..##
.................#.#.#.#.#.#.#.#
................################
...............#...............#
..............##..............##
.............#.#.............#.#
............####............####
...........#...#...........#...#
..........##..##..........##..##
.........#.#.#.#.........#.#.#.#
........########........########
.......#.......#.......#.......#
......##......##......##......##
.....#.#.....#.#.....#.#.....#.#
....####....####....####....####
...#...#...#...#...#...#...#...#
..##..##..##..##..##..##..##..##
.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#
################################
```

#### Menger sponge

`$./fractals 3 "###@#.#@###" "...@...@..."`
```
###########################
#.##.##.##.##.##.##.##.##.#
###########################
###...######...######...###
#.#...#.##.#...#.##.#...#.#
###...######...######...###
###########################
#.##.##.##.##.##.##.##.##.#
###########################
#########.........#########
#.##.##.#.........#.##.##.#
#########.........#########
###...###.........###...###
#.#...#.#.........#.#...#.#
###...###.........###...###
#########.........#########
#.##.##.#.........#.##.##.#
#########.........#########
###########################
#.##.##.##.##.##.##.##.##.#
###########################
###...######...######...###
#.#...#.##.#...#.##.#...#.#
###...######...######...###
###########################
#.##.##.##.##.##.##.##.##.#
###########################
```

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors
* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))
* **Sofia Martin** ([Github](https://github.com/sofiampx))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
