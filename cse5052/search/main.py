# Project: Search Algorithm
# Created by: Michael Napoli
# Created on: 9/20/2021
# Last modifies on: 9/20/2021

# Purpose: For the testing of various search algorithms
#     of both the uninformed and informed architecture.

# test case
g_1 = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 3],
    3: [2]
}

g_2 = {
    0: [1, 2],
    1: [0, 4],
    2: [0, 4, 5],
    3: [5],
    4: [1, 2, 6],
    5: [2, 3, 6],
    6: [4, 5],
    7: [8],
    8: [7]
}

def bfs(g, s, goal):
    k = list(g.keys())
    d = {k[i]: None for i in range(0, len(k))}

    d[s] = 0  # set s node to 0
    q = [s]  # initialize queue

    while q:
        i = q.pop(0)

        if g[i] != None:
            for j in range(0, len(g[i])):
                if d[g[i][j]] == None:
                    q.append(g[i][j])
                    d[g[i][j]] = d[i] + 1

    return d

# test case useage
print(bfs(g_1, 0))
print(bfs(g_2, 6))
