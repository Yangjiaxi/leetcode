#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution {}

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut res: Option<Box<ListNode>> = None;
        let mut res_node = &mut res;

        let mut cur_1 = l1;
        let mut cur_2 = l2;
        let mut overflow = 0;
        loop {
            if cur_1 == None && cur_2 == None { break; }
            let (a, cur_1_next) = match cur_1 {
                Some(ref inner) => (inner.val, inner.next.clone()),
                None => (0, None),
            };
            let (b, cur_2_next) = match cur_2 {
                Some(ref inner) => (inner.val, inner.next.clone()),
                None => (0, None),
            };
            let sum = a + b + overflow;
            overflow = if sum >= 10 { 1 } else { 0 };
            let new_node = Box::new(ListNode::new(sum % 10));
            if let Some(inner) = res_node {
                inner.next = Some(new_node);
                res_node = &mut inner.next;
            } else {
                *res_node = Some(new_node);
            }
            cur_1 = cur_1_next;
            cur_2 = cur_2_next;
        }
        if overflow == 1 {
            let new_node = Box::new(ListNode::new(1));
            if let Some(inner) = res_node {
                inner.next = Some(new_node);
                res_node = &mut inner.next;
            }
        }
        res
    }
}

fn print_list(list: Option<Box<ListNode>>) {
    let mut node = list;
    while let Some(inner) = node {
        print!("{:?}->", inner.val);
        node = inner.next;
    }
    println!();
}

fn make_list(arr: Vec<i32>) -> Option<Box<ListNode>> {
    if let Some((val, rest)) = arr.split_first() {
        Some(Box::new(ListNode {
            val: *val,
            next: make_list(Vec::from(rest)),
        }))
    } else {
        None
    }
}

fn main() {
    let list_a = make_list(vec![5]);
    let list_b = make_list(vec![5]);
    print_list(Solution::add_two_numbers(list_a, list_b));
}
