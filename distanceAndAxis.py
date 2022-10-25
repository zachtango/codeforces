

'''
    given point A on the x axis and O at 0

    find an integer B such that the abs diff
    between the distance of O to B and A to B is k

    3 cases k == A, k > A, k < A

'''

t = int(input())

for _ in range(t):
    moves = 0

    A, k = [int(x) for x in input().split(' ')]

    if k > A:
        moves = k - A
    elif k < A and (A - k) % 2 == 1:
        moves = 1

    print(moves)


