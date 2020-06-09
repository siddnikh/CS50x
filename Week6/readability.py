import re
string = input("Enter the sentence: ")

words = len(re.split(r' ', string)) 
sentences = len(re.split(r'[.!?]+', string)) - 1
symbols = string.count('.') + string.count(' ') + string.count('?') + string.count('!') + string.count('\'') + string.count(',') + string.count(';')
letters = len(string) - symbols

L = (letters / words) * 100

S = (sentences / words) * 100

index = (0.0588 * L) - (0.296 * S) - 15.8
level = round(index)

if level >= 16:
    print("Grade 16")
elif level < 1:
    print("Before Grade 1")
else:
    print("Grade {}".format(level))