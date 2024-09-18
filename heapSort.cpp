#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>&v, int heapSize, int index) {
    
    int leftChildIndex = 2*index + 1, rightChildIndex = 2*index + 2;
    
    int largestElementIndex = index;
    if(leftChildIndex < heapSize && v[leftChildIndex] > v[largestElementIndex])
        largestElementIndex = leftChildIndex;
    
    if(rightChildIndex < heapSize && v[rightChildIndex] > v[largestElementIndex]) 
        largestElementIndex = rightChildIndex;
    
    if(largestElementIndex != index) {
        swap(v[index], v[largestElementIndex]);
        maxHeapify(v, heapSize, largestElementIndex);
    }
}

void heapSort(vector<int>& v) {
    
    int heapSize = v.size();
    
    // build max heap
    for(int i= heapSize/2-1; i>=0; i--) {
        maxHeapify(v, heapSize, i);
    }

    // sort
    for(int i=heapSize-1; i>0; i--) {
        swap(v[0], v[i]);
        heapSize--;
        maxHeapify(v, heapSize, 0);
    }
}

int main() {
	
	vector<int> v = {8,1,4,9,1,1,2,7,8,8,8,6,6,8,9,7,3,0,4,4};
	
	heapSort(v);
	
	for(int i=0; i<v.size(); i++)
	    cout<<v[i]<<' ';
	
	return 0;
}


