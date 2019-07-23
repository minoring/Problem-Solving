words = set() 
for _ in range(int(input())):
    words.add(input())

for w in sorted(sorted(words), key=len):
    print(w)