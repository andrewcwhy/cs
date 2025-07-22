fn main() {
    let mut age = 0;

    let andrews_age = loop {
        age += 1;

        if age == 9 {
            break 1 + (age * 2);
        }
    };

    println!("Andrew is {} years old", { andrews_age });
}
