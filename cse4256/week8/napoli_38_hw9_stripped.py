# File: napoli_38_hw9.py
# Created by: Michael Napoli
# Due date: 7/5/2021

# Comments and test cases removed for submission.

# Problem 1
def look_and_say(row_num):
    d = 1

    for i in range(0, row_num):
        if i == 0:
            print(d)
        else:
            l = [int(q) for q in str(d)]
            c = 1
            p = ''
            digit = l[0]

            for j in range(1, len(l)):
                if digit != l[j]:
                    p += str(c) + str(digit)
                    c = 0
                digit = l[j]
                c += 1

            p += str(c) + str(digit)
            d = int(p)
            print(d)

    return True

# Problem 2
def shortest_path(s):
    sp = []
    l = s.split('/')

    for i in range(0, len(l)):
        sp.append(l.pop(0))

        if sp[-1] == '.':
            sp.pop(-1)
        elif sp[-1] == '..':
            sp.pop(-1)
            sp.pop(-1)

    return '/'.join(sp)
