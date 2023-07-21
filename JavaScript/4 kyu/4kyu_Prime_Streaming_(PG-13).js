class Primes {
static * stream() {
yield 2;
let primes = [2];
let current = 3;
while (true) {
let isPrime = true;
for (let prime of primes) {
if (prime * prime > current) break;
if (current % prime === 0) {
isPrime = false;
break;
}
}
if (isPrime) {
primes.push(current);
yield current;
}
current += 2;
}
}
}