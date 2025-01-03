export default function divisibleTriangleNumber(n) {
    // What is the first number that will have n factors
    const MAX_POSITION = 76576500

    // sum of series till sum_series(i) = i(i+1) / 2
    // if n = 10
    // num of n factors of x <= x
    // 10 = sum_series(i)
    let triangleNum = null
    let prev = 0
    let factorArr = null




    for (let i = 1; i <= MAX_POSITION; i++) {
        triangleNum = prev + i
        prev = triangleNum
        if (triangleNum < n * (n + 1) / 2) continue

        // Now check if number of factors of i are > n
        // Find number of factors of i
        const sqrtTNum = Math.floor(Math.sqrt(triangleNum))
        // const factors = Array(triangleNum).fill().map((_,i) => i+1)
        //  .filter(i => ((triangleNum%i)==0))
        factorArr = []
        for (let j = 1; j <= sqrtTNum; j++) {
            if (triangleNum % j == 0) {
                factorArr.push(j)
                factorArr.push(triangleNum / j)
            }
        }

        // console.log(`i: ${i}, Triangle number: ${triangleNum}, factors: ${factors}`)
        const numberOfFactors = factorArr.length

        if (numberOfFactors > n) break
    }

    return triangleNum;
}
