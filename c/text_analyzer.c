#include <stdio.h>

static int is_ascii_whitespace(int byte) {
    return byte == ' ' || byte == '\t' || byte == '\n' || byte == '\r' ||
           byte == '\v' || byte == '\f';
}

static int is_ascii_vowel(int byte) {
    return byte == 'a' || byte == 'e' || byte == 'i' || byte == 'o' ||
           byte == 'u' || byte == 'A' || byte == 'E' || byte == 'I' ||
           byte == 'O' || byte == 'U';
}

int main(void) {
    size_t bytes = 0;
    size_t words = 0;
    size_t newlines = 0;
    size_t vowels = 0;
    size_t digits = 0;
    int previous_was_whitespace = 1;
    int last_byte = EOF;
    int input_byte;

    while ((input_byte = getchar()) != EOF) {
        const unsigned char byte = (unsigned char)input_byte;
        const int whitespace = is_ascii_whitespace(byte);
        ++bytes;
        if (whitespace && !previous_was_whitespace) {
            previous_was_whitespace = 1;
        } else if (!whitespace) {
            if (previous_was_whitespace) {
                ++words;
            }
            previous_was_whitespace = 0;
        }
        if (byte == '\n') {
            ++newlines;
        }
        if (is_ascii_vowel(byte)) {
            ++vowels;
        }
        if (byte >= '0' && byte <= '9') {
            ++digits;
        }
        last_byte = byte;
    }

    if (ferror(stdin)) {
        fputs("Error reading standard input.\n", stderr);
        return 1;
    }

    printf("Lines: %zu\n", newlines + (bytes > 0 && last_byte != '\n'));
    printf("Words: %zu\n", words);
    printf("Bytes: %zu\n", bytes);
    printf("Vowels: %zu\n", vowels);
    printf("Digits: %zu\n", digits);
    return 0;
}
