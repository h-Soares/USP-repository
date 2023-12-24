class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.tail = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def insert(self, data):
        node = Node(data)
        node.next = self.tail
        self.tail = node
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        self.tail = self.tail.next
        self.size -= 1

    def contains(self, data):
        if self.is_empty():
            raise Exception("Stack is empty")
        aux = self.tail
        while aux is not None:
            if data == aux.data:
                return True
            aux = aux.next
        return False

    def length(self):
        return self.size

    def show(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        aux = self.tail
        while aux is not None:
            print(aux.data)
            aux = aux.next
