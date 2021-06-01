# File: napoli_38_hw4.py
# Created by: Michael Napoli
# Due Date: 6/6/2021

import numpy
import string

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

    return alph[max]

# test cases
# print(most_common_letter('AAAaa NNNNNNNNNN,ppPPPp Hht'))
# print(most_common_letter('My name is Michael Napoli!!'))


# Problem 2
