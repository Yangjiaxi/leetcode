struct Solution {}

use std::cmp::Ordering::{Equal, Greater, Less};

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.len() < 3 {
            return vec![];
        }
        let mut sorted = nums.clone();
        sorted.sort();
        let mut res = Vec::new();
        for i in 0..sorted.len() - 2 {
            let a = sorted[i];
            if i > 0 && a == sorted[i - 1] {
                continue;
            }
            let (mut x, mut y) = (i + 1, sorted.len() - 1);
            while x < y {
                let (b, c) = (sorted[x], sorted[y]);
                let sum = a + b + c;
                if sum > 0 {
                    y -= 1;
                } else if sum < 0 {
                    x += 1;
                } else {
                    res.push(vec![a, b, c]);
                    while x < y && sorted[x] == sorted[x + 1] {
                        x += 1;
                    }
                    while x < y && sorted[y] == sorted[y - 1] {
                        y -= 1;
                    }
                    x += 1;
                    y -= 1;
                }
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::three_sum(vec![-1, 0, 1, 2, -1, -4]));
    println!("{:?}", Solution::three_sum(vec![]));
    println!("{:?}", Solution::three_sum(vec![0]));
    println!("{:?}", Solution::three_sum(vec![-1, 1]));
    println!("{:?}", Solution::three_sum(vec![0, -1, 1]));
    println!("{:?}", Solution::three_sum(vec![-2, 0, 0, 2, 2]));
}
