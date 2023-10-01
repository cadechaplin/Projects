
import csv
import numpy as np
import random
import time
import sys
sys.setrecursionlimit(50000)

print("enter times to run")
tests = input()
i = 0
nosw = 0
sw = 0
while i < int(tests):
    doors = [0,0,0]
    ans = random.randint(0,2)

    doors[ans] = 1

    choice = random.randint(0,2)
    j = 0
    replace = False
    while j < 3:
        if choice != j and doors[j] == 0 and replace == False:
            doors[j] = 2
            replace = True

        j += 1

    if doors[choice]== 1:
        nosw += 1
    else:
        sw += 1


    i += 1
print(nosw, sw)