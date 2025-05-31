const { performance } = require("perf_hooks");

function linearSearch(arr, target) {
    const startTime = performance.now();
    
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) {
            const endTime = performance.now();
            console.log(`Element ${target} found at index ${i}.`);
            console.log(`Search time: ${(endTime - startTime).toFixed(2)} ms`);
            return i;
        }
    }

    const endTime = performance.now();
    console.log(`Element ${target} not found.`);
    console.log(`Search time: ${(endTime - startTime).toFixed(2)} ms`);
    return -1;
}

// Allocating a billion-element array (⚠️ Requires substantial RAM!)
const billionSize = 1_000_000_000;
console.log(`Allocating array with ${billionSize} elements...`);

const startAlloc = performance.now();
const arr = Array.from({ length: billionSize }, (_, i) => i);  // Efficiently filling array
const endAlloc = performance.now();

console.log(`Array allocated in ${(endAlloc - startAlloc).toFixed(2)} ms`);

// Testing search performance
const target = billionSize - 1; // Searching for the last element
linearSearch(arr, target);
