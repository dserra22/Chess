#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "Pieces.h"

//#pragma once
using namespace std;

int fact(int first, int total) {
    if (first > 0) {
        total = fact(first-1, total*first);
    }
    return total;
}

bool checkX(string part) {
    for (auto &e : part) {
        if (e == 'x') {
            return true;
        }
    }
    return false;
}
void integral(string equation) {
    vector<string> nums;
    vector<string> newNums;
    string indNum = "";
    for (auto &e : equation) {
            if (e == '+' || e == '-' || e == '/' || e == '*') {
                nums.push_back(indNum);
                indNum = "";
            } else {
                indNum += e;
            }
    }
    nums.push_back(indNum);

    // compute
   for (int i = 0; i < nums.size(); ++i) {
       if (checkX(nums.at(i) ) ) {
           for (auto &e : nums)
       }


   }



}
int main() {
    integral("5x^2+3");

    cout << "Recursion" << endl;
   cout << fact(8, 1);
   cout << "Loop style" << endl;

    int total = 1;
    for (int i = 1; i < 9; ++i) {
        total *= i;
    }

cout << total;

    return 0;
}