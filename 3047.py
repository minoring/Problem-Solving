l = sorted(input().split(), key=int)
print(' '.join(str(l[ord(x) - 65]) for x in input()))