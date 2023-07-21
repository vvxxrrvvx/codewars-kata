def palindrome(num)
  return "Not valid" unless num.is_a?(Integer) && num >= 0

  digits = num.digits
  count = 0

  (2..digits.size).each do |length|
    digits.each_cons(length) do |sub_digits|
      count += 1 if sub_digits == sub_digits.reverse
    end
  end

  count
end