
fn main() {
    println!("Hello, world!")
}

#[cfg(test)]
mod tests {
    #[test]
    fn example_case() {
        // Testcase from problem statement.
        aoc2022::example(
            "1000
2000
3000

4000

5000
6000

7000
8000
9000

10000",
            "24000"
        )
    }
}