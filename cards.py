'''
    given a string consisting of lower case
    letters that make up the words zero and one

    print the max possible number in binary
    notation formed from the digits from the
    mixed up str

    input guaranteed to rearrange letters
    to form a sequence of words of zero or one

    --> keep track of z's and n's, this gives
    num of zeros and ones
'''

n = int(input())

zeros = ones = 0

for c in input():
    if c == 'z':
        zeros += 1
    elif c == 'n':
        ones += 1

out = ''
for _ in range(ones):
    out += '1 '

for _ in range(zeros):
    out += '0 '

print(out)