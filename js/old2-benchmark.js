
export default async function benchmark(fn) {
    if (fn==undefined || fn ==null) {
        console.error("No function given to benchmark")
    }
    const start = performance.now()
    await fn()
    const end = performance.now()
    console.log(`${fn.name} took: ${end - start} ms`)
}


// benchmark(async function with_delay() {
//   await delay(1000)
// })

// function delay(milliseconds){
//     return new Promise(resolve => {
//         setTimeout(resolve, milliseconds);
//     });
// }