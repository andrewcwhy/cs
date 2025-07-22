use std::io;

fn main() {
    let mut applied: bool = false;

    while !applied {
        println!("Have you applied for internships? (yes/no): ");

        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read input");

        let input = input.trim().to_lowercase();

        if input == "yes" {
            applied = true;
        } else {
            println!("APPLY!");
        }
    }

    println!("Congratualtions on successfully applying for an internship!");
    println!("Now get an internship.");
}
