import sys
import csv

def str_number(dna_seq, str):
    seq_count = 0
    number = 0
    for i in range(0, len(dna_seq) - len(str)):
        if dna_seq[i: i + len(str)] == str:
            seq_count = 0
            for j in range(i, len(dna_seq) - len(str), len(str)):
                if dna_seq[j: j + len(str)] == str:
                    seq_count += 1
                else:
                    break
        if seq_count > number:
            number = seq_count
    
    return number

#first, get a csv file path
#second, get a dna sequence file path
if len(sys.argv) != 3:
    print("Wrong usage")
    sys.exit()

csv_filename = sys.argv[1]
dna_seq = sys.argv[2]

fields = []
rows = []

with open(csv_filename, 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    fields = next(csvreader)
    
    for row in csvreader:
        rows.append(row)

dna = ""
with open(dna_seq, 'r') as txt:
    dna = txt.read()

seq = ["sequences"]

for i in range( 1, len(fields)):
    seq.append(str(str_number(dna, fields[i])))

for row in rows:
    match = False
    if row[1:] == seq[1:]:
        print (row[0])
        sys.exit()
print("No Match")