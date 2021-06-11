# File: napoli_38_hw5.py
# Created by: Michael Napoli
# Due Date: 6/12/2021

# Comments and test cases removed by request of Professor.

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


# Problem 2
def bfs(graph, start):
    k = list(graph.keys())
    d = {k[i]: None for i in range(0, len(k))}

    d[start] = 0
    q = [start]

    while q:
        i = q.pop(0)

        if graph[i] != None:
            for j in range(0, len(graph[i])):
                if d[graph[i][j]] == None:
                    q.append(graph[i][j])
                    d[graph[i][j]] = d[i] + 1

    return d


# Problem 3
def is_connected(graph):
    k = list(graph.keys())

    for i in range(0, len(k)):
        d = bfs(graph, k[i])
        if None in d.values():
            return False

    return True


# Problem 4
def connected_components(graph):
    if is_connected(graph):
        return 1

    n = 0
    g = dict(graph)
    cc = {}
    while g:
        k = list(g.keys())

        for i in range(0, len(k)):
            if g[k[i]] != None:
                st = k[i]

        cc = bfs(g, st)
        for i in range(0, len(k)):
            if cc[k[i]] != None:
                del g[k[i]]

        n += 1

    return n
