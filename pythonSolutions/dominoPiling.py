
'''
    given m x n board

    and 2 x 1 dominos, try to fill up board
    w as many dominos as possible


    if m is odd --> have all the rows except for last
    fill up dominoes vertically
    have last row fill up dominoes horizontally
'''

m, n = [int(x) for x in input().split(' ')]

dominoes = m // 2 * n

if m % 2 == 1:
    dominoes += n // 2

print(dominoes)

