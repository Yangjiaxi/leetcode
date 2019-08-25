struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        const INT_MAX: i32 = 2147483647;
        const INT_MIN: i32 = -2147483648;
        let mut res = 0;
        let mut number = x;
        while number != 0 {
            let head = number % 10;
            number /= 10;
            if res > INT_MAX / 10 || (res == INT_MAX / 10 && head > 7) {
                return 0;
            }
            if res < INT_MIN / 10 || (res == INT_MIN / 10 && head < -8) {
                return 0;
            }
            res = res * 10 + head;
        }
        res
    }
}

fn main() {
    assert_eq!(Solution::reverse(-123), -321);
    assert_eq!(Solution::reverse(123), 321);
    assert_eq!(Solution::reverse(2147483647), 0);
}
