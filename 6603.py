import sys
input = sys.stdin.readline
print = sys.stdout.write

def comb(chosen, remained):
    if len(chosen) == 6:
        print(' '.join(chosen) + '\n')
        return
    
    for i in range(len(remained)):
        chosen.append(remained[i])
        comb(chosen, remained[i + 1: ])
        chosen.pop()

while(1):
    l = input().split()
    if l[0] == '0':
        break
    l = l[1:]
    comb([], l)
    print('')