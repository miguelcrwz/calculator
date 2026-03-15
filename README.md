<div align="center">

<pre>
 ┌────────────────────────────────────────────────────┐
 │  user@dev:~/projects$ ./calculator                 │
 │                                                    │
 │        ██████╗   █████╗   ██╗        ██████╗       │
 │       ██╔════╝  ██╔══██╗  ██║       ██╔════╝       │
 │       ██║       ███████║  ██║       ██║            │
 │       ██║       ██╔══██║  ██║       ██║            │
 │       ╚██████╗  ██║  ██║  ███████╗  ╚██████╗       │
 │        ╚═════╝  ╚═╝  ╚═╝  ╚══════╝   ╚═════╝       │
 │                                                    │
 │  > four-operation terminal calculator · c + gcc    │
 └────────────────────────────────────────────────────┘
</pre>

![type](https://img.shields.io/badge/type-study%20project-2ea043?style=for-the-badge&labelColor=0d1117)
![version](https://img.shields.io/badge/version-1.0.0-58a6ff?style=for-the-badge&labelColor=0d1117)
![license](https://img.shields.io/badge/license-mit-8b949e?style=for-the-badge&labelColor=0d1117)
![stack](https://img.shields.io/badge/stack-c%20%2B%20gcc-d29922?style=for-the-badge&labelColor=0d1117)

</div>

---

## `$ cat about.txt`

```
calculator is a terminal program that asks for one of four operations
and two numbers, then prints the result.

everything lives in main(). the choice is read with scanf("%d") and
each number with scanf("%lf"), and every read checks what scanf
returns, so input that does not start with a number exits with code 1
before any math runs. a switch on the choice does the arithmetic, the
division case refuses a zero divisor, and the result is printed as
%.2lf in ansi color.

built as a hands-on study of c — reading input with scanf, branching
with switch and coloring the terminal with escape codes.
```

## `$ ls features/`

```
[x] addition, subtraction, multiplication and division of two numbers
[x] numbers are doubles — decimals and negatives both work
[x] input that does not start with a number exits with code 1, in red
[x] a choice outside 1-4 is rejected the same way
[x] division by zero is caught before it happens
[x] ansi colors for the menu, prompts, results and errors
[ ] one calculation per run — no loop back to the menu
[ ] division by zero prints an error but still exits with code 0
[ ] leftover text spills into the next prompt — first number 1,5 exits 1
[ ] on the second number the leftover is dropped — 2 + 1,5 gives 3.00
[ ] a choice like 1.5 runs as 1, and the .5 becomes the first number
[ ] a choice past int range wraps — 4294967297 runs as 1, addition
[ ] no overflow check — 1e308 * 10 prints inf (1.#J in the dev build)
[ ] the result always has two decimals — 1 / 3 prints 0.33
[ ] no fflush — in git bash (mintty) the prompts only show up at exit
[ ] colors are raw escape codes — terminals without vt support show them
[ ] no tests, no makefile
```

## `$ cat stack.lock`

```
runtime     c (c99 in the production build), gcc 6.3.0 (mingw)
framework   none — stdlib only (stdio.h: printf, scanf)
infra       none, runs locally in a terminal
tests       none yet
tooling     gcc cli — builds clean with -std=c99 -pedantic -Wall -Wextra
```

## `$ ./install.sh`

```bash
# clone
git clone https://github.com/miguelcrwz/calculator.git
cd calculator

# dependencies (none — just a c compiler, e.g. mingw gcc on windows)
gcc --version
```

## `$ ./run`

```bash
# development (from the repo root)
gcc main.c -o calculator && ./calculator

# production (-O2, strict warnings)
gcc -O2 -std=c99 -pedantic -Wall -Wextra main.c -o calculator
./calculator

# git bash (mintty) — without winpty the prompts only show up at exit
winpty ./calculator
```

```
WELCOME TO THE CALCULATOR!

CHOOSE AN OPERATION:
1. ADDITION
2. SUBTRACTION
3. MULTIPLICATION
4. DIVISION
ENTER YOUR CHOICE: 1

ENTER THE FIRST NUMBER: 10
ENTER THE SECOND NUMBER: 5
RESULT: 15.00
```

## `$ cat input.flow`

```
./calculator
  │
  ├─ read the choice with scanf("%d")
  │    ├─ no leading number ────────────> INVALID INPUT, exit 1
  │    └─ outside 1-4 ──────────────────> INVALID OPERATION, exit 1
  │
  ├─ read both numbers with scanf("%lf")
  │    └─ no leading number ────────────> INVALID INPUT, exit 1
  │
  └─ switch (operation)
       ├─ 1, 2, 3 ─> +, -, * ───────────> RESULT: x.xx, exit 0
       ├─ 4, second number is 0 ────────> ERROR! DIVISION BY ZERO, exit 0
       └─ 4 ─> num1 / num2 ─────────────> RESULT: x.xx, exit 0
```

## `$ tree`

```
calculator/
├── main.c       # menu, input checks and the four operations in main()
├── .gitignore   # keeps compiled binaries (output/, *.exe) out of git
├── LICENSE
└── README.md
```

## `$ git log --oneline roadmap`

```
a1b2c3d  fflush(stdout) after every prompt so they show up in git bash too
e4f5g6h  loop back to the menu until the user chooses to quit
i7j8k9l  exit with code 1 when dividing by zero
m0n1o2p  use fgets + strtol/strtod so 5abc and a 1.5 choice are rejected
q3r4s5t  move each operation into its own function and unit test them
u6v7w8x  add a makefile with the strict warning flags
```

## `$ cat LICENSE | head -1`

```
MIT © 2026 Miguel Cruz
```

## `$ whoami`

```
miguel cruz
├── github    https://github.com/miguelcrwz
├── linkedin  https://linkedin.com/in/miguelcrwz
└── email     miguwlcrwz@gmail.com
```

<div align="center">

<pre>
$ exit
[process exited with code 0]
</pre>

</div>
