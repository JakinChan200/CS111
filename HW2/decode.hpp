#include <String>
#include <vector>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int findDecodedNum(int coefficient, int secretNum, int exponent, int n){
    if(exponent == 1){
        return (secretNum * coefficient) % n;
    }else if(exponent % 2 == 0){
        exponent /= 2;
        secretNum = (secretNum * secretNum) % n;
        return findDecodedNum(coefficient, secretNum, exponent, n);
    }else if(exponent % 2 == 1){
        exponent -= 1;
        coefficient = (coefficient * secretNum) % n;
        return findDecodedNum(coefficient, secretNum, exponent, n);
    }
    return 0;
}

char convertToLetter(int decodedNum){
    decodedNum -= 3;
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
    int d = 89;
    int n = 187;
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
            decodedNum = findDecodedNum(1, current, d, n);
            key[current] = decodedNum;
        }else{
            decodedNum = key[current];
        }
        finalString += convertToLetter(decodedNum);
    }

    return finalString;
} 