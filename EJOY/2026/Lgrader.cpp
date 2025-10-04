#include <bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    ifstream codeinp("nod.txt");
    vector<vector<string>> code;
    while (getline(codeinp, line)) {
        istringstream iss(line);
        string word;
        vector<string> words;
        while (iss >> word) {
            words.push_back(word);
        }
        code.push_back(words);
    }
    int a,b;
    cin >> a >> b;
    int inputPointer = 0;
    int ans = __gcd(a,b);
    int contestant = -1;
    unordered_map<string, int> registers; // registers for machine code
    for(int lineNum = 0; lineNum < code.size(); lineNum++) {
        vector<string> line = code[lineNum];
        if(line.size()==0) continue;
        if(line[0]=="IN") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            assert(inputPointer <= 1);
            if(inputPointer == 0) {
                registers[line[1]]=a;
                inputPointer++;
            }
            else if(inputPointer == 1) {
                registers[line[1]]=b;
                inputPointer++;
            }
        }
        else if(line[0]=="OUT") {
            assert(contestant == -1);
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            contestant = registers[line[1]];
        }
        else if(line[0]=="MOV") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            assert(line[2]=="RES" || (line[2][0]>='A' && line[2][0]<='E'));
            registers[line[1]]=registers[line[2]];
        }
        else if(line[0]=="ADD") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            assert(line[2]=="RES" || (line[2][0]>='A' && line[2][0]<='E'));
            registers[line[1]]+=registers[line[2]];
        }
        else if(line[0]=="SUB") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            assert(line[2]=="RES" || (line[2][0]>='A' && line[2][0]<='E'));
            registers[line[1]]-=registers[line[2]];
        }
        else if(line[0]=="INC") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            registers[line[1]]++;
        }
        else if(line[0]=="DEC") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            registers[line[1]]--;
        }
        else if(line[0]=="CMP") {
            assert(line[1]=="RES" || (line[1][0]>='A' && line[1][0]<='E'));
            assert(line[2]=="RES" || (line[2][0]>='A' && line[2][0]<='E'));
            registers["RES"]=registers[line[1]]<registers[line[2]];
        }
        else if(line[0]=="JZ") {
            if(registers["RES"]==0) {
                assert(lineNum<=code.size() && lineNum>=1);
                lineNum = stoi(line[1])-2; // 1 for index and 1 because we jump to the next one on next iteration
            }
        }
        else if(line[0]=="JNZ") {
            if(registers["RES"]!=0) {
                assert(lineNum<=code.size() && lineNum>=1);
                lineNum = stoi(line[1])-2; // 1 for index and 1 because we jump to the next one on next iteration
            }
        }
        else if(line[0]=="RETURN") break;
        else if(line[0]==";") continue;

    }
    cout << contestant << endl;
}
