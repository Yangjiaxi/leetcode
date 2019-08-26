struct Solution {}

use std::cmp::{max, min};

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut i, mut j) = (0, height.len() - 1);
        let s = |i, j, cur| max(cur, (j - i) as i32 * min(height[i], height[j]));
        let mut res = s(i, j, 0);
        while i < j {
            if height[i] < height[j] {
                i += 1;
            } else {
                j -= 1;
            }
            res = s(i, j, res);
        }
        res
    }
}

fn main() {
    assert_eq!(Solution::max_area(vec![1, 8, 6, 2, 5, 4, 8, 3, 7]), 49);
}
