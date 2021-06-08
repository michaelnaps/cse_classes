# File: napoli_38_hw5.py
# Created by: Michael Napoli
# Due Date: 6/12/2021


# Problem 1
def balanced(s):
    o = 0
    c = 0

    for i in range(0, len(s)):
        if (s[i] == '('):
            o += 1
        elif (s[i] == ')'):
            c += 1

    return (o == c)

# test cases
print(balanced('())'))
print(balanced('((())'))
print(balanced('(())()'))


# Problem 2
