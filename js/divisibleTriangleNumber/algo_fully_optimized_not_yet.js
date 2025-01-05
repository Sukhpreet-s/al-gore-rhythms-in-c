export default function divisibleTriangleNumber(n) {
    // What is the first number that will have n factors
    const MAX_POSITION = 76576500

    // sum of series till sum_series(i) = i(i+1) / 2
    // if n = 10
    // num of n factors of x <= x
    // 10 = sum_series(i)
    let triangleNum = null
    let prev = 0

    for (let i = 1; i <= MAX_POSITION; i++) {
        triangleNum = prev + i
        prev = triangleNum
        if (triangleNum < n) continue

        // Now check if number of factors of i are > n
        // Find number of factors of i

        const primeFactorsPows = []
        let remainder = triangleNum
        // Below while loop is O(log(n))
        while (remainder % 2 == 0) {
            if (primeFactorsPows[0]) primeFactorsPows[0] += 1
            else primeFactorsPows[0] = 1
            remainder /= 2
        }
        // console.log(`factor powers after div by 2: ${primeFactorsPows} \n remainder: ${remainder} \t triangleNumber: ${triangleNum}`)
        let currentPrime = 3
        let currPrimePow = 0
        
        while (remainder > 2) {
            if (remainder % currentPrime == 0) {
                currPrimePow += 1
                remainder = remainder / currentPrime
                if (remainder == 1) {
                    primeFactorsPows.push(currPrimePow)
                }
            } else {
                // The remainder number is not divisible by currentPrime anymore
                currentPrime += 2

                if (currPrimePow > 0) {
                    primeFactorsPows.push(currPrimePow)
                    currPrimePow = 0
                }
            }
        }

        const numberOfFactors = primeFactorsPows.reduce(
            (accumulator, currentValue) => accumulator * (currentValue + 1),
            1
        )
        // console.log(`Prime factors powers array: ${primeFactorsPows} \n Computed number of factors: ${numberOfFactors}\n`)

        if (numberOfFactors > n) break
    }

    return triangleNum;
}

// console.log(divisibleTriangleNumber(500))