class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue2:  # Queue.py causes error in python debugger
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def insert(self, data):
        node = Node(data)
        if self.is_empty():
            self.head = node
        else:
            self.tail.next = node
        self.tail = node
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        self.head = self.head.next
        if self.head is None:
            self.tail = None
        self.size -= 1

    def get(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        return self.head.data

    def contains(self, data):
        if self.is_empty():
            raise Exception("Queue is empty")
        aux = self.head
        while aux is not None:
            if data == aux.data:
                return True
            aux = aux.next
        return False

    def length(self):
        return self.size

    def show(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        aux = self.head
        while aux is not None:
            print(aux.data, end=" ")
            aux = aux.next
