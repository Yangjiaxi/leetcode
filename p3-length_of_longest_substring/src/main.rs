struct Solution {}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut prev_appear = std::collections::HashMap::new();
        let (mut left, mut max) = (0, 0);
        for (idx, c) in s.chars().enumerate() {
            if let Some(c_prev_idx) = prev_appear.get(&c) {
                if *c_prev_idx >= left { left = *c_prev_idx + 1; }
                *prev_appear.get_mut(&c).unwrap() = idx;
            } else { prev_appear.insert(c, idx); }
            let right = idx + 1;
            max = if max < right - left { right - left } else { max };
        }
        max as i32
    }
}

fn main() {
    assert_eq!(Solution::length_of_longest_substring("bbbbb".to_string()), 1);
    assert_eq!(Solution::length_of_longest_substring("tmmzuxt".to_string()), 5);
    assert_eq!(Solution::length_of_longest_substring("pwwkew".to_string()), 3);
}