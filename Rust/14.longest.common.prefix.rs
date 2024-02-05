impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return String::new();
        }

        // Sort the vector of strings
        let mut sorted_strs = strs.clone();
        sorted_strs.sort();

        // Take the first and last strings after sorting
        let first = sorted_strs.first().unwrap();
        let last = sorted_strs.last().unwrap();

        // Find the common prefix between the first and last strings
        let common_prefix: String = first.chars().zip(last.chars())
            .take_while(|(a, b)| a == b)
            .map(|(a, _)| a)
            .collect();

        common_prefix
    }
}

fn main() {
    let strs = vec![
        String::from("flower"),
        String::from("flow"),
        String::from("flight"),
    ];

    let result = Solution::longest_common_prefix(strs);

    println!("Longest Common Prefix: {}", result);
}