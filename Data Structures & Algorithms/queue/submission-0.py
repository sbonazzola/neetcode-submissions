class ListNode:
    def __init__(self,val):
        self.val = val
        self.next = None
        self.prev = None

class Deque:
    
    def __init__(self):
        self.head = ListNode(-1)
        self.tail = ListNode(-1)

        self.head.next = self.tail
        self.tail.prev = self.head

    def isEmpty(self) -> bool:
        if self.head.next == self.tail:
            return True
        return False

    def append(self, value: int) -> None:
        
        new_node = ListNode(value)

        back = self.tail.prev
        back.next = new_node
        self.tail.prev = new_node
        new_node.next = self.tail
        new_node.prev = back

    def appendleft(self, value: int) -> None:
        new_node = ListNode(value)

        front = self.head.next
        front.prev = new_node
        self.head.next = new_node
        new_node.next = front
        new_node.prev = self.head

    def pop(self) -> int:
        if self.head.next == self.tail:
            return -1
        x = self.tail.prev.val
        remove = self.tail.prev
        self.tail.prev = remove.prev
        remove.prev.next = self.tail
        return x
       

    def popleft(self) -> int:

        if self.head.next == self.tail:
            return -1
        x = self.head.next.val 
        remove = self.head.next
        self.head.next = remove.next
        remove.next.prev = self.head
        return x
