// C++ program to find minimum element in a 
// sorted and rotated array using binary search

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
      
        if (arr[low] < arr[high])        
            return arr[low];
      
        int mid = (low + high) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    return arr[low]; 
}

int main() {
    vector<int> arr = {5, 6, 2, 3, 4};
    cout << findMin(arr) << endl;
    return 0;
}
