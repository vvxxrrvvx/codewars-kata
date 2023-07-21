class Node {
    var data: Int
    var next: Node?
    init(_ data: Int) {
        self.data = data
    }
}

func sortedInsert(_ head: Node?, _ data: Int) -> Node? {
    let newNode = Node(data)
    if head == nil || data < head!.data {
        newNode.next = head
        return newNode
    }

    var current = head
    var prev: Node? = nil
    while current != nil && current!.data <= data {
        prev = current
        current = current?.next
    }
  
    prev?.next = newNode
    newNode.next = current
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