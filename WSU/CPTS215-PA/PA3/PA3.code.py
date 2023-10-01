"""
Cade Chaplin
PA3
3/12/2023
This program implements a  avl tree.

"""



from graphviz import Graph
from graphviz import Digraph
import collections
import random
class BSTNode:
    def __init__(self, data, left=None, right=None, parent=None):
        self.data = data
        self.left_child = left
        self.right_child = right
        self.parent = parent
        self.balance_factor = 0



class BinarySearchTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def post_order_traversal(self):
        if self.root is None:
            print("Empty Tree")
        else:
            self.post_order_traversal_helper(self.root)
            print()

    def post_order_traversal_helper(self,node):
        if node is None:
            return

        self.post_order_traversal_helper(node.left_child)
        self.post_order_traversal_helper(node.right_child)
        print(node.data, node.balance_factor)

    def in_order_traversal(self):
            if self.root is None:
                print("Empty Tree")
            else:
                self.in_order_traversal_helper(self.root)
                print()

    def in_order_traversal_helper(self,node):
        if node is None:
            return

        self.in_order_traversal_helper(node.left_child)
        print(node.data, node.balance_factor)
        self.in_order_traversal_helper(node.right_child)


    def pre_order_traversal(self):
        if self.root is None:
            print("Empty Tree")
        else:
            self.pre_order_traversal_helper(self.root)
            print()

    def pre_order_traversal_helper(self,node):
        if node is None:
            return

        print(node.data, node.balance_factor)
        self.pre_order_traversal_helper(node.left_child)
        self.pre_order_traversal_helper(node.right_child)


    def level_order_traversal(self):
        return self.level_order_traversal_helper()

    def level_order_traversal_helper(self):
        ans = []

    # Return Null if the tree is empty
        if self.root is None:
            return ans

    # Initialize queue
        queue = collections.deque()
        queue.append(self.root)


    # Iterate over the queue until it's empty
        while queue:
        # Check the length of queue
            currSize = len(queue)
            currList = []

            while currSize > 0:
            # Dequeue element
                currNode = queue.popleft()
                currList.append(currNode.data)
                currList.append(currNode.balance_factor)
                currSize -= 1

            # Check for left child
                if currNode.left_child is not None:
                    queue.append(currNode.left_child)
            # Check for right child
                if currNode.right_child is not None:
                    queue.append(currNode.right_child)

        # Append the currList to answer after each iteration
            ans.append(currList)

    # Return answer list
        print(ans)
        return ans





    def get(self, item):
        return self._get(self.root,item)


    def _get(self,node,item):

        if node == None:
            return None

        if (node.data) == (item):
            return node
        elif (node.data) > (item):
            if node.left_child != None:
                return self._get(node.left_child, item)
            else:
                return None
        elif (node.data) < (item):
            if node.right_child != None:
                return self._get(node.right_child, item)
            else:
                return None



class AVLTree(BinarySearchTree):
    def __init__(self):
        super().__init__()
        self.graph = None


    def put(self, data):
        if self.root is None:
            self.root = BSTNode(data)
            self.size += 1
        else:
            self._put(data, self.root)

    def _put(self, data, curr_node):
        if data == curr_node.data:
            return
        if data < curr_node.data:
            if curr_node.left_child is None:
                curr_node.left_child = BSTNode(data, parent=curr_node)
                self.size += 1
                curr_node.balance_factor += 1
                self.update_balance_insert(curr_node)
            else:
                self._put(data, curr_node.left_child)
        else:
            if curr_node.right_child is None:
                curr_node.right_child = BSTNode(data, parent=curr_node)
                self.size += 1
                curr_node.balance_factor -= 1
                self.update_balance_insert(curr_node)
            else:
                self._put(data, curr_node.right_child)

    def update_balance_insert(self, node):
        if node.balance_factor == 0:
            return
        elif node.balance_factor == +1:
            if node.parent and node.parent.left_child is node:
                node.parent.balance_factor += 1
                self.update_balance_insert(node.parent)
            elif node.parent and node.parent.right_child is node:
                node.parent.balance_factor -= 1
                self.update_balance_insert(node.parent)
        elif node.balance_factor == -1:
            if node.parent and node.parent.left_child is node:
                node.parent.balance_factor += 1
                self.update_balance_insert(node.parent)
            elif node.parent and node.parent.right_child is node:
                node.parent.balance_factor -= 1
                self.update_balance_insert(node.parent)
        elif node.balance_factor == -2:
            if node.right_child.balance_factor == -1:
                self.rotate_left(node)
            elif node.right_child.balance_factor == 0:
                self.rotate_left(node)
            elif node.right_child.balance_factor == +1:
                self.rotate_right(node.right_child)
                self.rotate_left(node)
            else:
                raise RuntimeError("Unexpected Balance Factor value")
        elif node.balance_factor == +2:
            if node.left_child.balance_factor == +1:
                self.rotate_right(node)
            elif node.left_child.balance_factor == 0:
                self.rotate_right(node)
            elif node.left_child.balance_factor == -1:
                self.rotate_left(node.left_child)
                self.rotate_right(node)
            else:
                raise RuntimeError("Unexpected Balance Factor value")
        else:
            raise RuntimeError("Unexpected Balance Factor value")


    def _update_balance_delete(self, node):
        if node.balance_factor > 1:
            if node.left.balance_factor >= 0:
                node = self.rotate_right(node)
            else:
                node.left = self.rotate_left(node.left)
                node = self.rotate_right(node)
        elif node.balance_factor < -1:
            if node.right.balance_factor <= 0:
                node = self.rotate_left(node)
            else:
                node.right = self._rotate_right(node.right)
                node = self.rotate_left(node)

        if node.parent:
            node.parent.balance_factor = self.get_balance_factor(node.parent)
            if node.parent.balance_factor > 1 or node.parent.balance_factor < -1:
                self.rebalance(node.parent)




    def update_balance_delete(self, node):
        if node.balance_factor == -1 or +1:
            return
        elif node.balance_factor == 0:
            if node.parent and node.parent.left_child is node:
                node.parent.balance_factor += 1
                self.update_balance_delete(node.parent)
            elif node.parent and node.parent.right_child is node:
                node.parent.balance_factor -= 1
                self.update_balance_delete(node.parent)
        elif node.balance_factor == -2:
            if node.right_child.balance_factor == -1:
                self.rotate_left(node)
            elif node.right_child.balance_factor == 0:
                self.rotate_left(node)
            elif node.right_child.balance_factor == +1:
                self.rotate_right(node.right_child)
                self.rotate_left(node)
            else:
                raise RuntimeError("Unexpected Balance Factor value")
        elif node.balance_factor == +2:
            if node.left_child.balance_factor == +1:
                self.rotate_right(node)
            elif node.left_child.balance_factor == 0:
                self.rotate_right(node)
            elif node.left_child.balance_factor == -1:
                self.rotate_left(node.left_child)
                self.rotate_right(node)
            else:
                raise RuntimeError("Unexpected Balance Factor value")
        else:
            raise RuntimeError("Unexpected Balance Factor value")

    def rotate_left(self, rot_root):
        new_root = rot_root.right_child
        rot_root.right_child = new_root.left_child
        if new_root.left_child != None:
            new_root.left_child.parent = rot_root
        new_root.parent = rot_root.parent
        if rot_root.parent is None:
            self.root = new_root
        else:
            if rot_root.parent.left_child is rot_root:
                rot_root.parent.left_child = new_root
            else:
                rot_root.parent.right_child = new_root
        new_root.left_child = rot_root
        rot_root.parent = new_root
        rot_root.balance_factor = rot_root.balance_factor + 1 - min(new_root.balance_factor, 0)
        new_root.balance_factor = new_root.balance_factor + 1 + max(rot_root.balance_factor, 0)

    def rotate_right(self, rot_root):
        new_root = rot_root.left_child
        rot_root.left_child = new_root.right_child
        if new_root.right_child != None:
            new_root.right_child.parent = rot_root
        new_root.parent = rot_root.parent
        if rot_root.parent is None:
            self.root = new_root
        else:
            if rot_root.parent.right_child is rot_root:
                rot_root.parent.right_child = new_root
            else:
                rot_root.parent.left_child = new_root
        new_root.right_child = rot_root
        rot_root.parent = new_root
        rot_root.balance_factor = rot_root.balance_factor - 1 - max(new_root.balance_factor, 0)
        new_root.balance_factor = new_root.balance_factor - 1 + min(rot_root.balance_factor, 0)
    def test(self):
        self.test_helper(self.root)
    def test_helper(self, node):
        if(node.left_child != None):

            print(node == node.left_child.parent)
        if(node.right_child != None):
            print(node == node.right_child.parent)
        if(node.left_child != None):
            self.test_helper(node.left_child)
        if(node.right_child != None):

            self.test_helper(node.right_child)
        return

    def delete(self, data):
        if self.size == 1 and self.root.data == data:
            self.root = None
            self.size = 0
        elif self.size > 1:
            node_to_remove = self._get(self.root, data)
            if node_to_remove is not None:
                self.remove(node_to_remove, data)
                self.size -= 1
            else:
                raise KeyError("Error, data not present in the tree")
        else:
            raise KeyError("Error, data not present in the tree")

    def remove(self, root, key):

        # Find the node to be deleted and remove it


        if key < root.data:
            self.remove(root.left_child, key)
        elif key > root.data:
            self.remove(root.right_child, key)
        else:
            if root.right_child is None and root.left_child is None:
                if root.parent != None:
                    if root.parent.left_child == root:
                        root.parent.left_child = None

                    elif root.parent.right_child == root:
                        root.parent.right_child = None
                    self.update_balance_delete(root.parent)
                else:
                    root = None


            elif root.left_child is None:
                temp = root.right_child
                if root.parent != None:
                    parent = root.parent
                    if parent.left_child == root:
                        parent.left_child = temp
                        temp.parent = parent
                    elif parent.right_child == root:
                        parent.right_child = temp
                        temp.parent = parent
                    self.update_balance_delete(root.parent)

                else:
                    temp.parent = None
                    self.root = temp

                return temp
            elif root.right_child is None:
                temp = root.left_child
                if root.parent != None:
                    parent = root.parent
                    if parent.left_child == root:
                        parent.left_child = temp
                        temp.parent = parent
                    elif parent.right_child == root:
                        parent.right_child = temp
                        temp.parent = parent
                    self.update_balance_delete(root.parent)
                else:
                    temp.parent = None
                    self.root = temp




                return temp
            else:

                temp = self.getMinValueNode(root.right_child)
                if root.parent != None:
                    self.update_balance_delete(root.parent)
                root.data = temp.data
                self.remove(root.right_child,root.data)

        if root is None:
            return root

        # Update the balance factor of nodes


        balanceFactor = self.getBalance(root)

        # Balance the tree
        if balanceFactor > 1:
            if self.getBalance(root.left) >= 0:
                return self.rotate_right(root)
            else:
                root.left = self.rotate_left(root.left)
                return self.rotate_right(root)
        if balanceFactor < -1:
            if self.getBalance(root.right_child) <= 0:
                return self.rotate_left(root)
            else:
                root.right = self.rotate_right(root.right)
                return self.rotate_left(root)
        return root

    def getMinValueNode(self, root):
        if root is None or root.left_child is None:
            return root
        return self.getMinValueNode(root.left_child)

    def visualize(self):
        self.graph = Graph()

        self.visualize_helper(self.root)


        #self.graph.node("example")
        #self.graph.render(view = True)
        #self.graph.render(format = "pdf")
        #self.graph.render(filename = file)
        self.graph.write_png("output.png")
    def getBalance(self, root):

        return root.balance_factor
    def visualize_helper(self,node):
        if node != None:

            if node.left_child != None:
                self.graph.node(str(node.left_child.data))

                self.visualize_helper(node.left_child)
                self.graph.edge(str(node.data),str(node.left_child.data))


            if node.right_child != None:
                self.graph.node(str(node.right_child.data))

                self.visualize_helper(node.right_child)
                self.graph.edge(str(node.data),str(node.right_child.data))



def main():
    mytree = AVLTree()

    mytree.put(131)
    mytree.put(121)
    mytree.put(122)
    mytree.put(132)
    mytree.put(115)
    mytree.put(415)
    mytree.put(321)
    mytree.put(315)
    mytree.put(111)

    print("pre-order traversal:")
    mytree.pre_order_traversal()

    print("post-order traversal:")
    mytree.post_order_traversal()

    print("in-order traversal:")
    mytree.in_order_traversal()

    print("level-order traversal:")
    mytree.level_order_traversal()

    print("get method result: ", end=" ")
    print((mytree.get(122)).data)
    print()

    print("deleting 122")
    mytree.delete(122)



    print("level-order traversal after deleting 122:")
    mytree.level_order_traversal()

    print("deleting 131")
    mytree.delete(131)


    mytree.visualize()

    print("level-order traversal after deleting 131:")
    mytree.level_order_traversal()

if __name__ == '__main__':
          main()

