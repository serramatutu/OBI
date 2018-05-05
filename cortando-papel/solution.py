n = int(input())
a = [int(x) for x in input().split()]
b = [x+0.5 for x in a]
b.pop()
c = 2
for i in b:
	up = sum(x > i and (index == 0 or a[index - 1] <= i) for index, x in enumerate(a)) + 1
	if c < up:
		c = up
print(c)
