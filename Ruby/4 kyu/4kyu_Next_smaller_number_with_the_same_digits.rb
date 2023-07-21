def next_smaller(n)
  digits = n.to_s.chars.map(&:to_i)
  
  # Find the rightmost digit that is larger than the digit to its right
  i = digits.size - 2
  i -= 1 while i >= 0 && digits[i] <= digits[i + 1]
  
  if i < 0
    # All digits are in non-increasing order, no smaller number possible
    return -1
  end
  
  # Find the largest digit to the right of i that is smaller than digits[i]
  j = digits.size - 1
  j -= 1 while j > i && digits[j] >= digits[i]
  
  # Swap digits[i] and digits[j]
  digits[i], digits[j] = digits[j], digits[i]
  
  # Reverse the digits to the right of i
  digits[(i + 1)..-1] = digits[(i + 1)..-1].reverse
  
  # Check if the result has a leading zero
  result = digits.join.to_i
  if result.to_s.size < digits.size || result.zero?
    return -1
  else
    return result
  end
end