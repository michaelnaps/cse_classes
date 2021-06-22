# File: napoli_38_hw7.py
# Created by: Michael Napoli
# Due Date: 6/24/2021

# Comments and test cases by request of Professor.

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


# Problem 2
def complement2(d):
    k = list(d.keys())
    cd = {k[i]: None for i in range(0, len(k))}

    for i in range(0, len(d)):
        for j in range(0, len(k)):
            if k[j] not in d[k[i]] and i != j:
                if cd[k[i]] == None:
                    cd[k[i]] = [k[j]]
                else:
                    cd[k[i]].append(k[j])

    return cd


# Problem 3
def transpose1(m):
    tm = [[0 for j in range(0, len(m))] for i in range(0, len(m))]

    for i in range(0, len(m)):
        for j in range(0, len(m[i])):
            if m[i][j] == 1:
                m[i][j] = 0
                tm[j][i] = 1

    return tm


# Problem 4
def transpose2(d):
    k = list(d.keys())
    td = {k[i]: None for i in range(0, len(k))}

    for i in range(0, len(d)):
        for j in range(0, len(d[k[i]])):
            if d[k[i]] is not None:
                if td[d[k[i]][j]] is None:
                    td[d[k[i]][j]] = [k[i]]
                else:
                    td[d[k[i]][j]].append(k[i])

    return td
