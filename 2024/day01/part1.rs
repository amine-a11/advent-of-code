
use std::fs;
use std::vec::Vec;

fn main(){
    const FILE_PATH:&str = "./in.txt";
    let content = fs::read_to_string(FILE_PATH).expect("Should have been able to read the file");
    let mut v1 : Vec<i64> = Vec::new();
    let mut v2 : Vec<i64> = Vec::new();
    for line in content.lines(){
        let parts: Vec<i64> = line
        .split_whitespace()
        .map(|num| num.parse::<i64>().unwrap())
        .collect();
        v1.push(parts[0]);
        v2.push(parts[1]);
    }
    v1.sort_unstable();
    v2.sort_unstable();
    let mut ans:u64 = 0;
    for i in 0..v1.len(){
        ans+=v1[i].abs_diff(v2[i]);
    }
    println!("{}",ans);
}