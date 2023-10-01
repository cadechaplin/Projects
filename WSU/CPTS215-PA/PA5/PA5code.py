'''
Cade Chaplin
PA5
4/9/2023
This program uses a hashmap, including two linked list, to store words from a text file in one set of linked lists,
as well as how many times the words occur in another linked list, the words and how many times they occur are recorded
in corresponding slots in each linked list.
'''
class Node:
    '''

    '''
    def __init__(self, data):
        '''

        '''

        self.data = data
        self.next = None

    def __str__(self):
        '''

        '''
        return str(self.data)


class LinkedList:
    '''

    '''
    def __init__(self):
        '''
        Creates a new list that is empty. It needs no parameters and returns an empty list.
        '''
        self.head = None

    def __str__(self):
        '''

        '''
        list_str = ""
        curr = self.head
        while curr is not None:
            list_str += str(curr)
            list_str += "->"
            curr = curr.next
        list_str += "None"
        return list_str

    def add(self, item):
        '''
        Adds a new item to the list. It needs the item and returns nothing. Assume the item is not already in the list.
        '''
        temp = Node(item)
        temp.next = self.head
        self.head = temp

    def append(self, item):
        '''
        Adds a new item to the end of the list making it the last item in the collection.
        It needs the item and returns nothing. Assume the item is not already in the list.
        '''
        if self.head is None:
            self.head = Node(item)
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            temp = Node(item)
            curr.next = temp

    def insert(self, index, item):
        '''
        Adds a new item to the list at position pos. It needs the item and returns nothing.
        Assume the item is not already in the list and there are enough existing items to have position pos.
        '''
        if index == 0 or self.head is None:
            self.add(item)
        else: # not adding at front. stop one before location
            curr = self.head
            i = 0
            while curr.next is not None and i < index - 1:
                curr = curr.next
                i += 1
            temp = Node(item)
            temp.next = curr.next
            curr.next = temp

    def pop(self, index=None):
        '''
        Removes and returns the item at position index. It needs the position and returns the item.
        If index is not specified, removes and returns the last item in the list.
        Assume the item is in the list.
        '''
        if self.head is None:
            return None

        if index is None:
            index = self.size() - 1

        if index == 0:
            curr = self.head
            self.head = self.head.next
            curr.next = None
            return curr
        else: # not popping front. stop one before location
            curr = self.head
            i = 1
            while curr.next is not None and i < index:
                curr = curr.next
                i += 1
            to_pop = curr.next
            curr.next = to_pop.next
            to_pop.next = None
            return to_pop

    def remove(self, item):
        '''
        Removes the item from the list. It needs the item and modifies the list. Assume the item is present in the list.
        '''
        current = self.head
        previous = None
        found = False

        while current != None and not found:
            if current.data == item:
                found = True
            else:
                previous = current
                current = current.next

        if found:
            if previous == None:
                self.head = current.next
                current.next = None
            else:
                previous.next = current.next
                current.next = None
        return found

    def search(self, item):
        '''
        Searches for the item in the list. It needs the item and returns the index of the item (-1 if not found).
        Combined a Boolean search(item) with index(item) function.
        '''
        current = self.head
        found = -1
        loc = 0

        while current != None and found == -1:
            if current.data == item:
                found = current
            else:
                current = current.next
            loc += 1

        return found

    def find(self, item):
        '''
        Searches for the item in the list. It needs the item and returns the index of the item (-1 if not found).
        Combined a Boolean search(item) with index(item) function.
        '''
        current = self.head
        found = -1
        loc = 0

        while current != None and found == -1:
            if current.data == item:
                found = loc
            else:
                current = current.next
            loc += 1

        return found

    def is_empty(self):
        '''
        Tests to see whether the list is empty. It needs no parameters and returns a boolean value.
        '''
        return self.head == None

    def size(self):
        '''
        Returns the number of items in the list. It needs no parameters and returns an integer.
        '''
        current = self.head
        count = 0
        while current != None:
            count = count + 1
            current = current.next

        return count
    def get(self, index):
        iter = 0
        node = self.head
        while node != None:
            if iter == index:
                return node
            node = node.next
            iter += 1
        return

class HashMap:
    def __init__(self, size=11):
        self.size = size
        self.keys = [None] * self.size # holds keys
        self.values = [None] * self.size # holds values
        self.word_count = 0


    def __str__(self):
        s = ""
        for slot, key in enumerate(self.keys):
            value = self.values[slot]
            s += str(key) + ":" + str(value) + ", "
        return s

    def __len__(self):

        return self.word_count
    def hashfunction(self, item):
        #return item % self.size
        sum = 0
        for c in item:
            sum += ord(c)
        return sum % self.size

    def put(self, key, value):
        hashvalue = self.hashfunction(key)
        slot_placed = -1
        self.word_count += 1
        if self.keys[hashvalue] == None : # empty slot or slot contains item already
            self.keys[hashvalue] = LinkedList()
            self.keys[hashvalue].append(key)
            self.values[hashvalue] = LinkedList()
            self.values[hashvalue].append(value)
            slot_placed = hashvalue
        else:
            index = self.keys[hashvalue].find(key)
            if index == -1:
                self.keys[hashvalue].append(key)
                self.values[hashvalue].append(value)
            else:
                node = self.values[hashvalue].get(index)
                node.data +=1
            '''
            nextslot = self.rehash(hashvalue)
            while (nextslot != hashvalue):
                if self.keys[nextslot] == None or self.keys[nextslot] == key:
                    self.keys[nextslot] = key
                    self.values[nextslot] = value
                    slot_placed = nextslot
                    break
                else:
                    nextslot = self.rehash(nextslot)
                    '''
        return slot_placed

    def __setitem__(self, key, data):
        self.put(key, data)
    def get(self, key):
        hashvalue = self.hashfunction(key)
        if self.keys[hashvalue] == None:
            return -1
        index = self.keys[hashvalue].find(key)
        if index == -1:
            return -1
        else:
            return self.values[hashvalue].get(index).data
    def __getitem__(self, key):
        return self.get(key)
    def remove(self, key):
        hashvalue = self.hashfunction(key)
        slot_placed = -1
        index = self.keys[hashvalue].find(key)
        if index == -1:
            return slot_placed
        else:
            self.word_count -= 1
            self.values[hashvalue].pop(index)
            self.keys[hashvalue].pop(index)
            self.keys[hashvalue].find(key)
            return slot_placed
    def __delitem__(self, key):
        self.remove(key)
    def __contains__(self, key):
        return self.get(key) != -1





def main():
    filename = input("Enter the name of the text file: ")

    try:
        file = open(filename, "r")
        print(f"Successfully opened {filename}")

    except FileNotFoundError:
        print(f"Error: could not open {filename}")
    Map = HashMap()
    text = file.read()
    text = text.lower()

    words = text.split()
    for word in words:
        if word[-1].isalpha() == False and word[-1] != "\'":
            word = word[:-1]
        Map.put(word,1)
    print("total count: ", Map.word_count)
    word = ""
    while word != "q" and word != "Q":
        print("enter a word to find its count, enter q or Q to exit.")
        word = input()
        output = Map.get(word)
        if word == "q" or word == "Q":
            return
        if output == -1:
            print(word, "not found.")
        else:
            print(word, "found", output, "times.")


if __name__ == '__main__':
    main()


