use std::fs;
use regex::Regex;
use std::vec::Vec;

fn main() {
    const FILE_PATH:&str = "src/in.txt";
    let content = fs::read_to_string(FILE_PATH).expect("Should have been able to read the file");
    let mut ans:i64 = 0;
    let re = Regex::new(r"mul\((\d+),(\d+)\)").unwrap();
    for line in content.lines(){
        let mut s:i64 = 0;
        let numbers: Vec<i64> = re.captures_iter(line).flat_map(|val| vec![val[1].parse::<i64>().unwrap(), val[2].parse::<i64>().unwrap()]).collect();
        let mut i = 1;
        while i<numbers.len(){
            s+=numbers[i]*numbers[i-1];
            i=i+2;
        }
        ans=ans+s;
    }
    println!("ans = {}",ans);
}
