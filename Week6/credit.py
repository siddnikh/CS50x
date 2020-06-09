import sys

#helper method to check if checksum for the card is right
def checksum(card):
    sum1 = 0
    sum2 = 0

    for i in range(len(card) - 2, -1, -2):
        n = int(card[i]) * 2

        if n > 9: #adding the digits
            while n != 0:
                sum1 += n % 10
                n = int(n / 10)
        else:
            sum1 += n
    print(sum1)
    for i in range(len(card) - 1, -1, -2):
        sum2 += int(card[i])
    print(sum2)
    #checking if digit at end is 0
    if (sum1 + sum2) % 10 == 0:
        return True
    return False

#helper method to check if the string obtained is an integer
def RepresentsInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

#taking input
card = input("Credit Card Number: ")

#checking for fundamentals lol
while len(card) < 13 or RepresentsInt(card) == False :
    card = input("Credit Card Number: ")

#checking the first few digits to recognise the card
if(checksum(card)):
    if card[ :2] == "34" or card[ :2] == "37":
        print("AMEX")
    elif card[ :2] in ["51", "52", "53", "54", "55"]:
        print("MASTERCARD")
    elif card[0] == "4":
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
