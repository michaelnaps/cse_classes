# File: napoli_38_hw9.py
# Created by: Michael Napoli
# Due date: 7/5/2021

# Problem 1
def look_and_say(data, row_num):
    d = data
    print(data)

    for i in range(0, row_num):
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

# test cases
print(look_and_say(1, 5))
print(look_and_say(32, 3))
