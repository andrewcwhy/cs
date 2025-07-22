use std::io;

fn main() {
    println!("What month were you born?");
    println!("Enter a number from 1 to 12.");

    println!("Birth month: ");

    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ];

    println!("You were born in {}.", months[input - 1]);
}
