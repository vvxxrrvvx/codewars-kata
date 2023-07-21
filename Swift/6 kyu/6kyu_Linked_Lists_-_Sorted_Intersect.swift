class Node {
    var data: Int
    var next: Node?
    
    init(_ data: Int) {
        self.data = data
    }
}

func SortedIntersect(first: Node?, second: Node?) -> Node? {
    var resultHead: Node? = nil
    var resultTail: Node? = nil
    var currentFirst = first
    var currentSecond = second

    while currentFirst != nil && currentSecond != nil {
        if currentFirst!.data == currentSecond!.data {
            if resultHead == nil || resultTail?.data != currentFirst!.data {
                let newNode = Node(currentFirst!.data)
                if resultHead == nil {
                    resultHead = newNode
                } else {
                    resultTail?.next = newNode
                }
                resultTail = newNode
            }
            currentFirst = currentFirst?.next
            currentSecond = currentSecond?.next
        } else if currentFirst!.data < currentSecond!.data {
            currentFirst = currentFirst?.next
        } else {
            currentSecond = currentSecond?.next
        }
    }
    return resultHead
}

func printLinkedList(_ head: Node?) {
    var current = head
    while current != nil {
        print(current!.data, terminator: " -> ")
        current = current?.next
    }
    print("null")
}