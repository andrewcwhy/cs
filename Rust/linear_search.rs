use std::time::Instant;

fn main() {
    let n: usize = 1000000000; // 100 million. 1_000_000_000 needs 4GB+ RAM.
    println!("Allocating vector with {} elements...", n);

    // Preallocate and fill in parallel, if desired.
    // SAFETY: This avoids initializing memory, then fills it immediately.
    let mut arr: Vec<i32> = Vec::with_capacity(n);
    unsafe {
        arr.set_len(n);
    }
    // Fill with iota (0..n) fast
    arr.iter_mut().enumerate().for_each(|(i, x)| *x = i as i32);

    let target: i32 = (n - 1) as i32;
    println!("Searching for element {}...", target);

    let start = Instant::now();
    let idx = linear_search(&arr, target);
    let elapsed = start.elapsed();

    let elapsed_ns = elapsed.as_secs() * 1_000_000_000 + u64::from(elapsed.subsec_nanos());
    let elapsed_ms = elapsed_ns as f64 / 1e6;

    match idx {
        Some(idx) => println!("Element {} found at index {}.", target, idx),
        None => println!("Element {} not found.", target),
    }
    println!(
        "Search completed in {} nanoseconds ({:.2} ms).",
        elapsed_ns, elapsed_ms
    );
}

#[inline(always)]
fn linear_search(arr: &[i32], target: i32) -> Option<usize> {
    for (idx, &elem) in arr.iter().enumerate() {
        if elem == target {
            return Some(idx);
        }
    }
    None
}
