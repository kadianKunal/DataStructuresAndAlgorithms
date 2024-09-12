#include <bits/stdc++.h>
using namespace std;

/**
 * Performs binary search for given number on given array of numbers
 * If number is found, it returns index of number in array, else if number is not found, it returns -1
 * It requires the given array to be sorted
 */
int binarySearch(vector<int>&v, int number) {
    
    if(v.empty()) {
        return -1;
    }
    
    if(v.size() == 1) {
        return (v[0] == number) ? 0 : -1;
    }
    
    int leftIndex = 0, rightIndex = v.size()-1;
    while(leftIndex <= rightIndex) {
        int midIndex = (leftIndex + rightIndex) / 2;
        
        if(v[midIndex] > number) {
            rightIndex = midIndex-1;
        }
        else if(v[midIndex] < number) {
            leftIndex = midIndex+1;
        }
        else {
            return midIndex;
        }
    }
    
    return -1;
}

int main() {
    
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16};
	
	cout<<binarySearch(v, 9)<<'\n';
	cout<<binarySearch(v, 16)<<'\n';
	cout<<binarySearch(v, 10)<<'\n';
	cout<<binarySearch(v, 0)<<'\n';
	cout<<binarySearch(v, 100)<<'\n';
}

