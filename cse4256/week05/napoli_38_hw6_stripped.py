# File: napoli_38_hw6.py
# Created by: Michael Napoli
# Due date: 6/19/2021

# Comments and test cases removed by request of Professor.

# Problem 1 - solution given

# Problem 2
def dict_to_list(d):
    k = list(d.keys())
    l = []

    for i in range(0, len(k)):
        for j in range(0, len(d[k[i]])):
            if (d[k[i]][j], k[i]) not in l:
                l.append((k[i], d[k[i]][j]))

    return l


# Problem 3
def list_to_dict(l):
    k = list({l[i][j] for i in range(0, len(l)) for j in range(0, len(l[i]))})
    d = {k[i]: None for i in range(0, len(k))}

    for i in range(0, len(l)):
        if d[l[i][0]] == None:
            d[l[i][0]] = [l[i][1]]
        else:
            d[l[i][0]].append(l[i][1])

        if d[l[i][1]] == None:
            d[l[i][1]] = [l[i][0]]
        else:
            d[l[i][1]].append(l[i][0])

    return d


# Problem 4
def list_to_matrix(l):
    k = list({l[i][j] for i in range(0, len(l)) for j in range(0, len(l[i]))})
    m = [[0 for i in range(0, len(k))] for i in range(0, len(k))]

    for i in range(0, len(k)):
        for j in range(0, len(l)):
            if k[i] == l[j][0]:
                m[k[i]][l[j][1]] = 1
            if k[i] == l[j][1]:
                m[k[i]][l[j][0]] = 1

    return m


# Problem 5
def matrix_to_dict(m):
    d = {i: None for i in range(0, len(m))}

    for i in range(0, len(m)):
        for j in range(0, len(m[i])):
            if m[i][j] == 1:
                if d[i] == None:
                    d[i] = [j]
                else:
                    d[i].append(j)

    return d


# Problem 6
def matrix_to_list(m):
    l = []

    for i in range(0, len(m)):
        for j in range(0, len(m[i])):
            if m[i][j] != 0 and (j, i) not in l:
                l.append((i, j))

    return l
