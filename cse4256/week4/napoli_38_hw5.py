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
# print(balanced('())'))
# print(balanced('((())'))
# print(balanced('(())()'))


# Problem 2
def bfs(graph, start):
    k = list(graph.keys())
    d = {k[i]: None for i in range(0, len(k))}

    d[start] = 0  # set start node to 0
    q = [start]  # initialize queue

    while q:
        i = q.pop(0)

        if graph[i] != None:
            for j in range(0, len(graph[i])):
                if d[graph[i][j]] == None:
                    q.append(graph[i][j])
                    d[graph[i][j]] = d[i] + 1

    return d

# test case
graph_1 = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 3],
    3: [2]
}

graph_2 = {
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

# print(bfs(graph_1, 2))
print(bfs(graph_2, 0))
print(bfs(graph_2, 6))


# Problem 3
def is_connected(graph):
    k = list(graph.keys())

    for i in range(0, len(k)):
        d = bfs(graph, k[i])
        if None in d.values():
            return False

    # if loop exits, graph is connected
    return True

# test cases
# print(is_connected(graph_1))  # connected graph
# print(is_connected(graph_2))  # disconnected graph


# Problem 4
def connected_components(graph):
    # if graph is connected, there is only 1 component
    if is_connected(graph):
        return 1

    # else, count components individually
    n = 0  # count integer
    g = dict(graph)  # copy of given graph variable
    cc = {}  # arbitrary starting point for loop
    while g:
        # update variables
        k = list(g.keys())

        # look for starting point in graph
        for i in range(0, len(k)):
            if g[k[i]] != None:
                st = k[i]

        cc = bfs(g, st)  # arbitrary starting point
        for i in range(0, len(k)):
            if cc[k[i]] != None:
                del g[k[i]]

        # iterate count
        n += 1

    return n

# test cases
print(connected_components(graph_1))  # output should be 1
print(connected_components(graph_2))  # output should be 2
