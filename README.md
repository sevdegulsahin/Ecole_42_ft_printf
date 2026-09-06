*This project has been created as part of the 42 curriculum by sevdsahi.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library `printf()` function,
built as a static library (`libftprintf.a`). The project's goal is to understand
variadic functions in C and to write clean, extensible code for format string parsing.

Supported conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String (null prints `(null)`) |
| `%p` | Pointer address in hexadecimal (`0x...`) |
| `%d` | Signed decimal integer |
| `%i` | Signed integer in base 10 |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned integer in lowercase hexadecimal |
| `%X` | Unsigned integer in uppercase hexadecimal |
| `%%` | Literal percent sign |

## Instructions

### Compilation

```bash
make
```

This creates `libftprintf.a` at the root of the repository.

### Using ft_printf in your project

Include the header and link against the library:

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf -I. -o your_program
```

### Makefile rules

```bash
make          # build libftprintf.a
make clean    # remove object files
make fclean   # remove object files and library
make re       # full rebuild
```

## Algorithm and Data Structure

### Format String Parsing

`ft_printf()` iterates over the format string with a simple integer index — no
heap allocation required. When it encounters `%`, it reads the next character and
dispatches to `ft_handle()`, which selects the correct conversion. All other
characters are written directly with `write(1, ...)`.

This linear O(n) scan is simple to follow and easy to extend (adding a new
specifier is a one-line `if` block in `ft_handle`).

### Number Conversion — base-agnostic recursion

A single function handles every numeric conversion:

```c
int ft_putnbr_base(unsigned long n, int base, char *chars);
```

It works by:
1. Recursing on `n / base` (most-significant digit first — no string reversal needed)
2. Writing `chars[n % base]` on the way back up

Calling it with different arguments covers all cases:
- `%d` / `%i` → base 10, `"0123456789"` (wrapped in `ft_print_signed` for the sign)
- `%u` → base 10, `"0123456789"`, value cast to `unsigned int`
- `%x` → base 16, `"0123456789abcdef"`
- `%X` → base 16, `"0123456789ABCDEF"`

### Signed number safety (`INT_MIN`)

`ft_print_signed` casts the negated value to `unsigned long` *before* the
negation, avoiding undefined signed overflow for `INT_MIN`:

```c
ft_putnbr_base((unsigned long)(-n), 10, "0123456789");
```

### Pointer printing

`ft_print_ptr` writes the two-character prefix `0x` directly, then delegates
the address value (cast to `unsigned long`) to `ft_putnbr_base`. A NULL pointer
prints as `0x0`.

## Resources

- [printf specification — cppreference](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic functions — va_start / va_arg / va_end](https://en.cppreference.com/w/c/variadic)
- [ar(1) — creating static libraries](https://man7.org/linux/man-pages/man1/ar.1.html)
- [42 Norm v4](https://github.com/42School/norminette)

### AI Usage

AI (Antigravity / Claude) was used to:
- Generate the initial project file structure and Makefile boilerplate
- Produce the first draft of all `.c` and `.h` files

All generated code was reviewed and understood before being submitted. The
algorithm design decisions (recursive base conversion, pointer-to-va_list for
correct advancement, INT_MIN safety) were studied and explained independently.