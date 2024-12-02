// rustup doc --std
use std::fs;
use std::vec::Vec;

fn is_inc(a: &[i32]) -> bool {
    a.windows(2).all(|w| w[0] < w[1] && (1..4).contains(&w[0].abs_diff(w[1])))
}

fn ok(a: &[i32]) -> bool {
    is_inc(a) || is_inc(&a.iter().rev().copied().collect::<Vec<i32>>())
}


fn main(){
    const FILE_PATH:&str = "./in.txt";
    let content = fs::read_to_string(FILE_PATH).expect("Should have been able to read the file");
    let mut ans:u32 = 0;
    for line in content.lines(){
        let report: Vec<i32> = line
        .split_whitespace()
        .map(|num| num.parse::<i32>().unwrap())
        .collect();
        
        let mut valid:bool = false;
        
        if ok(&report){
            ans += 1;
            continue;
        }
        for i in 0..report.len() {
            let mut aux = Vec::new();
            aux.extend_from_slice(&report[0..i]);
            aux.extend_from_slice(&report[i+1..]);
            if ok(&aux) {
                valid = true;
                break;
            }
        }
        if valid {
            ans+=1;
        }
        
    }

    println!("ans = {}",ans);
}