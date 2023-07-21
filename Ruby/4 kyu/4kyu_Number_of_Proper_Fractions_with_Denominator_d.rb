def proper_fractions(n)
  return 0 if n == 1
  
  phi = n
  p = 2

  while p * p <= n
    if n % p == 0
      while n % p == 0
        n /= p
      end
      phi -= phi / p
    end
    p += 1
  end

  if n > 1
    phi -= phi / n
  end

  phi
end