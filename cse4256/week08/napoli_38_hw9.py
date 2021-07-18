# File: napoli_38_hw9.py
# Created by: Michael Napoli
# Due date: 7/5/2021

# Problem 1
def look_and_say(data, row_num):
    d = data  # create modifiable copy of positive integer

    for i in range(0, row_num):
        if i == 1:
            print(data)
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

            # reset loop variables
            p += str(c) + str(digit)
            d = int(p)
            print(d)

    return True  # no return necessary, always true

# test cases
# print(look_and_say(1, 5))
# print(look_and_say(32, 3))


# Problem 2
def shortest_path(s):
    sp = []  # initialize empty list
    l = s.split('/')  # create list of path id's

    for i in range(0, len(l)):
        sp.append(l.pop(0))

        if sp[-1] == '.':
            sp.pop(-1)  # ignore
        elif sp[-1] == '..':
            sp.pop(-1)
            sp.pop(-1)

    return '/'.join(sp)

# test cases
# print(shortest_path('/usr/bin/../bin/./scripts/../'))
# print(shortest_path('/mnt/joaquin/../joaquin/../usr/bin/./test/..'))
