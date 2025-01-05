export default function divisibleTriangleNumber(n) {
    let prevDivisors = 1

    for (let i = 2; ; i++) {
        let num = i

        // When n is even, find divisors for n/2. For odd, it will just be n so that: d(n) = even (n/2)*(n+1) | odd (n)*((n+1)/2)
        if (num % 2 == 0) num /= 2

        // First find divisor count for 2 (prime number), so then we can increment the count by 2 for each number to find all the primes.
        let numCopy = num // copy
        let divisors = 1
        while (numCopy % 2 == 0) {
            divisors += 1
            numCopy /= 2
        }

        // Count divisors for 3<=p<=sqrt(numCopy)
        for (let p = 3; p <= num; p += 2) {
            let count = 1
            while (numCopy % p == 0) {
                count += 1
                numCopy /= p
            }
            divisors *= count

            if (numCopy == 1) break
        }

        if ((prevDivisors * divisors) > n) {
            return ((i - 1) * i) / 2
        }

        prevDivisors = divisors
    }
}

// console.log(divisibleTriangleNumber(500))