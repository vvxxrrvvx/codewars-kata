def int_to_negabinary(i)
  return '0' if i.zero?

  result = ''
  while i != 0
    remainder = i % -2
    i /= -2
    i += 1 if remainder < 0
    result.prepend((-remainder).to_s)
  end
  result
end

def negabinary_to_int(s)
  return 0 if s == '0'

  result = 0
  s.chars.reverse_each.with_index do |digit, index|
    value = digit.to_i * (-2)**index
    result += value
  end
  result
end