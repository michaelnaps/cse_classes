# File: napoli_38_hw7.py
# Created by: Michael Napoli
# Due Date: 6/24/2021

# Problem 1
def complementw2(m):
    cm = [[0 for j in range(0, len(m))] for i in range(0, len(m))]

    for i in range(0, len(m)):
        for j in range(0, len(m[i])):
            if m[i][j] == 0 and i != j:
                cm[i][j] = 1
            elif m[i][j] == 1:
                cm[i][j] = 0

    return cm

# test cases
mat_1 = [
    [0, 1, 0, 0],
    [1, 0, 0, 1],
    [0, 0, 0, 1],
    [0, 1, 1, 0]
    ]

print(complementw2(mat_1))
