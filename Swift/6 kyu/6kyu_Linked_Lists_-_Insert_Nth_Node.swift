enum LinkedListError: Error {
    case invalidIndex
}

func insertNth(_ head: Node?, _ index: Int, _ data: Int) throws -> Node? {
    if index == 0 {
        let newNode = Node(data)
        newNode.next = head
        return newNode
    }

    var current = head
    var prev: Node? = nil
    var currentIndex = 0

    while current != nil && currentIndex < index {
        prev = current
        current = current?.next
        currentIndex += 1
    }

    if currentIndex == index {
        let newNode = Node(data)
        prev?.next = newNode
        newNode.next = current
        return head
    } else {
        throw LinkedListError.invalidIndex
    }
}

func FrontBackSplit(source: Node?, front: inout Node?, back: inout Node?) throws {
    guard source != nil, source?.next != nil else {
        front = source
        back = nil
        return
    }

    var slow = source
    var fast = source?.next
    while fast != nil {
        fast = fast?.next
        if fast != nil {
            slow = slow?.next
            fast = fast?.next
        }
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