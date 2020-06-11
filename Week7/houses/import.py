import csv
import sys
import sqlite3

#Checking if they provided the right number of arguments
if len(sys.argv) != 2:
    print("Wrong usage")
    sys.exit()

#extracting name of the csv file provided
filename = sys.argv[1]

#just to seperate out the field names and the student rows
fields = []
students = []

with open(filename, 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    
    fields = next(csvreader)
    
    #getting everyone's details in one list, which will have MANY lists :P
    for row in csvreader:
        students.append(row)

#connecting to our sql database
conn = sqlite3.connect("students.db")

#iterating over details, one student at a time (one list at a time, from many lists)
for student in students:
    
    #this gives us the student's first and last name, seperately
    name = student[0].split()
    #if the student doesn't have a middle name
    if len(name) == 2:
        #explicitly executing the SQL command
        conn.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", (name[0], None, name[1], student[1], student[2]))
    #if the student does have a middle name
    else:
        conn.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", (name[0], name[1], name[2], student[1], student[2]))

conn.commit()
conn.close()