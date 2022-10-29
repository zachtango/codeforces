from sys import stdin, stdout

t = int(stdin.readline())


for _ in range(t):

    n = int(stdin.readline())
    a = [int(x) for x in stdin.readline().split()]

    maxScore = 0

    for i in range(n):
        score = 0
        pos = i

        while pos < n:
            score += a[pos]
            pos += a[pos]

        maxScore = max(maxScore, score)

    stdout.write(str(maxScore) + '\n')