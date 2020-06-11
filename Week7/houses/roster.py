import sqlite3
import sys

#checking for wrong usage
if len(sys.argv) != 2:
    print("Wrong usage")
    sys.exit()

#getting the house name provided
house = sys.argv[1]

#connecting to our database
db = sqlite3.connect("students.db")

#the db.execute (as opposed to some documentation I read, returns a list of tuples)
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last ASC, first ASC", (house,))

for student in students:
    #checking for the student's middle name
    if student[2] != None:
        print("{} {} {}, born {}".format(student[1], student[2], student[3], student[5]))
    else:
        print("{} {}, born {}".format(student[1], student[3], student[5]))
        
db.close()