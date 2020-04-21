struct Solution {}

impl Solution {
    fn add_char(res: &mut String, ss: &Vec<char>, nth: i32) {
        let nth = nth as usize;
        if nth < ss.len() {
            res.push(ss[nth]);
        }
    }
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }
        let each = num_rows * 2 - 2;
        let parts = (s.len() as f64 / each as f64).ceil() as i32;
        let chars = s.chars().collect();
        let mut res = String::new();
        for row in 0..num_rows {
            for part in 0..parts {
                match row {
                    0 => Self::add_char(&mut res, &chars, each * part),
                    _ if row == num_rows - 1 => {
                        Self::add_char(&mut res, &chars, each * part + num_rows - 1)
                    }
                    _ => {
                        Self::add_char(&mut res, &chars, each * part + row);
                        Self::add_char(&mut res, &chars, (each - row) + each * part);
                    }
                }
            }
        }
        res
    }
}

fn main() {
    assert_eq!(
        "PINALSIGYAHRPI",
        Solution::convert("PAYPALISHIRING".to_string(), 4)
    );
}
