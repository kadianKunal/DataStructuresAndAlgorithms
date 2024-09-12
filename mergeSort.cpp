#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int main() {
    vector<int> v = {8, 1, 4 ,9, 1, 1, 2 ,7 ,8, 8, 8, 6, 6, 8, 9, 7, 3 ,0, 4, 4};
    
    mergeSort(v, 0, v.size()-1);
    
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }

}

void mergeSort(vector<int>& v, int l, int r) {
    
    if(l == r) return; // single elements is already sorted
        
    int mid = (l + r) / 2;
    
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);
    
    merge(v, l, mid, r);
}

void merge(vector<int>& v, int l1, int r1, int r2) {
    
    vector<int> arr1(v.begin()+l1, v.begin()+r1+1), arr2(v.begin()+r1+1, v.begin()+r2+1);
    int arr1Index = 0, arr2Index = 0, vIndex = l1;
    
    while(arr1Index < arr1.size() && arr2Index < arr2.size()) {
        
        if(arr1[arr1Index] < arr2[arr2Index]) 
            v[vIndex++] = arr1[arr1Index++];
        else 
            v[vIndex++] = arr2[arr2Index++];
    }
    
    while(arr1Index < arr1.size()) 
        v[vIndex++] = arr1[arr1Index++];
    
    while(arr2Index < arr2.size()) 
        v[vIndex++] = arr2[arr2Index++];
    
}
