#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int num) {
    for(int i = 2; i < num - 1; i++ ){
        if(num % i == 0) 
            return false;
    }
    return true;
}

vector<int> GenRandomVec(int numOfNums,int min, int max) {
    
    vector<int> randInt;
    srand(time(NULL));
    for( int i = 0; i < numOfNums; i++){
    int randVal = min + rand() % ((max + 1) - min);
        if(IsPrime(randVal))
            randInt.push_back(randVal);
    }
    return randInt;
}

int main() {
    // Write C++ code here
    int numOfNums,minN,maxN;
    vector<int> randomVec;
    cout << "Enter Num of Prime numbers: ";
    cin >> numOfNums;
    cout << "Enter the min num: ";
    cin >> minN;
    cout << "Enter the max num: ";
    cin >> maxN;
    randomVec = GenRandomVec(numOfNums,minN,maxN);
    
    for(auto x: randomVec){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}