class Node {
    var data: Int
    var next: Node?
    init(_ data: Int) {
        self.data = data
    }
}

enum LinkedListError: Error {
    case invalidListLength
}

func frontBackSplit(source: Node?, front: inout Node?, back: inout Node?) throws {
    if source == nil || source?.next == nil {
        throw LinkedListError.invalidListLength
    }

    var slow: Node? = source
    var fast: Node? = source

    while fast?.next != nil && fast?.next?.next != nil {
        slow = slow?.next
        fast = fast?.next?.next
    }

    front = source
    back = slow?.next
    slow?.next = nil
}

func printLinkedList(_ head: Node?) {
    var current = head
    while current != nil {
        print(current!.data, terminator: " -> ")
        current = current?.next
    }
    print("null")
}