if (process.argv.length <= 2) {
    console.error('Provide the file to benchmark as an argument!');
    process.exit(1);
}

import fs from 'fs/promises';

const algoName = process.argv[2]
const pathPrefix = './'
const filenamePattern = 'algo'

/*
* Access all filename
*/
console.log('Logging files: ')
const files = await fs.readdir(pathPrefix + algoName)
    .then(files => files.filter(filename => filename.startsWith(filenamePattern)))
    .catch(err => {
        console.log('!!!!!!!!!Error while reading filenames!!!!!!!!!')
        return null;
    })

if (!files) {
    console.log("No function files detected! Terminating!")
    process.exit(1)
}
console.log(files)

/*
* Access all functions
*/
console.log('Logging functions')
const functions = await Promise.all(
    files.map(async (file) => {
        try {
            const module = await import(`${pathPrefix}${algoName}/${file}`)
            return { name: file, fn: module.default }
        } catch (err) {
            console.error(`Error while loading module for file: ${file}`, err)
            return null
        }
    })
)

if (!functions) {
    console.log("No function files detected! Terminating!")
    process.exit(1)
}
console.log(functions)

/*
* Access input data
*/
const input = await import(pathPrefix + algoName + "/input.js")
    .then(module => module.default)
    .catch(err => {
        console.log("!!!!! Error while getting input data!!!!", err)
        return null
    })

if (!input || input.length == 0) {
    console.log("No input detected! Terminating!")
    process.exit(1)
}
console.log(input)

console.log(`Running the ${algoName} functions`)
runBenchmark(functions, input)

// benchmark(fn, args)
function runBenchmark(fns, variations) {
    for (let fn of fns) {
        console.log(`For ${fn.name}: `)
        for (let args of variations) {
            const start = performance.now()
            const output = fn.fn(...args)
            const end = performance.now()
            console.log(`\t with\t input ${args[0]}\t output ${output}\t took: ${(end - start) | 0} ms`)
        }
    }
}
