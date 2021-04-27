#include <String>
#include <vector>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int findDecodedNum(int secretNum){
    /*
    Just need to do this part
        d = 89
        n = 187
        need to do secretNum^89 (rem 187) and return it
    */
    return secretNum;
}

char convertToLetter(int decodedNum){
    decodedNum -= 1;
    decodedNum += 'a';
    if(decodedNum <= 122)
        return decodedNum;
    else if(decodedNum == 123)
        return ' ';
    else if(decodedNum == 124)
        return '"';
    
    return '.';
}  

string DecodeMessage(string fileName){
    vector<int> key(184);
    fill(key.begin(), key.end(), 0);
    ifstream input;
    input.open(fileName);

    int decodedNum;
    string finalString;
    int current;

    while(!input.eof()){
        input >> current;
        input.ignore();
        if(key[current] == 0){
            decodedNum = findDecodedNum(current);
            key[current] = decodedNum;
        }else{
            decodedNum = key[current];
        }
        finalString += convertToLetter(decodedNum);
    }

    return finalString;
} 