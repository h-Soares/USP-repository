class Node:
    def __init__(self, data):
        self._data = data
        self._left = None
        self._right = None

    @property
    def data(self):
        return self._data

    @property
    def left(self):
        return self._left

    @left.setter
    def left(self, left):
        self._left = left

    @property
    def right(self):
        return self._right

    @right.setter
    def right(self, right):
        self._right = right

    @data.setter
    def data(self, data):
        self._data = data


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def is_empty(self):
        return self.root is None

    def insert(self, data):
        if self.is_empty():
            self.root = Node(data)
        else:
            x = self.root
            parent = None
            while x:
                parent = x
                if data < x.data:
                    x = x.left
                else:
                    x = x.right
            x = Node(data)
            if x.data < parent.data:
                parent.left = x
            else:
                parent.right = x

    def search(self, data):
        if self.is_empty():
            raise Exception("Tree is empty")

        x = self.root
        while x:
            if x.data == data:
                return True
            if data < x.data:
                x = x.left
            else:
                x = x.right
        return False

    def __print_in_order(self, node):
        if node:
            self.__print_in_order(node.left)
            print(node.data, end=" ")
            self.__print_in_order(node.right)

    def print_in_order(self):
        if self.is_empty():
            raise Exception("Tree is empty")

        self.__print_in_order(self.root)
