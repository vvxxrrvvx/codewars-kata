def to_postfix(infix)
  precedence = {"^" => 4, "*" => 3, "/" => 3, "+" => 2, "-" => 2}
  stack = []
  output = []
  
  infix.each_char do |char|
    case char
    when /\d/
      output << char
    when /\+|\-|\*|\// # operator
      while stack.any? && stack.last != "(" && precedence[char] <= precedence[stack.last]
        output << stack.pop
      end
      stack << char
    when /\^/ # exponentiation
      while stack.any? && stack.last != "(" && precedence[char] < precedence[stack.last]
        output << stack.pop
      end
      stack << char
    when /\(/
      stack << char
    when /\)/
      while stack.any? && stack.last != "("
        output << stack.pop
      end
      stack.pop
    end
  end
  
  while stack.any?
    output << stack.pop
  end
  
  output.join
end