# File: napoli_38_hw3.py
# Created by: Michael Napoli
# Created on: 5/24/2021


# Problem 1
# determine if given integer array has all unique values
# NOTE: assumption that list is made up of integers, but any type
#       list should also work
def unique_list(n):
    # if the length of the set is equal to the array, unique list
    return len(n) == len(set(n))

# test cases
# print(unique_list(range(10)))  # unique list of integers
# print(unique_list([1, 2, 2]))  # non-unique list of integers


# Problem 2
# determine if given string contains all vowels, return bool
def vowel_search(S):
    s = set(S.lower())  # create set of lower characters
    # check for each vowel in the given string
    return ('a' in s) and ('e' in s) and ('i' in s) and ('o' in s) and ('u' in s)

# test cases
# print(vowel_search("All vowels with unicorns"))  # all vowels are present
# print(vowel_search("I needed as many letters"))  # not all vowels present
