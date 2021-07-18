# File: napoli_38_hw8.py
# Created by: Michael Napoli
# Due Date: 6/29/2021

import math
import random as rdm

# Problem 1: Pentagonal Number
def pentagonal_num(n):
    if n != 1:
        c = 5 * (n - 1)
        return (c + pentagonal_num(n - 1))

    return 1

# test case
# print(pentagonal_num(1))  # 1
# print(pentagonal_num(2))  # 6
# print(pentagonal_num(3))  # 16
# print(pentagonal_num(4))  # 31


# Problem 2: Encode/Decode
def encode(dec):
    enc = ''  # initialize empty char array
    c_count = 1  # count since last different letter
    c_last = dec[0]  # first letter

    for i in range(1, len(dec)):
        if c_last != dec[i]:
            enc += str(c_count) + c_last
            c_count = 0  # reset count
        c_last = dec[i]  # update last letter
        c_count += 1  # iterate count

    # add last iteration of loop
    return enc + str(c_count) + c_last

def decode(enc):
    dec = ''  # empty character list variable

    # assumption: only single digit integers
    for i in range(0, len(enc), 2):
        dec += int(enc[i]) * enc[i+1]

    return dec

# test case
dec = 'AAAABBBCCDXX'
enc = encode(dec)
# print(enc)
# print(decode(enc))


# Problem 3: Balanced Braces
# check if given brace is closing brace
def is_closing_brace(c):
    return c == ')' or c == ']' or c == '}'

# check if two braces are compatible
def is_appr_brace(open, close):
    if open == '(':
        return close == ')'
    elif open == '[':
        return close == ']'
    elif open == '{':
        return close == '}'

    return False  # if given character(s) are not braces

# check if string of braces are valid
def is_balanced(s):
    b = list(s)  # create deque variable from string

    c = [b.pop(0)]  # pop first element into character deque
    if is_closing_brace(c[0]):  # check if first brace is closing
        return False

    for i in range(0, len(b)):
        c.append(b.pop(0))
        if is_closing_brace(c[-1]) and is_appr_brace(c[-2], c[-1]):
            c.pop(-1)  # pop last two elements
            c.pop(-1)

    # check that c and b are empty
    return len(c) == 0 and len(b) == 0

# test cases
# print(is_balanced('[]{}{()}'))
# print(is_balanced('[{{]'))
# print(is_balanced('[{]}'))


# Problem 4: Monte Carlo Method
def monte_carlo():
    in_c = 0
    total_c = 0

    for i in range(0, 1000000000): # arbitrary number of iterations
        x_rdm = rdm.random()
        y_rdm = rdm.random()

        if math.sqrt(x_rdm**2 + y_rdm**2) < 1:
            in_c += 1

        total_c += 1

    return (in_c / total_c) * 4

# test cases
print(monte_carlo())
