struct Solution {}

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.len() == 0 {
            return "".to_string();
        }
        let ss = s.as_bytes();
        let mut res = (0, 0, 1);
        for i in 0..ss.len() {
            let (l1, r1) = Self::spread(ss, i, i);
            let (l2, r2) = Self::spread(ss, i, i + 1);
            let (len_1, len_2) = (r1 - l1 + 1, r2 - l2 + 1);
            if len_1 > res.2 {
                res = (l1, r1, len_1);
            }
            if len_2 > res.2 {
                res = (l2, r2, len_2);
            }
        }
        s[res.0..=res.1].to_string()
    }

    fn spread(ss: &[u8], left: usize, right: usize) -> (usize, usize) {
        if ss.get(left) != ss.get(right) {
            return (left, left);
        }
        let (mut l, mut r) = (left, right);
        while ss.get(l) == ss.get(r) {
            if l == 0 || r == ss.len() {
                return (l, r);
            }
            l -= 1;
            r += 1;
        }
        (l + 1, r - 1)
    }
}

fn main() {
    println!("{:?}", Solution::longest_palindrome("bb".to_string()));
    println!("{:?}", Solution::longest_palindrome("abba".to_string()));
    println!("{:?}", Solution::longest_palindrome("".to_string()));
}
