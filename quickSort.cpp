#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>&, int, int);
void swap(int&, int&);

int main() {
    
	vector<int> v = {8, 1, 4 ,9, 1, 1, 2 ,7 ,8, 8, 8, 6, 6, 8, 9, 7, 3 ,0, 4, 4};
	
	quickSort(v, 0, v.size()-1);
	
	for(int i=0; i<v.size(); i++) {
	    cout<<v[i]<<" ";
	}

}

void quickSort(vector<int>& v, int l , int r) {
    
    if(l >= r) return;
    
    // taking v[r] as pivot
    int index = l;
    for(int i=l; i<r; i++) {
        if(v[i] < v[r]) {
            swap(v[index], v[i]);
            index++;
        }
    }
    swap(v[index], v[r]);
    
    quickSort(v, l, index-1);
    quickSort(v, index+1, r);
    
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

