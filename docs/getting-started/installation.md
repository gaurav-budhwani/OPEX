# Installation & Setup

Get started with the OPEX language and compiler in minutes.

---

## Prerequisites

OPEX requires standard C build tools available on macOS and Linux systems:

| Dependency | Minimum Version | Description |
| :--- | :--- | :--- |
| **GCC** or **Clang** | C99 compliant | Host C compiler used for building the compiler and lowering code |
| **Flex** | 2.6+ | Fast Lexical Analyzer Generator |
| **Bison (Yacc)** | 3.8+ | LALR(1) Parser Generator |
| **Make** | GNU Make 3.81+ | Automation tool |

=== "macOS (Homebrew)"
    ```bash
    brew install flex bison make
    # Ensure Homebrew bison/flex are in your PATH if using Apple Silicon
    export PATH="/opt/homebrew/opt/bison/bin:$PATH"
    export PATH="/opt/homebrew/opt/flex/bin:$PATH"
    ```

=== "Ubuntu / Debian"
    ```bash
    sudo apt update
    sudo apt install -y build-essential flex bison
    ```

=== "Arch Linux"
    ```bash
    sudo pacman -S base-devel flex bison
    ```

---

## Build from Source

```bash
# Clone the repository
git clone https://github.com/gaurav-budhwani/OPEX.git
cd OPEX

# Compile the compiler binary
make
```

This compiles both `./parser` and creates the `./opex` CLI driver in the root directory.

---

## System-Wide Installation (Optional)

To invoke `opex` globally from any directory on your computer:

```bash
sudo make install
```

Now you can run:

```bash
opex --run program.opx
```

---

## Verifying the Installation

Run the built-in test suite to ensure the front-end, semantic analyzer, and native code generator are working properly:

```bash
# Run syntax and parsing checks
make test_all

# Run semantic validation
make test_semantic

# Run live algorithmic and computer vision test cases
make test_run
```
