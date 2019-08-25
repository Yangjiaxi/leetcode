use std::cmp::{max, min};

struct Solution {}

impl Solution {
    fn get(arr: &Vec<i32>, idx: usize) -> i32 {
        *arr.get(idx).unwrap()
    }
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (len_1, len_2) = (nums1.len(), nums2.len());
        if len_1 > len_2 {
            return Solution::find_median_sorted_arrays(nums2, nums1);
        }
        let (mut left, mut right) = (0 as usize, len_1);
        let k = (len_1 + len_2 + 1) / 2;
        let mut res = 0.;
        while left <= right {
            let left_1 = (left + right) / 2;
            let left_2 = k - left_1;
            if left_1 < right && Self::get(&nums2, left_2 - 1) > Self::get(&nums1, left_1) {
                left = left_1 + 1;
            } else if left_1 > left && Self::get(&nums1, left_1 - 1) > Self::get(&nums2, left_2) {
                right = left_1 - 1;
            } else {
                let mut max_left = 0;
                if left_1 == 0 {
                    max_left = Self::get(&nums2, left_2 - 1);
                } else if left_2 == 0 {
                    max_left = Self::get(&nums1, left_1 - 1);
                } else {
                    max_left = max(Self::get(&nums1, left_1 - 1), Self::get(&nums2, left_2 - 1));
                }
                if (len_1 + len_2) % 2 == 1 {
                    res = max_left as f64;
                    break;
                }

                let mut min_right = 0;
                if left_1 == len_1 {
                    min_right = Self::get(&nums2, left_2);
                } else if left_2 == len_2 {
                    min_right = Self::get(&nums1, left_1);
                } else {
                    min_right = min(Self::get(&nums1, left_1), Self::get(&nums2, left_2));
                }
                res = (max_left + min_right) as f64 * 0.5;
                break;
            }
        }
        res
    }
}

fn main() {
    assert_eq!(
        Solution::find_median_sorted_arrays(vec![2], vec![1, 3, 5, 7, 9]),
        4.0
    );
    assert_eq!(
        Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4]),
        2.5
    );
    println!("Passed")
}
