n = int(input("Height: "))
while( n < 1 or n > 8):
    n = int(input("Height: "))
x = 1
for i in range(n):
    print(" " * (n - x), end = "")
    print("#" * x)
    x += 1