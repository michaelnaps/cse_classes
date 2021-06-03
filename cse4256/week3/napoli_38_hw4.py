# File: napoli_38_hw4.py
# Created by: Michael Napoli
# Due Date: 6/6/2021

import numpy

# Problem 1
# given a sentence, find the most common letter
def most_common_letter(s):
    max = 0                                 # max element location
    c = s.lower()                           # convert sentence to lower case
    n = numpy.zeros(26)                     # array for counts of each letter
    alph = 'abcdefghijklmnopqrstuvwxyz'     # alphabet array for search

    # loop for letter count
    for i in range(0, len(alph)):
        for j in range(0, len(c)):
            if alph[i] == c[j]:
                n[i] += 1

        # check if the current letter is more common than current max
        if n[max] < n[i]:
            max = i

    return alph[max]  # return most common letter found

# test cases
# print(most_common_letter('AAAaa NNNNNNNNNN,ppPPPp Hht'))
# leaprint(most_common_letter('My name is Michael Napoli!!'))


# Problem 2
# create dictionary variable from two string variables
def create_dict(index, item):
    # check that lists are of equal length, if not return -1
    if (len(index) != len(item)):
        return -1

    d = {}  # initialize empty dictionary variable
    for i in range(0, len(index)):
        # create appropriately indexed dictionary
        d[index[i]] = item[i]

    return d


# test cases
# print(create_dict(['cat'], ['egg']))
# print(create_dict(['cat', 'dog', 'parrot'], ['egg', 'bacon', 'toast']))


# Problem 3
# count number of iterations for given value with bisection method
def bisection_count(n):
    c = 1    # initialize count variable to 0
    g = 50   # initialize guess to 50 (always)
    l = 0    # initialize range variables to 1 and 100
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


# Problem 4
# create dictionary variable of number of guesses from bisection method (max 7)
def bisection_dict():
    # initialize number of guess dictionary variable
    d = {1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0}
    for i in range(1, 101):
        d[bisection_count(i)] += 1

    return d

# test
# print(bisection_dict())
