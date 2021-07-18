# File: napoli_38_hw4.py
# Created by: Michael Napoli
# Due Date: 6/6/2021

import string

# Problem 1
# given a sentence, find the most common letter
def most_common_letter(s):
    c = s.lower()           # convert sentence to lower case
    max = c[0]              # max element location (arbitrarily set to first letter)
    # create count dict. variable for letters in alphabet
    alph = {element: 0 for element in string.ascii_lowercase}

    # loop for letter count
    for i in range(0, len(c)):
        # check to ignore spacing and punctuation
        if (alph.get(c[i]) != None):
            # iterate count for current letter
            alph[c[i]] += 1

            # switch to new max element location
            if (alph[c[i]] > alph[max]):
                max = c[i]

    return max  # return most common letter found

# test cases
# print(most_common_letter('AAAaa NNNNNNNNNN,ppPPPp Hht'))
# print(most_common_letter('My name is Michael Napoli!!'))


# Problem 2
# create dictionary variable from two string variables
def create_dict(index, item):
    # check that arrays are equal
    if (len(index) != len(item)):
        print('ERROR: Arrays are not equal length.')
        return -1  # print message and return '-1'

    # otherwise, return dictionary created from two arrays
    return {index[i]: item[i] for i in range(0, len(index))}

# test cases
# print(create_dict(['a'], ['a', 'b']))  # error message test
# print(create_dict(['cat'], ['egg']))
# print(create_dict(['cat', 'dog', 'parrot'], ['egg', 'bacon', 'toast']))


# Problem 3
# count number of iterations for given value with bisection method
def bisection_count(n):
    c = 1    # initialize count variable to 0
    g = 50   # initialize guess to 50 (always)
    l = 0    # initialize range variables to 0 and 101
    h = 101


    # use bisection method to solve for user's guess
    while (g != n):  # infinite loop
        # adjust range based on current guess
        if g < n:
            l = g
        elif g > n:
            h = g

        g = int((l + h) / 2)  # divide range by two for next guess and truncate
        c += 1  # iterate guess counter

    return c

# test cases for bisection_count() function
# print(bisection_count(50))
# print(bisection_count(25))
# print(bisection_count(12))
# print(bisection_count(37))


# Problem 4
# create dictionary variable of number of guesses from bisection method (max 7)
def bisection_dict():
    d = {}  # initialize empty dictionary
    for i in range(1, 101):
        c = bisection_count(i)  # create count variable

        if (d.get(c) == None):
            d[c] = 1  # initialize new counts to 1
        else:
            d[c] += 1  # increment count values

    return d

# test dictionary function
# print(bisection_dict())
