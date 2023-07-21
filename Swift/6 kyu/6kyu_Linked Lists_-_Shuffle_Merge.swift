class Node {
    var data: Int
    var next: Node?
    
    init(_ data: Int) {
        self.data = data
    }
}

func shuffleMerge(first: Node?, second: Node?) -> Node? {
    if first == nil {
        return second
    } else if second == nil {
        return first
    }
    let mergedHead = Node(0) 
    var current = mergedHead
    var firstCurrent = first
    var secondCurrent = second

    while firstCurrent != nil && secondCurrent != nil {
        current.next = firstCurrent
        firstCurrent = firstCurrent?.next
        current = current.next!
        
        current.next = secondCurrent
        secondCurrent = secondCurrent?.next
        current = current.next!
    }
    
    if firstCurrent != nil {
        current.next = firstCurrent
    }

    if secondCurrent != nil {
        current.next = secondCurrent
    }
    return mergedHead.next
}

func printLinkedList(_ head: Node?) {
    var current = head
    while current != nil {
        print(current!.data, terminator: " -> ")
        current = current?.next
    }
    print("null")
}