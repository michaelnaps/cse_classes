# File: napoli_38_hw4.py
# Created by: Michael Napoli
# Due Date: 6/6/2021

import numpy
import string

# Problem 1
# given a sentence, find the most common letter
def most_common_letter(s):
    max = 0
    c = s.lower()
    n = numpy.zeros(26)
    alph = 'abcdefghijklmnopqrstuvwxyz'

    for i in range(0, len(alph)):
        if alph[i] in c:
            n[i] += 1
        if n[max] <= n[i]:
            max = i

    return alph[max]

# test cases
print(most_common_letter('AAAaa NNNNNNNNNN,ppPPPp Hht'))
print(most_common_letter('My name is Michael Napoli!!'))
