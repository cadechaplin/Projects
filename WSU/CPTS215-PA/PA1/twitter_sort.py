import csv



def read_tweets(file):


    read = file.readlines()
    i = 0
    tweetList = list()
    for row in read:
        AtList = list()

        curRow = row
        curRow = curRow.split("\"", 1)
        AtList.append(curRow[0])
        curRow = curRow[1]
        curRow = curRow.rsplit(":", 2)
        AtList.append(curRow[-1])
        AtList.append(curRow[-2])
        curRow = curRow[-3]

        curRow = curRow.rsplit(" ", 4)
        AtList.append(curRow[-1])
        AtList.append(curRow[-2])
        AtList.append(curRow[-3])
        AtList.append(curRow[-4])
        AtList.append(curRow[-5])


        curDict = {
        "user" : AtList[0],
        "second" : AtList[1],
        "minute" :AtList[2],
        "hour" : AtList[3],
        "day" : AtList[4],
        "month" : AtList[5],
        "year" : AtList[-2],
        "tweet" : AtList[-1]


            }
        tweetList.append(curDict)


    return tweetList






def merge_tweets(list1, list2):
    merged_list = list()
    while 0 < len(list1) + len(list2):

        if len(list1) == 0:
            merged_list.append(list2.pop())

        else:
            if len(list2) == 0:
                merged_list.append(list1.pop())

            else:
                if (find(list1[0], list2[0])) == False:
                    merged_list.append(list1.pop())

                else:
                    merged_list.append(list2.pop())

        #print(len(list1) + len(list2))
        #print(merged_list[-1])


    return merged_list

def find(item1, item2):
    if item1["year"] == item2["year"]:
        if item1["month"] == item2["month"]:
            if item1["day"] == item2["day"]:
                if item1["hour"] == item2["hour"]:
                    if item1["minute"] == item2["minute"]:
                        return item1["second"] < item2["second"]
                    else:
                        return item1["minute"] < item2["minute"]
                else:
                    item1["hour"] < item2["hour"]
            else:
                item1["day"] < item2["day"]
        else:
            item1["month"] < item2["month"]
    else:
        return item1["year"] < item2["year"]



def write_tweets(merged):
    file = open('merged.txt', 'w')
    for rows in merged:
        #file.write(list(rows["user"], "  /",  rows["tweet"], " ", rows["year"], " ", rows["month"], " ", rows["day"], " ", rows["hour"], " ", rows["minute"], ";", rows["second"]))
        file.write(rows["user"])
        file.write("\"")
        file.write(rows["tweet"])
        file.write(" ")
        file.write(rows["year"])
        file.write(" ")
        file.write(rows["month"])
        file.write(" ")
        file.write(rows["day"])
        file.write(":")
        file.write(rows["hour"])
        file.write(":")
        if(rows["second"][-1] != "\n"):
            rows["second"] = rows["second"] + "\n"
        file.write(rows["second"])






def main():
    file = open('tweet1.txt', 'r')
    list1 = read_tweets(file)
    file = open('tweet2.txt', 'r')
    list2 = read_tweets(file)
    merged = merge_tweets(list1, list2)
    write_tweets(merged)

if __name__ == '__main__':
    main()