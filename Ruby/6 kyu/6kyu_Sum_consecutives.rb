def sum_consecutives(s)
  s.chunk_while(&:==).map(&:sum)
end