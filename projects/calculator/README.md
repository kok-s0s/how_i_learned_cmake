# A Simple Calculator

i will use c-plus-plus to make it.

and use CMake to build && package it.

---

## Functional requirements

- [x] simple four arithmetic --- `["+", "-", "*", "/"]`;

- [x] complex operations --- `["%", "**", and so on]`;

- [x] nice looking user interface;

- [ ] and so on! --- take notes when i have new ideas;

---

> **Anyway, let's play!**

i use `clang-format` to format these files.

With `Windows Subsystem for Linux` --- Ubuntu

```bash
$ clang-format --version
clang-format version 10.0.0-4ubuntu1
```

With `macOS`

```bash
$ clang-format --version
clang-format version 14.0.1
```

i choose to use Google Style!

```bash
$ clang-format -style=google -dump-config > .clang-format
```
