# File: napoli_38_hw4.py
# Created by: Michael Napoli
# Due Date: 6/6/2021

# All comments and test cases removed by request of Professor.

import string

# Problem 1
def most_common_letter(s):
    c = s.lower()
    max = c[0]
    alph = {element: 0 for element in string.ascii_lowercase}
    for i in range(0, len(c)):
        if (alph.get(c[i]) != None):
            alph[c[i]] += 1
            if (alph[c[i]] > alph[max]):
                max = c[i]
    return max


# Problem 2
def create_dict(index, item):
    if (len(index) != len(item)):
        print('ERROR: Arrays are not equal length.')
        return -1
    return {index[i]: item[i] for i in range(0, len(index))}


# Problem 3
def bisection_count(n):
    c = 1
    g = 50
    l = 0
    h = 101
    while (g != n):
        if g < n:
            l = g
        elif g > n:
            h = g
        g = int((l + h) / 2)
        c += 1
    return c


# Problem 4
def bisection_dict():
    d = {}
    for i in range(1, 101):
        c = bisection_count(i)

        if (d.get(c) == None):
            d[c] = 1
        else:
            d[c] += 1

    return d
