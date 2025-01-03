export default function divisibleTriangleNumber(n) {
    // Helper function to count factors of a number
    function countFactors(num) {
        let count = 0;
        const sqrt = Math.floor(Math.sqrt(num));
        for (let i = 1; i <= sqrt; i++) {
            if (num % i === 0) {
                count += 2; // i and num/i
                if (i === num / i) count--; // If both factors are the same, count only once
            }
        }
        return count;
    }

    let i = 1;
    let triangleNum = 0;

    while (true) {
        triangleNum += i; // Calculate triangle number directly
        i++;

        // Count factors of the triangle number
        const factors = countFactors(triangleNum);

        if (factors > n) return triangleNum;
    }
}


// divisibleTriangleNumber(500);


