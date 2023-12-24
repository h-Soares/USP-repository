class Node:
    def __init__(self, priority, data):
        self.priority = priority
        self.data = data
        self.next = None


class PriorityQueue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def insert(self, priority, data):
        new_node = Node(priority, data)

        if self.is_empty() or priority < self.head.priority:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            while current.next and priority >= current.next.priority:
                current = current.next
            new_node.next = current.next
            current.next = new_node
            if new_node.next is None:
                self.tail = new_node
        self.size += 1
        if self.size == 1:
            self.tail = new_node

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

    def show(self):
        if self.is_empty():
            raise Exception("Linked list is empty")
        aux = self.head
        while aux is not None:
            print(f"Priority: {aux.priority}, data: {aux.data};", end=" ")
            aux = aux.next
