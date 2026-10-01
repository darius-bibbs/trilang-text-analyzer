# TriLang Text Analyzer

A small command-line project with the same text analyzer implemented in Python 3, C, and C++. Each version reads text from standard input and reports line, word, byte, ASCII vowel, and ASCII digit counts.

## Counting rules

- Input is processed as bytes, so UTF-8 characters can count as multiple bytes.
- Words are runs of bytes separated by ASCII whitespace (space, tab, newline, carriage return, vertical tab, or form feed).
- A line is each newline-terminated record, plus a final non-empty record that does not end in a newline. Empty input has zero lines.
- Vowels and digits are counted only for ASCII bytes.

## Run the Python version

From the project root:

```powershell
py -3 python/text_analyzer.py < sample.txt
```

Run the Python tests:

```powershell
py -3 -m unittest discover -s tests -v
```

## Build and run C and C++

You need CMake plus a C compiler and a C++17 compiler.

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```

Run either executable with redirected input:

```powershell
cmd /c "build\text_analyzer_c.exe < sample.txt"
cmd /c "build\text_analyzer_cpp.exe < sample.txt"
```

The MinGW generator puts both executables directly inside `build`.

## Example

Input:

```text
Hello, world! 42
```

Output:

```text
Lines: 1
Words: 3
Bytes: 17
Vowels: 3
Digits: 2
```
