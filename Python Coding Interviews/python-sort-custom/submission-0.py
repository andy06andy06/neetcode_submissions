from typing import List



def sort_words(words: List[str]) -> List[str]:
    def word_length(word: str):
        return len(word)
    words.sort(key=word_length, reverse=True)
    return words



def sort_numbers(numbers: List[int]) -> List[int]:
    def absolute(number: int):
        return abs(number)
    numbers.sort(key=absolute)
    return numbers


# do not modify below this line
print(sort_words(["cherry", "apple", "blueberry", "banana", "watermelon", "zucchini", "kiwi", "pear"]))

print(sort_numbers([1, -5, -3, 2, 4, 11, -19, 9, -2, 5, -6, 7, -4, 2, 6]))
