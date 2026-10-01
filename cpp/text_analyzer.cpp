#include <cstddef>
#include <iostream>

namespace {
bool is_ascii_whitespace(unsigned char byte) {
    return byte == ' ' || byte == '\t' || byte == '\n' || byte == '\r' ||
           byte == '\v' || byte == '\f';
}

bool is_ascii_vowel(unsigned char byte) {
    return byte == 'a' || byte == 'e' || byte == 'i' || byte == 'o' ||
           byte == 'u' || byte == 'A' || byte == 'E' || byte == 'I' ||
           byte == 'O' || byte == 'U';
}
}  // namespace

int main() {
    std::size_t bytes = 0;
    std::size_t words = 0;
    std::size_t newlines = 0;
    std::size_t vowels = 0;
    std::size_t digits = 0;
    bool previous_was_whitespace = true;
    unsigned char last_byte = 0;
    bool has_input = false;
    char input_byte;

    while (std::cin.get(input_byte)) {
        const auto byte = static_cast<unsigned char>(input_byte);
        const bool whitespace = is_ascii_whitespace(byte);
        ++bytes;
        if (whitespace) {
            previous_was_whitespace = true;
        } else {
            if (previous_was_whitespace) {
                ++words;
            }
            previous_was_whitespace = false;
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
        has_input = true;
    }

    if (!std::cin.eof()) {
        std::cerr << "Error reading standard input.\n";
        return 1;
    }

    const std::size_t lines = newlines + (has_input && last_byte != '\n');
    std::cout << "Lines: " << lines << '\n'
              << "Words: " << words << '\n'
              << "Bytes: " << bytes << '\n'
              << "Vowels: " << vowels << '\n'
              << "Digits: " << digits << '\n';
    return 0;
}
