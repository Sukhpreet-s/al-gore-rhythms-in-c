export default function divisibleTriangleNumber(n) {
  // Helper function to count factors using prime factorization
  function countFactors(num) {
    let count = 1;
    let divisor = 2;

    while (num > 1) {
      let exponent = 0;
      while (num % divisor === 0) {
        num /= divisor;
        exponent++;
      }
      count *= (exponent + 1);
      divisor++;

      // Optimization: If divisor^2 exceeds num, num is prime
      if (divisor * divisor > num && num > 1) {
        count *= 2;
        break;
      }
    }
    return count;
  }

  let i = 1;
  let triangleNum = 0;

  while (true) {
    triangleNum = (i * (i + 1)) / 2; // Calculate triangle number
    const factors =
      countFactors(i) * countFactors((i + 1) / 2); // Separate even and odd parts

    if (factors > n) return triangleNum;
    i++;
  }
}

// console.log(divisibleTriangleNumber(500)); // Example test for n=500

