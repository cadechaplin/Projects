'''
Cade Chaplin
PA4
This project implements a binary and ternary max heap and then tests them to make sure they funciton correctly
'''
import sys
from numpy import random
sys.setrecursionlimit(15099990)
class BinaryHeap:
    '''

    '''
    def __init__(self):
        '''
        heap_list[0] = 0 is a dummy value (not used)
        '''
        self.heap_list = [0]
        self.size = 0

    def __str__(self):
        '''

        '''
        return str(self.heap_list)

    def __len__(self):
        '''

        '''
        return self.size

    def __contains__(self, item):
        '''

        '''
        return item in self.heap_list

    def is_empty(self):
        '''
        compare the size attribute to 0
        '''
        return self.size == 0
        # To Be Implemented
        pass

    def find_max(self):
        '''
        the smallest item is at the root node (index 1)
        '''
        # To Be Implemented
        if self.is_empty():
            return None
        return self.heap_list[1]

    def insert(self, item):
        '''
        append the item to the end of the list (maintains complete tree property)
        violates the heap order property
        call percolate up to move the new item up to restore the heap order property
        '''
        self.heap_list.append(item)

        self.size += 1

        self.percolate_up(self.size)

        # To Be Implemented
        pass

    def del_max(self):
        '''
        min item in the tree is at the root
        replace the root with the last item in the list (maintains complete tree property)
        violates the heap order property
        call percolate down to move the new root down to restore the heap property
        '''
        if self.is_empty():
            return None

        max_val = self.heap_list[1]
        self.heap_list[1] = self.heap_list[self.size]
        self.heap_list.pop()

        self.size -= 1

        self.percolate_down(1)
        return max_val
        # To Be Implemented


    def max_child(self, index):
        '''
        return the index of the smallest child
        if there is no right child, return the left child
        if there are two children, return the smallest of the two
        '''
        if (index *2)+1 > self.size:
            return index * 2
        else:
            if self.heap_list[index * 2] > self.heap_list[index * 2 +1]:
                return index * 2
            else:
                return index *2 +1
        # To Be Implemented


    def build_heap(self, alist):
        '''
        build a heap from a list of keys to establish complete tree property
        starting with the first non leaf node
        percolate each node down to establish heap order property
        '''
        index = len(alist) // 2 # any nodes past the half way point are leaves
        self.size = len(alist)
        self.heap_list = [0] + alist[:]
        while (index > 0):
            self.percolate_down(index)
            index -= 1
        # To Be Implemented


    def percolate_up(self, index):
        '''
        compare the item at index with its parent
        if the item is less than its parent, swap!
        continue comparing until we hit the top of tree
        (can stop once an item is swapped into a position where it is greater than its parent)
        '''
        while index // 2 > 0:
            if self.heap_list[index] > self.heap_list[index // 2]:
                self.heap_list[index], self.heap_list[index // 2] =  self.heap_list[index // 2],self.heap_list[index]

            index = index // 2
        # To Be Implemented
        pass

    def percolate_down(self, index):
        '''
        compare the item at index with its smallest child
        if the item is greater than its smallest child, swap!
        continue continue while there are children to compare with
        (can stop once an item is swapped into a position where it is less than both children)
        '''
        while (index * 2) <= self.size :
            mc = self.max_child(index)
            if self.heap_list[index] < self.heap_list[mc]:
                self.heap_list[index],self.heap_list[mc] = self.heap_list[mc], self.heap_list[index]

            index = mc


        return
        # To Be Implemented
class TernaryHeap:
    '''

    '''
    def __init__(self):
        '''
        heap_list[0] = 0 is a dummy value (not used)
        '''
        self.heap_list = [0]
        self.size = 0

    def __str__(self):
        '''

        '''
        return str(self.heap_list)

    def __len__(self):
        '''

        '''
        return self.size

    def __contains__(self, item):
        '''

        '''
        return item in self.heap_list

    def is_empty(self):
        '''
        compare the size attribute to 0
        '''
        return self.size == 0
        # To Be Implemented
        pass

    def find_max(self):
        '''
        the smallest item is at the root node (index 1)
        '''
        # To Be Implemented
        if self.is_empty():
            return None
        return self.heap_list[1]

    def insert(self, item):
        '''
        append the item to the end of the list (maintains complete tree property)
        violates the heap order property
        call percolate up to move the new item up to restore the heap order property
        '''
        self.heap_list.append(item)

        self.size += 1

        self.percolate_up(self.size)

        # To Be Implemented


    def del_max(self):
        '''
        min item in the tree is at the root
        replace the root with the last item in the list (maintains complete tree property)
        violates the heap order property
        call percolate down to move the new root down to restore the heap property
        '''
        if self.is_empty():
            return None

        max_val = self.heap_list[1]
        self.heap_list[1] = self.heap_list[self.size]
        self.heap_list.pop()

        self.size -= 1

        self.percolate_down(1)
        return max_val
        # To Be Implemented


    def max_child(self, index):
        '''
        return the index of the smallest child
        if there is no right child, return the left child
        if there are two children, return the smallest of the two
        '''
        if (index * 3)+1 > self.size:
            if (index * 3) > self.size:
                return (index * 3 )-1
            else:
                if self.heap_list[index * 3-1] > self.heap_list[index * 3]:
                    return index * 3-1
                else:
                    return index * 3
        else:
            if self.heap_list[index * 3 ] >= self.heap_list[index * 3 -1] and self.heap_list[index * 3 ] >= self.heap_list[index * 3 +1]:
                return index * 3
            elif  self.heap_list[index * 3 +1 ] >= self.heap_list[index * 3 -1] and self.heap_list[index * 3+1 ] >= self.heap_list[index * 3]:
                return index * 3+1
            elif self.heap_list[index * 3 -1] >= self.heap_list[index * 3 ] and self.heap_list[index * 3 -1] >= self.heap_list[index * 3 ]:
                return index * 3-1

        # To Be Implemented


    def build_heap(self, alist):
        '''
        build a heap from a list of keys to establish complete tree property
        starting with the first non leaf node
        percolate each node down to establish heap order property
        '''
        index = len(alist) // 2 # any nodes past the half way point are leaves
        self.size = len(alist)
        self.heap_list = [0] + alist[:]
        while (index > 0):
            self.percolate_down(index)
            index -= 1


        # To Be Implemented


    def percolate_up(self, index):
        '''
        done
        compare the item at index with its parent
        if the item is less than its parent, swap!
        continue comparing until we hit the top of tree
        (can stop once an item is swapped into a position where it is greater than its parent)
        '''
        while (index+1) // 3 > 0:
            if self.heap_list[index] > self.heap_list[(index+1) // 3]:
                self.heap_list[index], self.heap_list[(index+1) // 3 ] =  self.heap_list[(index+1) // 3 ],self.heap_list[index]

            index = (index) // 3

        # To Be Implemented


    def percolate_down(self, index):
        '''
        done
        compare the item at index with its smallest child
        if the item is greater than its smallest child, swap!
        continue continue while there are children to compare with
        (can stop once an item is swapped into a position where it is less than both children)
        '''
        while (index * 3)-1 <= self.size :
            mc = self.max_child(index)
            if self.heap_list[index] < self.heap_list[mc]:
                self.heap_list[index],self.heap_list[mc] = self.heap_list[mc], self.heap_list[index]

            index = mc





def main():
    x=random.randint(1000, size=(100))
    h = TernaryHeap()
    g = BinaryHeap()
    print(h.is_empty())
    print(h.find_max())
    print(g.is_empty())
    print(g.find_max())
    h.build_heap(x.tolist())

    g.build_heap(x.tolist())
    h.insert(5)
    g.insert(5)
    h.insert(15)
    g.insert(15)
    h.insert(115)
    g.insert(115)
    h.insert(500)
    g.insert(500)
    list1 = list()
    list2 = list()
    print(h.is_empty())
    print(h.find_max())
    print(g.is_empty())
    print(g.find_max())
    while h.size > 0 and g.size > 0:

        x =h.del_max()
        y =g.del_max()
        list1.append(x)
        list2.append(y)
        if x == y:
            print("Correct")
        else:
            print("error") # this should never occur if both heaps are implemented correctly
    i = 0
    #check values in order
    while i+1 < len(list1):
        if list1[i] < list1[i+1]:
            print("oops")
        i+=1

if __name__ == '__main__':
        main()