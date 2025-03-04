
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int key) {
  
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If key found, return the index
        if (arr[mid] == key)
            return mid;

        // If Left half is sorted
        if (arr[mid] >= arr[low]) {
          
            // If the key lies within this sorted half,
            // move the hi pointer to mid - 1
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
          
            // Otherwise, move the lo pointer to mid + 1
            else
                low = mid + 1;
        }
      
        // If Right half is sorted
        else {
          
            // If the key lies within this sorted half,
            // move the lo pointer to mid + 1
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
          
            // Otherwise, move the hi pointer to mid - 1
            else
                high = mid - 1;
        }
    }
    
      // Key not found
    return -1; 
}

int main() {
    vector<int> arr1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key1 = 3;
    cout << search(arr1, key1) << endl;

    return 0;
}
