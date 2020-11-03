use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input);
  input.retain(|c| !c.is_whitespace());

  let mut res = 0;
  for num in input.chars() {
    res += num.to_digit(10).unwrap().pow(2);
  }
  println!("{}", res % 10);
}
