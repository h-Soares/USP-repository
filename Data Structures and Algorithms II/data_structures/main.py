from data_structures.LinkedList import LinkedList
from data_structures.Queue2 import Queue2
from data_structures.Stack import Stack
from data_structures.PriorityQueue import PriorityQueue

mylist = [1, 2, 3, 4, 5]

print("LINKED LIST:")
linked_list = LinkedList()
for numb in mylist:
    linked_list.insert(numb)
linked_list.show()
print(f"\ncontains 6: {linked_list.contains(6)}")
print(f"length: {linked_list.length()}")
print("Removing 3:")
linked_list.remove(3)
linked_list.show()
print(f"\ncontains 3: {linked_list.contains(3)}")
print(f"length: {linked_list.length()}")

print("\nQUEUE:")
queue = Queue2()
for numb in mylist:
    queue.insert(numb)
queue.show()
print(f"\ncontains 5: {queue.contains(5)}")
print(f"length: {queue.length()}")
print("After pop:")
queue.pop()
queue.show()
print(f"\ncontains 1: {queue.contains(1)}")
print(f"length: {queue.length()}")

print("\nSTACK:")
stack = Stack()
for numb in mylist:
    stack.insert(numb)
stack.show()
print(f"contains 3: {stack.contains(3)}")
print(f"length: {stack.length()}")
print("After pop: ")
stack.pop()
stack.show()
print(f"contains 5: {stack.contains(5)}")
print(f"length: {stack.length()}")
print()

mypq = PriorityQueue()
mynumbs = [(5, "A"), (3, "B"), (1, "C"), (4, "D"), (2, "E"), (5, "K"), (1, "Z"), (1, "Z")]
for numb, letter in mynumbs:
    mypq.insert(numb, letter)
mypq.show()
print(f"\nhead: {mypq.head.priority}, {mypq.head.data}")
print(f"tail: {mypq.tail.priority}, {mypq.tail.data}")
mypq.pop()
print()
mypq.show()
print(f"\nhead: {mypq.head.priority}, {mypq.head.data}")
print(f"tail: {mypq.tail.priority}, {mypq.tail.data}")
mypq.insert(1, "ZZZ")
print()
mypq.show()
print(f"\nhead: {mypq.head.priority}, {mypq.head.data}")
print(f"tail: {mypq.tail.priority}, {mypq.tail.data}")
mypq.pop()
mypq.pop()
mypq.pop()
print()
mypq.show()
print(f"\nhead: {mypq.head.priority}, {mypq.head.data}")
print(f"tail: {mypq.tail.priority}, {mypq.tail.data}")
mypq.insert(6, "AKKZ")
print()
mypq.show()
print(f"\nhead: {mypq.head.priority}, {mypq.head.data}")
print(f"tail: {mypq.tail.priority}, {mypq.tail.data}")
