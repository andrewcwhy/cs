use std::io;

fn main() {
    name_prompt();
}

fn name_prompt() {
    println!("What is your name?");
    print!("Name: ");
    // Ensure prompt is printed before waiting for input
    use std::io::Write;
    std::io::stdout().flush().unwrap();

    let mut name = String::new();
    io::stdin()
        .read_line(&mut name)
        .expect("Failed to read line");

    let name = name.trim(); // Remove newline
    println!("Hello, {}!", name);
}
