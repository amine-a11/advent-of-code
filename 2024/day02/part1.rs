// rustup doc --std
use std::fs;
use std::vec::Vec;

fn main(){
    const FILE_PATH:&str = "./in.txt";
    let content = fs::read_to_string(FILE_PATH).expect("Should have been able to read the file");
    let mut ans:u32 = 0;
    for line in content.lines(){
        let report: Vec<i32> = line
        .split_whitespace()
        .map(|num| num.parse::<i32>().unwrap())
        .collect();
        if report.windows(2).all(|w| w[0] < w[1] && (1..4).contains(&w[0].abs_diff(w[1])) ) || report.windows(2).all(|w| w[0] > w[1] && (1..4).contains(&w[0].abs_diff(w[1])) ){
            ans+=1;
        };
    }

    println!("ans = {}",ans);
}