struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = std::collections::HashMap::with_capacity((nums.len() / 2) as usize);
        let mut res = vec![];
        for i in 0..nums.len() {
            let a = nums.get(i).unwrap();
            if let Some(idx_b) = map.get(&(target - a)) {
                res.push(*idx_b as i32);
                res.push(i as i32);
                break;
            } else {
                map.insert(nums.get(i).unwrap(), i as i32);
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::two_sum(vec![2, 7, 11, 15], 9));
}
