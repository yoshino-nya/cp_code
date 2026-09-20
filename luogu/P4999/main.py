sum = 0
for i in range(1000):
	while i > 0:
		sum += i % 10
		i //= 10

print(sum)