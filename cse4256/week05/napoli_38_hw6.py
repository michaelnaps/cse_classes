# File: napoli_38_hw6.py
# Created by: Michael Napoli
# Due date:

# Problem 1 - solution given


# Problem 2
def dict_to_list(d):
    k = list(d.keys())  # list of dictionary keys
    l = []  # empty list variable

    for i in range(0, len(k)):
        for j in range(0, len(d[k[i]])):
            if (d[k[i]][j], k[i]) not in l:
                l.append((k[i], d[k[i]][j]))

    return l

# test cases
graph_1 = {
    0: [1, 2],
    1: [0, 2, 4],
    2: [0, 1, 3],
    3: [2, 4],
    4: [1, 3]
}

graph_2 = {
    'A': ['C', 'E'],
    'B': ['C', 'D'],
    'C': ['A', 'B', 'D'],
    'D': ['C', 'B', 'E'],
    'E': ['A', 'D']
}

# print(dict_to_list(graph_1))
# print(dict_to_list(graph_2))


# Problem 3
def list_to_dict(l):
    # create set of keys
    k = list({l[i][j] for i in range(0, len(l)) for j in range(0, len(l[i]))})
    # empty dictionary with appropriate keys
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

# test cases
list_1 = dict_to_list(graph_1)
# print(list_to_dict(list_1))
list_2 = dict_to_list(graph_2)
# print(list_to_dict(list_2))


# Problem 4
def list_to_matrix(l):
    # create key variable list
    k = list({l[i][j] for i in range(0, len(l)) for j in range(0, len(l[i]))})
    # initialize matrix of graph details, set all to 0
    m = [[0 for i in range(0, len(k))] for i in range(0, len(k))]

    for i in range(0, len(k)):
        for j in range(0, len(l)):
            if k[i] == l[j][0]:
                m[k[i]][l[j][1]] = 1
            if k[i] == l[j][1]:
                m[k[i]][l[j][0]] = 1

    return m

# test cases
print(list_1)
print(list_to_matrix(list_1))


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

# test cases
matrix_1 = list_to_matrix(list_1)
# print(matrix_1)
# print(matrix_to_dict(matrix_1))


# Problem 6
def matrix_to_list(m):
    l = []  # empty list

    for i in range(0, len(m)):
        for j in range(0, len(m[i])):
            if m[i][j] != 0 and (j, i) not in l:
                l.append((i, j))

    return l

# test cases
print(matrix_1)
print(matrix_to_list(matrix_1))
