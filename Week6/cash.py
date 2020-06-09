f = -1.0
while f < 0:
    f = float(input("Change owed: "))
QUARTER = 0.25
DIME = 0.10
NICKEL = 0.05
PENNY = 0.01

n_coins = 0
sum = 0
while sum != f:
    if sum + QUARTER <= f:
        sum += QUARTER
    elif sum + DIME <= f:
        sum += DIME
    elif sum + NICKEL <= f:
        sum += NICKEL
    elif sum + PENNY <= f:
        sum += PENNY
    n_coins += 1

print(n_coins)