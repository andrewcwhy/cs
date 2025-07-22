fn main() {
    let mut number = 9;

    if number < 7 {
        println!("{} is less than {}", number, 7);
    } else {
        println!("Condition false");
    }

    number = 7;

    if number != 0 {
        println!("Number was something other than zero");
    }
}
