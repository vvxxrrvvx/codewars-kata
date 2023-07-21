class Node {
    var data: Int
    var next: Node?
    init(_ data: Int) {
        self.data = data
    }
}

func removeDuplicates(head: Node?) -> Node? {
    var current = head

    while current != nil && current!.next != nil {
        if current!.data == current!.next!.data {
            current!.next = current!.next!.next
        } else {
            current = current!.next
        }
    }
    return head
}

func printLinkedList(_ head: Node?) {
    var current = head
    while current != nil {
        print(current!.data, terminator: " -> ")
        current = current?.next
    }
    print("null")
}