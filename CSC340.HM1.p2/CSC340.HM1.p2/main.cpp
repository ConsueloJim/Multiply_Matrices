//
//  main.cpp
//  CSC340.HM1.p2
//
//  Created by Consuelo Jimenez on 2/17/15.
//  Copyright (c) 2015 Consuelo Jimenez. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declare function prototypes
vector<int> readData(vector<int> &numbers);
vector<int> selectionSort(vector<int> &numbers);
void printVector(vector<int> &numbers);

 vector<int> readData(vector<int> &numbers){
    int input;
    cout << "Please enter an array of numbers. Enter -1 when finished: ";
    cin >> input;
    
    //Ends while loop when it sees -1
    while( input != -1) {
        numbers.push_back(input);
        cin >> input;
    }
    return numbers;
}

vector<int> selectionSort(vector<int> &numbers){
    int startScan, minIndex, minValue;
   
    for( startScan = 0; startScan< numbers.size()-1; startScan++){
        minIndex= startScan;
        minValue = numbers[startScan];
        
        for(int index = startScan + 1; index<numbers.size(); index++){
           
            if(numbers[index] < minValue)
            {
                minValue = numbers[index];
                minIndex = index;
            }
        }
        numbers[minIndex] = numbers[startScan];
        numbers[startScan] = minValue;
    }
    return numbers;
  
}

void printVector(vector<int> &numbers){
    
    for(int i=0; i<numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numberV;
    numberV = readData(numberV);
    cout << "Vector unsorted : ";
    printVector(numberV);
    cout << endl;
    vector<int> numSort = selectionSort(numberV);
    cout << "Vector sorted: " ;
    printVector(numSort);
}