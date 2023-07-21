func splitlist(_ list: [Int]) -> ([Int], [Int]) {
    var bestDiff = Int.max
    var bestLists: ([Int], [Int]) = ([], [])
    
    func helper(_ a: [Int], _ b: [Int], _ i: Int) {
        if i == list.count {
            let diff = abs(a.reduce(0, +) - b.reduce(0, +))
            if diff < bestDiff {
                bestDiff = diff
                bestLists = (a, b)
            }
            return
        }
        
        helper(a + [list[i]], b, i + 1)
        helper(a, b + [list[i]], i + 1)
    }
    
    helper([], [], 0)
    
    return bestLists
}