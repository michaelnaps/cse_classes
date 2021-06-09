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
    c = len(graph)  # count variable for distance
    d = [[i] for i in range(1, len(graph) + 1)]  # distance from start varaible
    index = list(graph.keys())

    for i in range(0, len(index)):
        for j in range(0, len(graph[index[i]])):
            c += 1
            d[i].append(c)

    return d

# test case
graph = {
    0: [2, 5],
    1: [3, 6]
}

print(bfs(graph, 1))
