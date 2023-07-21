def prime(n)
  # create an array of boolean values representing whether each number from 0 to n is prime
  is_prime = Array.new(n + 1, true)

  # 0 and 1 are not prime by definition
  is_prime[0] = is_prime[1] = false

  # mark all multiples of each prime number as not prime
  (2..Math.sqrt(n)).each do |i|
    if is_prime[i]
      (i**2..n).step(i).each do |j|
        is_prime[j] = false
      end
    end
  end

  # collect all prime numbers in a separate array
  primes = []
  is_prime.each_with_index do |is_prime, i|
    primes << i if is_prime
  end

  return primes
end