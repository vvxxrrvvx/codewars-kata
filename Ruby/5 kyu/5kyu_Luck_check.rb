def luck_check(str)
  raise ArgumentError, "String must not be empty" if str.empty?
  raise ArgumentError, "String must be a decimal number" unless str.match?(/^\d+$/)
  digits = str.chars.map(&:to_i)
  half_size = digits.size / 2
  left_half = digits[0...half_size]
  right_half = digits[-half_size..-1]
  left_sum = left_half.reduce(&:+)
  right_sum = right_half.reduce(&:+)
  left_sum == right_sum
end