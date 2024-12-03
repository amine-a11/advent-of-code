use std::fs;
use regex::Regex;
use std::vec::Vec;

fn main() {
    const FILE_PATH:&str = "src/in.txt";
    let content = fs::read_to_string(FILE_PATH).expect("Should have been able to read the file");
    let mut ans:i64 = 0;
    let re = Regex::new(r"don't\(\)|mul\(\d+,\d+\)|do\(\)").unwrap();
    for line in content.lines(){
        let vals: Vec<String> = re.find_iter(line).map(|mat| mat.as_str().to_string()).collect();
        let mut ok = true;
        let mut s:i64 = 0;
        for val in vals{
            if val == "do()"{
                ok = true;
                continue;
            }else if val == "don't()"{
                ok = false;
                continue;
            }else if ok {
                let nums: Vec<i64> = val[4..val.len()-1].split(',').map(|s|s.parse::<i64>().unwrap()).collect();
                s+=nums[0]*nums[1];
            }
        }
        ans+=s;
    }
    println!("ans = {}",ans);
}
