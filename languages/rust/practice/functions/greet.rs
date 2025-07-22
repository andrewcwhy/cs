fn main() {
    greet("Andrew", 19);
}

fn greet(name: &str, age: u32) {
    println!("Well hello, {}. How does it feel being {}?", name, age);
}
