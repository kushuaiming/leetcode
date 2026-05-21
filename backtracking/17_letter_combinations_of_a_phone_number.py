from typing import List


def letter_combinations(digits: str) -> List[str]:
    digit_letter_map = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    results = []
    result = ""

    def backtracking(result: str, start: int) -> None:
        if len(digits) == len(result):
            results.append(result)

        for i in range(start, len(digits)):
            for ch in digit_letter_map[digits[i]]:
                result += ch
                backtracking(result, i + 1)
                result = result[:-1]

    backtracking(result, 0)
    return results


digits = "23"
print(letter_combinations(digits))
