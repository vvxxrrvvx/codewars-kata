func numericals(_ str: String) -> String {
    var countDictionary: [Character: Int] = [:]
    var result = ""

    for char in str {
        if let count = countDictionary[char] {
            countDictionary[char] = count + 1
            result.append(String(count + 1))
        } else {
            countDictionary[char] = 1
            result.append("1")
        }
    }

    return result
}