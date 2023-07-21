def solution(n)
  sum = 0
  (1..n).each do |num|
    digits = num.to_s.chars.map(&:to_i)
    sum += digits.sum
  end
  sum
end