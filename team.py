

n = int(input())

counter = 0

for _ in range(n):
    team = input().split(' ')

    if team[0] == '0' and team[1] == '0' or \
        team[0] == '0' and team[2] == '0' or \
        team[1] == '0' and team[2] == '0':
        continue

    counter += 1

print(counter)