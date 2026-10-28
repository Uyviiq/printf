*This project has been created as part of the 42 curriculum by `<ael-hamr>`.*

# ft_printf

## Description

The `ft_printf` project consists of reimplementing the standard C `printf()` function.

The goal of this project is to understand variadic functions in C, manage different data types, and format and print data according to a format string.

The implementation is written in C and follows the requirements of the 42 curriculum.

### Project Objectives

- Understand and use variadic functions (`va_start`, `va_arg`, and `va_end`).
- Parse and interpret format specifiers.
- Convert and print different data types.
- Manage return values and edge cases.

### Supported Conversions

| Specifiers | |
|---|---|
| `%c` | |  
| `%s` | |
| `%p` | |
| `%d` | |
| `%i` | |
| `%u` | |
| `%x` | |
| `%X` | |
| `%%` | |

## Instructions

### Requirements

- A C compiler (e.g., `cc`).
- `make`.

### Compilation

Clone the repository:

```bash
git clone <repository-url>
cd <repository-name>
```

Compile the library:

```bash
make
```

### Available Makefile Rules

| Rules | |
|---|---|
| `make` | |
| `make clean` | |
| `make fclean` | |
| `make re` | |

### Usage

Include the header in your C source file:

```c
#include "ft_printf.h"
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s! Number: %d\n", "1337", 1337);
    ft_printf("Characters printed: %d\n", count);
    return (0);
}
```

Compile your program with the library:

```bash
cc main.c -Iinclude libftprintf.a -o program
```

### Execution

```bash
./program
```

## Implementation

### Functions

#### `ft_printf()`

**File:** `src/ft_printf.c`

**Purpose:** Main entry point of the library. Mimics the behavior of the standard C `printf()` function.

**Responsibilities:**
- Initialize the variadic argument list.
- Process the format string.
- Track the number of characters printed.
- Return the total number of characters printed.

#### Format Parsing

**File:** `src/parser.c`

**Purpose:** Identify and interpret format specifiers in the format string.

**Responsibilities:**
- Traverse the format string.
- Identify conversion specifiers.
- Store the parsed specifier in the appropriate data structure.
- Prepare the information needed by the conversion handlers.

#### `call_handler()`

**File:** `src/ft_printf.c`

**Purpose:** Dispatch the parsed conversion specifier to the appropriate handler.

**Responsibilities:**
- Retrieve the corresponding argument from the variadic argument list.

#### `print_string()`

**File:** `src/handlers/handle_string.c`

**Purpose:** Handle character and string conversions.

**Responsibilities:**
- Handle `%c` by printing a single character.
- Handle `%s` by printing a string.
- Handle null string pointers according to the implementation's chosen behavior.

#### `print_signed()`

**File:** `src/handlers/putbase`.

**Purpose:** Print signed decimal integers for `%d` and `%i`.

**Responsibilities:**
- Handle negative and non-negative values.
- Print the minus sign for negative values.
- Convert the integer magnitude to decimal digits.
- Handle the minimum value of the `int` type without signed integer overflow.

#### `ft_putnbr_base()`

**File:** `src/handlers/putbase.c`

**Purpose:** Convert an integer value into digits using a specified base and print the result.

**Parameters:**
- `data`: Structure containing the printing state and character count.
- `nbr`: Number to convert.
- `base`: String containing the digits used for conversion.

**Supported bases:**
- Base 10 for decimal numbers.
- Base 16 for hexadecimal numbers, using lowercase or uppercase digits.

**Implementation details:**
- Determine the length of the supplied base.
- Extract digits using division and remainder.
- Print the digits in the correct order.
- Support unsigned values used by the relevant conversion handlers.

`printf_utils.c`

**Purpose:** Provide utility functions for printing characters and strings and calculating string lengths.

**Responsibilities:**

- Print a single character using `print_char()`.
- Calculate the length of a string using `ft_strlen()`.
- Print a string using `ft_putstr()`.
- Update the total character count after writing output.
- Return a status indicating whether the write operation succeeded or failed.

### Data Structures

#### `t_data`

**Defined in:** `include/ft_printf.h`

**Purpose:**
- store the count of that characteres that have been written
- keep an index for the current string
- keep track or what specifiere we are working with currentlly


## Resources

### Documentation

- [Variadic Functions](https://onepunchcoder.medium.com/variadic-functions-explained-fd3b4ab6fd84)
- [behind printf](https://stackoverflow.com/questions/13657890/what-goes-behind-printf-in-c)

## Project Structure

```text
ft_printf/
├── include/
│   ├── ft_printf.h
├── src/
│   ├── handlers/
│   |       ├── call_handler.c
│   |       ├── handle_string.c
│   |       ├── putbase.c
|   |── ft_printf.c
|   |── parser.c
|   |── printf_utils.c
|── Makefile
```