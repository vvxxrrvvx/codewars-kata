class Node {
    var data: Int
    var next: Node?
    init(_ data: Int) {
        self.data = data
    }
}

func length(_ head: Node?) -> Int {
    var count = 0
    var current = head
    while current != nil {
        count += 1
        current = current?.next
    }
    return count
}

func count(_ head: Node?, _ data: Int) -> Int {
    var count = 0
    var current = head
    while current != nil {
        if current!.data == data {
            count += 1
        }
        current = current?.next
    }
    return count
}

func printLinkedList(_ head: Node?) {
    var current = head
    while current != nil {
        print(current!.data, terminator: " -> ")
        current = current?.next
    }
    print("null")
}