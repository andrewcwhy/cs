fn main() {
    let friends = ["Briana", "Elan", "Holden", "Reem"];

    for friend in friends {
        if friend == "Briana" {
            println!("Briana is my sister and firend.");
        } else if friend == "Reem" {
            println!("Reem was my orientation leader and now my friend!");
        } else {
            println!("{} is my friend.", friend);
        }
    }
}
