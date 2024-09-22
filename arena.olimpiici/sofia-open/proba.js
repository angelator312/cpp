const cdPs = require("child_process");
const { log } = require("console");
const fs = require("fs");
const { max } = Math;
let command = "./2023-E1.exe";
let n = 20;
let m = "";
let yes = 0, no = 0;

function startingF() {
    let n = [];
    m="";
    n[0] = Math.floor(Math.random() * 1000);
    n[1] = Math.floor(Math.random() * 1000);
    n[2] = Math.floor(Math.random() * 1000);
    n[3] = Math.floor(Math.random() * 1000);
    n[4] = Math.floor(Math.random() * 1000);
    m += " " + n[0];
    m += " " + n[1];
    m += " " + n[2];
    m += " " + n[3];
    m += " " + n[4];

    fs.writeFile("./1.in", m, (err) => {
        if (err) {
            throw "There is error in file editing \n" + err;
        }
    })
    return n;
}

function exitingF(n) {
    // log("E")
    let e = Math.max(n[0], n[1]) - Math.min(n[0], n[1])
    let out = e * n[2] + max(e - 2, 0) * n[3] + max(e - 1, 0) * n[4]
    fs.readFile("1.out", (err, data) => {
        if (err) {
            log(err);
            throw "There is error in file reading \n" + err;

        }
        let data2 = data.toString().trim();
        log(data2);
        log(out);
        if (out == data2) {
            yes++;
        } else {
            no++;
        }
    })
}



function main() {
    for (let i = 0; i < n; i++) {
        let ni = startingF();
        cdPs.exec(command + " < 1.in > 1.out")
        exitingF(ni);
    }
    console.log("Yes :", yes, " No: ", no);
}



main()
