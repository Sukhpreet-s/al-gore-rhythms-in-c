if (process.argv.length <= 2) {
    console.error('Provide the file to benchmark as an argument!');
    process.exit(1);
}

try {
    const filename = process.argv[2]
    const pathPrefix = './'
    import(pathPrefix + filename).then(module => {
        const { fn, args } = module
        benchmark(fn, args)

        process.exit(1)
    })
} catch (error) {
    console.error("Ensure that given file exists in the current working directory!")
    // console.error(error)
    process.exit(1)
}

function benchmark(fn, variations) {
    for (let args of variations) {
        const start = performance.now()
        const output = fn(...args)
        const end = performance.now()
        console.log(`${fn.name} with\t input ${args[0]}\t output ${output}\t took: ${(end - start) | 0} ms`)
    }
}

