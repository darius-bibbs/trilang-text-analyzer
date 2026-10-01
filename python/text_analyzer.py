"""Analyze UTF-8 text using byte-based, language-independent rules."""

import sys

ASCII_WHITESPACE = b" \t\n\r\v\f"
VOWELS = b"aeiouAEIOU"


def analyze(data: bytes) -> dict[str, int]:
    """Return counts for lines, words, bytes, ASCII vowels, and ASCII digits."""
    words = sum(
        1
        for index, byte in enumerate(data)
        if byte not in ASCII_WHITESPACE
        and (index == 0 or data[index - 1] in ASCII_WHITESPACE)
    )
    newline_count = data.count(b"\n")
    line_count = newline_count + int(bool(data) and not data.endswith(b"\n"))

    return {
        "Lines": line_count,
        "Words": words,
        "Bytes": len(data),
        "Vowels": sum(byte in VOWELS for byte in data),
        "Digits": sum(48 <= byte <= 57 for byte in data),
    }


def main() -> None:
    results = analyze(sys.stdin.buffer.read())
    for label, count in results.items():
        print(f"{label}: {count}")


if __name__ == "__main__":
    main()
