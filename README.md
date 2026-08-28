# fortyTwo

Personal archive of work from **[42 Porto](https://www.42porto.com/)**, a project-based computer science school. Almost everything here is C on Unix: libc internals, algorithms, graphics, processes, networking, and exam drills. There is also the Piscine (the admission month), a Python hackathon, and a pile of scratch notes.

This is a **learning repo**, not a polished product monorepo. Folders range from finished projects with Makefiles to experiments, extra versions, and one subject PDF with no code yet. Use the map below to land in the right place.

**Author:** Gabriel Affonso ([@gabzaf](https://github.com/gabzaf)) · 42 login `gamado-x`

---

## Start here

| If you want… | Go to |
| --- | --- |
| The main 42 curriculum projects | [`Cursus/`](Cursus/) |
| Exam practice, ranked by difficulty | [`Exams/`](Exams/) |
| The 4-week bootcamp that came first | [`Piscine/`](Piscine/) |
| A Python scraping + dashboard hackathon | [`Hackaton/`](Hackaton/) |
| How to compile a typical C project | [Building](#building--running) |
| What each Cursus project actually does | [Cursus projects](#cursus-core-projects) |

Suggested order if you are reading the code as a path through 42:

1. [`Piscine/`](Piscine/) — C syntax, pointers, strings, recursion, shell
2. [`Cursus/libft`](Cursus/libft/) — reimplement libc; everything later reuses this
3. [`get_next_line`](Cursus/get_next_line/) → [`ft_printf`](Cursus/ft_printf/) — I/O and variadic functions
4. [`born2beRoot`](Cursus/born2beRoot/) — Linux admin (docs only here; the VM is not in git)
5. [`push_swap`](Cursus/push_swap/) / [`minitalk`](Cursus/minitalk/) / [`fdf`](Cursus/fdf/) — algorithms, signals, graphics
6. [`net_practice`](Cursus/net_practice/) — IP and routing puzzles
7. [`Exams/`](Exams/) — timed recreations of the same ideas, then C++ and sockets

---

## Repository map

```
fortyTwo/
├── Piscine/          4-week C + shell bootcamp (admission)
├── Cursus/           Core 42 projects (the main body of this repo)
│   ├── libft/
│   ├── born2beRoot/
│   ├── ft_printf/
│   ├── get_next_line/
│   ├── push_swap/
│   ├── minitalk/
│   ├── fdf/                  later / more complete wireframe renderer
│   ├── fdf_pixel_version/    earlier FdF attempt
│   ├── net_practice/
│   ├── pipex/                subject PDF only — no implementation yet
│   ├── operatorsInC/         bitwise / C operator scratch
│   └── testes/               throwaway tests (printf, GNL, leaks, …)
├── Exams/            Rank 02 → Rank 06 exam practice
└── Hackaton/         Hackathon Sogrape (Python wine-price scraping)
```

Most Cursus projects also ship `en.subject.pdf` (the official 42 brief) and a local `README.md`. Prefer those when you want the original constraints.

---

## Cursus (core projects)

These are the Common Core projects. Language is C unless noted. Compiler flags are almost always `-Wall -Wextra -Werror`. Style is 42 [Norminette](https://github.com/42School/norminette).

| Project | What it is | How to run |
| --- | --- | --- |
| [**libft**](Cursus/libft/) | Static library: libc string/memory/ctype, plus `ft_split`, `ft_itoa`, fd writers, and a linked-list bonus (`t_list`). Later projects depend on this mental model even when they copy the functions instead of linking the `.a`. | `make` → `libft.a`. Header: [`libft.h`](Cursus/libft/libft.h). |
| [**born2beRoot**](Cursus/born2beRoot/) | Secure a Debian/Rocky VM: encrypted LVM, SSH on port 4242, UFW, sudo/password policy, `monitoring.sh` on cron. | No code in git — only the subject and [notes](Cursus/born2beRoot/README.md). The deliverable was a virtual machine. |
| [**ft_printf**](Cursus/ft_printf/) | Recode `printf`: format parsing and conversions `cspdiuxX%`. | `make` → `libftprintf.a`. Prototype: `int ft_printf(const char *format, ...)`. |
| [**get_next_line**](Cursus/get_next_line/) | Read one line at a time from a file descriptor, with a compile-time `BUFFER_SIZE`. | `gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`. Returns `char *` (including `\n`) or `NULL`. |
| [**push_swap**](Cursus/push_swap/) | Sort integers using two stacks and a tiny instruction set (`sa`, `pb`, `ra`, …). Score is operation count (targets: ≤700 for 100 numbers, ≤5500 for 500). | `make && ./push_swap 3 8 1 2 0` |
| [**minitalk**](Cursus/minitalk/) | Client/server IPC using only `SIGUSR1` / `SIGUSR2` (one bit per signal). [`unixProcessInC/`](Cursus/minitalk/unixProcessInC/) is a sandbox of `fork`, pipes, and signal experiments that fed this project. | `make`, then `./server` and `./client <pid> "hello"`. |
| [**fdf**](Cursus/fdf/) | 3D wireframe landscape from `.fdf` height maps (MiniLibX, isometric projection, Bresenham). `make` clones [minilibx-linux](https://github.com/42Paris/minilibx-linux). | `make && ./fdf test_maps/42.fdf` (needs X11). |
| [**fdf_pixel_version**](Cursus/fdf_pixel_version/) | Earlier FdF tree — same idea, kept for comparison. Prefer [`Cursus/fdf`](Cursus/fdf/) unless you are tracing how the renderer evolved. | Same pattern: `make && ./fdf test_maps/42.fdf`. |
| [**net_practice**](Cursus/net_practice/) | Ten simulated TCP/IP labs: addressing, masks, routes, gateways. | Open the simulator from the `.tgz` / Intranet package. Written answers live in `level1/` … `level10/` as `solution_levelN.txt`. |
| [**pipex**](Cursus/pipex/) | Recode shell pipes (`infile cmd1 \| cmd2 > outfile`). | **Not implemented here** — folder currently holds only `en.subject.pdf`. |

### Scratch folders (not curriculum deliverables)

- [`Cursus/operatorsInC/`](Cursus/operatorsInC/) — bitwise flags, ternary, `switch`, bit reversal.
- [`Cursus/testes/`](Cursus/testes/) — ad-hoc tests for printf, GNL, `ft_split`, leaks, etc. Includes a compiled `memoryLeak` binary.

A fuller project-by-project writeup (skills, bonuses) is in [`Cursus/README.md`](Cursus/README.md).

---

## Exams

42 exams are timed, isolated C (later C++) sessions with a small allowed-function list. This tree is **practice and notes**, organised by rank. Many Rank 02 folders include a `subject.txt` / `subject.md` next to the solution.

| Rank | Focus | What’s in this repo |
| --- | --- | --- |
| [**Rank 02**](Exams/Rank_02/) | Strings, bits, simple lists, parsing | ~45 exercises: `ft_atoi` / `ft_split` / `ft_itoa`, `union` / `inter` / `wdmatch`, `flood_fill`, `sort_list`, bit ops (`print_bits`, `reverse_bits`, `swap_bits`), … |
| [**Rank 03**](Exams/Rank_03/) | Mini versions of Cursus I/O | [`ft_printf/`](Exams/Rank_03/ft_printf/), [`get_next_line/`](Exams/Rank_03/get_next_line/) |
| [**Rank 04**](Exams/Rank_04/) | Processes and pipes | [`microshell.c`](Exams/Rank_04/microshell.c) — tiny shell: `cd`, `;`, pipes |
| [**Rank 05**](Exams/Rank_05/) | C++ classes + classic algorithms | **lvl0:** `bigint` (arbitrary-precision unsigned int), `vect2` (2D vector operators), `polyset` (bag/set over array + tree). Several `v1`/`v2`/`v3` iterations. **lvl1:** `bsq` (biggest square on a map), `life` (Game of Life). |
| [**Rank 06**](Exams/Rank_06/) | Sockets, `select()`, no threads | [`mini_serv`](Exams/Rank_06/) — multiplexed TCP chat on `127.0.0.1`. See that folder’s README for compile/test with `nc`. |

Index of the lower ranks: [`Exams/README.md`](Exams/README.md) (covers Rank 02–04; 05 and 06 were added later).

Compile a typical exam file with:

```bash
cc -Wall -Wextra -Werror file.c -o prog
```

Rank 05 C++ files:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o prog
```

---

## Piscine

The Piscine is the intensive month before the Cursus. Layout follows 42’s daily modules: one directory per day, `ex00`, `ex01`, … inside.

| Path | Topic |
| --- | --- |
| [`c00/`](Piscine/c00/) | First functions: `putchar`, alphabet, `putnbr`, combinations |
| [`c01/`](Piscine/c01/) | Pointers, swap, `strlen`, in-place array reverse/sort |
| [`c02/`](Piscine/c02/) | String copy/classify/case, `strlcpy`, non-printable |
| [`c03/`](Piscine/c03/) | `strcmp` / `strncmp` / `strcat` / `strstr` |
| [`c04/`](Piscine/c04/) | `strlen`, `putstr`, `putnbr`, `atoi` |
| [`c05/`](Piscine/c05/) | Factorial, power, Fibonacci, sqrt, primes (iterative + recursive) |
| [`c06/`](Piscine/c06/) | `argc` / `argv` |
| [`c07semgit/`](Piscine/c07semgit/) | `malloc`: `strdup`, `range` (`semgit` = copy kept outside the original submit repo) |
| [`sh01/`](Piscine/sh01/) | Shell scripts: groups, `find`, file counts, MAC addresses, `skip.sh` |
| [`Rush00/`](Piscine/Rush00/) | Weekend group rush — printable rectangle / “rush” patterns |
| [`Rush01/`](Piscine/Rush01/) | Skyscraper-style constraint puzzle (solver). [`Rush01Clone/`](Piscine/Rush01Clone/) and [`Rush01deprecated/`](Piscine/Rush01deprecated/) are extra / older trees. |
| [`TestesC/`](Piscine/TestesC/) | Small C experiments from that month |

Compile a single exercise (no Makefile in these days):

```bash
cc -Wall -Wextra -Werror ft_whatever.c -o test
```

More context: [`Piscine/README.md`](Piscine/README.md).

---

## Hackathon

[`Hackaton/hackatonSogrape/`](Hackaton/hackatonSogrape/) is work from **Hackathon Sogrape**: scrape wine prices from Portuguese retailers and structure them for a dashboard.

- Scripts: `continente.py`, `garr_soares.py`, `el_corte_ingles.py`, plus shared helpers (`scraping.py`, `requisicoes.py`).
- Typical stack: Python 3, `requests`, BeautifulSoup, pandas.

Details and run notes: [`Hackaton/README.md`](Hackaton/README.md). Treat scrapers as historical code — storefronts change, and you should respect `robots.txt` and rate limits if you ever re-run them.

---

## Building & running

There is **no root Makefile**. Each Cursus project is standalone.

```bash
cd Cursus/<project>
make          # all
make clean    # objects
make fclean   # objects + binary / archive
make re       # fclean + all
```

**FdF** needs an X11 stack (MiniLibX links `-lXext -lX11 -lm -lbsd`) and will `git clone` `minilibx-linux` on first `make`.

**Minitalk** builds two binaries (`client` and `server`), not a single `NAME`.

**Valgrind** was the usual leak check:

```bash
valgrind --leak-check=full ./program
```

---

## How to read a 42 project folder

A typical Cursus directory looks like this:

| File | Role |
| --- | --- |
| `en.subject.pdf` | Official assignment (allowed functions, bonuses, norm) |
| `Makefile` | `all` / `clean` / `fclean` / `re` |
| `*.h` | Public API and structs |
| `README.md` | Short project-level notes (quality varies; this root README is the navigation layer) |
| `src/` or loose `.c` files | Implementation |

Things you will see that are *not* the “final hand-in”:

- Multiple versions (`v1`, `v2`, `v3` under Rank 05)
- `*_nogit`, `*Clone`, `*deprecated`, `semgit`
- Compiled binaries checked in (`push_swap`, `checker_linux`, `memoryLeak`)
- Vim swap files and test mains (`mainLibft.c`, `main.c` next to exam subjects)

If two trees exist for the same idea (FdF, Rush01, GNL tests), the name without `deprecated` / `pixel_version` / `Clone` is usually the one to read first.

---

## About 42

[42](https://www.42.fr/) has no lectures and no teachers. You learn by shipping projects, reviewing peers, and passing exams. **42 Porto** is the campus this work comes from. The Common Core is mostly C and Unix; later ranks add C++ and network programming.

This repository is a personal snapshot of that path (Piscine from 2023 onward). It is not an official 42 organisation repo.
