class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
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

    def remove(self, data):
        if self.is_empty():
            raise Exception("Linked list is empty")
        if data == self.head.data:
            self.head = self.head.next
            if self.head is None:
                self.tail = None
            self.size -= 1
            return

        to_remove = self.head.next
        to_remove_parent = self.head
        while to_remove is not None:
            if data == to_remove.data:
                to_remove_parent.next = to_remove.next
                if to_remove_parent.next is None:
                    self.tail = to_remove_parent
                self.size -= 1
                return
            to_remove_parent = to_remove
            to_remove = to_remove.next
        raise Exception(f"{data} is not in linked list")

    def contains(self, data):
        if self.is_empty():
            raise Exception("Linked list is empty")
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
            raise Exception("Linked list is empty")
        aux = self.head
        while aux is not None:
            print(aux.data, end=" ")
            aux = aux.next
