# File: napoli_38_hw3.py
# Created by: Michael Napoli
# Created on: 5/24/2021

# Problem 1
def unique_ints(n):
    # if the length of the set is equat to the array, all unique integers
    return len(n) == len(set(n))


# Problem 2
def vowel_search(s):
    str_list = s.lower()
    vow_list = [word for word in s if chr not in "aeiou"]
    return len(str_list) == len(vow_list)
