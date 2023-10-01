
# Title: PA2
# Author: Cade Chaplin
# Version: 1.0
# Date: Feb 27 2023
#
# Description: This program computes the times of different sorting methods
import csv
import numpy as np
import time
import sys
sys.setrecursionlimit(50000)
#done
def selectionsort(list, s, c):
    i = 0
    j = 0

    index = range(0, len(list)-1)

    for i in index:
        min = i
        for j in range(i+1, len(list)):
            c[0]= c[0]+1
            if list[j] < list[min]:
                min = j


        if min != i:
            list[i], list[min] = list[min], list[i]
            s[0] = s[0]+1
    return list

def bubblesort(list,s,c):
    index = range(0, len(list)-1)
    i = 0
    success = False
    while(success != True):
        success = True
        i = 0
        while i < len(list)-1:
            c[0]= c[0]+1
            if list[i] > list[i + 1]:

                list[i], list[i+1] = list[i+1], list[i]
                s[0] = s[0]+1
                success = False
            i=i+1

    return list

def insertsort(list,s,c):
    index = range(0, len(list))
    for i in index:
        val = list[i]
        c[0]= c[0]+1
        while list[i-1] > val and i>0:
            c[0]= c[0]+1
            list[i], list[i-1] = list[i-1], list[i]
            s[0] = s[0]+1
            i = i -1

    return list

def shellsort(list,s,c):
    split = len(list) // 2

    while split > 0:
        for i in range(split, len(list)):
            temp = list[i]
            j = i
            c[0] = c[0]+1
            while j>= split and list[j-split] > temp:
                list[j] = list[j-split]
                j = j-split
                s[0] = s[0]+1

            list[j]= temp
        split = split // 2

    return list



def mergesort(list,s,c):
    if len(list) > 1:

        left = list[:len(list)//2]
        #print("left:", left)
        right = list[len(list)//2:]
        #print("right:", right)
        mergesort(left,s,c)
        mergesort(right,s,c)
        i = 0 #left
        j = 0#right
        k = 0#merge

        while i < len(left) and j < len(right):
            c[0] = c[0]+1
            if left[i] < right[j]:
                list[k] = left[i]
                i += 1
                s[0] = s[0]+1

            else:
                list[k] = right[j]
                j += 1
                s[0] = s[0]+1

            k += 1
        while i < len(left):
            list[k] = left[i]
            s[0] = s[0]+1
            i += 1
            k += 1

        while j < len(right):
            list[k] = right[j]
            s[0] = s[0]+1
            j += 1
            k += 1
    return list

def split(list,s,c,low,high):
    i = low-1
    piv = list[high]
    for j in range(low, high):
        c[0] = c[0]+1
        if list[j] <= piv:
            i+= 1
            s[0] = s[0]+1
            list[i],list[j]= list[j], list[i]
    list[i+1], list[high]= list[high], list[i+1]
    return i+1

def newquicksort(list,s,c,low = 0, high = None):

    if high == None:
        high = len(list)-1
    if low < high:
        h = split(list, s,c,low, high)
        newquicksort(list,s,c, low, h-1)
        newquicksort(list,s,c, h+1, high)
#done
def output(col):#done
    with open('sort_results.csv', 'w', newline = '') as f:
        writer = csv.writer(f)

        writer.writerows(col)
#done
def datatime(lines, col,times, swaps, compares,test):#done
    i = 0
    lines = []
    lines.append(test)
    while i < 6:
        lines.append(times[i])
        lines.append(compares[i])
        lines.append(swaps[i])
        i = i +1
    col.append(lines)
    lines = []
#done
def header(lines, col):
    lines.append(" ")
    lines.append("selection sort")
    lines.append("")
    lines.append("")
    lines.append("bubble sort")
    lines.append("")
    lines.append("")
    lines.append("insertion sort")
    lines.append("")
    lines.append("")
    lines.append("shell sort")
    lines.append("")
    lines.append("")
    lines.append("merge sort")
    lines.append("")
    lines.append("")
    lines.append("quick sort")
    lines.append("")
    lines.append("")
    col.append(lines)
    lines = []
    lines.append("")
    i = 0
    while i < 6:
        lines.append("Time")
        lines.append("Data Comparisons")
        lines.append("Data Swaps")
        i = i +1
    col.append(lines)
    lines = []
#done
def speedtest(og,times,ss,cs):
    s = [0]
    c = [0]

    list = []

    list = og.copy()
    start_time = time.time()
    selectionsort(list,s,c)
    endtime = time.time()
    times.append(endtime-start_time)
    cs.append(c[0])
    ss.append(s[0])

    c[0]= 0
    s[0]= 0

    list = og.copy()
    start_time = time.time()
    bubblesort(list,s,c)
    endtime = time.time()
    times.append(endtime-start_time)

    cs.append(c[0])
    ss.append(s[0])

    c[0]= 0
    s[0]= 0

    list = og.copy()
    start_time = time.time()
    insertsort(list,s,c)
    endtime = time.time()
    times.append(endtime-start_time)
    cs.append(c[0])
    ss.append(s[0])
    c[0]= 0
    s[0]= 0

    list = og.copy()
    start_time = time.time()
    shellsort(list,s,c)
    endtime = time.time()
    times.append(endtime-start_time)
    cs.append(c[0])
    ss.append(s[0])
    c[0]= 0
    s[0]= 0

    list = og.copy()
    start_time = time.time()
    mergesort(list,s,c)
    endtime = time.time()
    times.append(endtime-start_time)
    cs.append(c[0])
    ss.append(s[0])
    c[0]= 0
    s[0]= 0

    list = og.copy()
    start_time = time.time()
    newquicksort(list,s,c)
    endtime = time.time()
    times.append(endtime-start_time)
    cs.append(c[0])
    ss.append(s[0])
    c[0]= 0
    s[0]= 0

def main():
    arr1 = np.random.randint(0, high=100, size=(250), dtype=int)
    arr2 = np.random.randint(0, high=100, size=(500), dtype=int)
    arr3 = np.random.randint(0, high=100, size=(1000), dtype=int)
    arr1 = arr1.tolist()
    arr2 = arr2.tolist()
    arr3 = arr3.tolist()
    aars = [arr1,arr2,arr3]
    lines = []
    col = []
    header(lines,col)
    test = ["Random 250","Random 500","Random 1000","Ascending 250","Ascending 500","Ascending 1000","Descending 250","Descending 500","Descending 1000"]
    nums = [1,2,3]
    i = 0
    for num in nums:

        if num == 2:
            aars[0].sort()
            aars[1].sort()
            aars[2].sort()

        if num == 3:
            aars[0].sort(reverse = True)
            aars[1].sort(reverse = True)
            aars[2].sort(reverse = True)
        for arr in aars:
            ss = []
            cs = []
            t = []
            speedtest(arr,t,ss,cs)
            datatime(lines, col,t,ss,cs,test[i])
            i += 1
    output(col)
if __name__ == '__main__':
    main()

