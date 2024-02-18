update = []
retire = []
cy = int(input())
n = int(input())
for i in range(n):
    a = input().split()
    y = int(a[2])
    id = a[0]
    if y <= cy-3: retire.append(id)
    else: update.append(id)
print("ACTUALIZAR")
for id in update: print(id)
print("RETIRAR")
for id in retire: print(id)
