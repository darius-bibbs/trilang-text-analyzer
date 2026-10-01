import unittest

from python.text_analyzer import analyze


class AnalyzeTests(unittest.TestCase):
    def test_counts_text_without_trailing_newline(self):
        self.assertEqual(
            analyze(b"Hello, world! 42"),
            {"Lines": 1, "Words": 3, "Bytes": 16, "Vowels": 3, "Digits": 2},
        )

    def test_counts_newlines_and_empty_lines(self):
        self.assertEqual(
            analyze(b"one\n\ntwo\n"),
            {"Lines": 3, "Words": 2, "Bytes": 9, "Vowels": 3, "Digits": 0},
        )

    def test_empty_input(self):
        self.assertEqual(
            analyze(b""),
            {"Lines": 0, "Words": 0, "Bytes": 0, "Vowels": 0, "Digits": 0},
        )

    def test_utf8_is_counted_as_bytes(self):
        self.assertEqual(analyze("café".encode()), {
            "Lines": 1, "Words": 1, "Bytes": 5, "Vowels": 1, "Digits": 0,
        })


if __name__ == "__main__":
    unittest.main()
