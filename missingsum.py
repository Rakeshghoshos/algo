n = int(input("enter the number of elements"))
l = []
t = []
print("enter the elements")
for i in range(n):
    x = int(input())
    l.append(x)
for i in range(n+1):
    c = 0
    c = l.count(i)
    if c == 0:
        t.append(i)

print(t)