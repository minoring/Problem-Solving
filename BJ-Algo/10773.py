inputs = []
for _ in range(int(input())):
    input_num = int(input())
    if input_num == 0:
        inputs.pop()
    else:
        inputs.append(input_num)
print(sum(inputs))
