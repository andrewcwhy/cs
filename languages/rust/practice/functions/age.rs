use std::io;

fn main() {
    let your_age = prompt_age();
    println!("You are {} years old.", your_age);
}

fn prompt_age() -> u32 {
    println!("Enter your age: ");

    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");

    let age: u32 = input.trim().parse().expect("Please enter a valid number");
    age
}
