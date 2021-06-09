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
print(balanced('())'))
print(balanced('((())'))
print(balanced('(())()'))


# Problem 2
def bfs(graph, start):
    v = []  # keep track of visited node
    q = []  # queue for tracking
    c = 0   # count from start
    d = []  # list of distances from start

    v.append(start)
    q.append(start)

    while q:
        c += 1
        i = q.pop(0)
        for n in graph[i]:
            if n not in v:
                v.append(n)
                q.append(n)
                d.append(c)
    return d

# test case
graph = {
    '1': ['2', '5'],
    '3': [],
    '4': ['3', '3', '7']
}

print(bfs(graph, '1'))
