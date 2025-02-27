//{ Driver Code Starts
// Initial template for C++
//Count zeros in sorted array of inc order
//O(logn)
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) 
    {
        // code here
        int n=arr.size();
        int low = 0, high = n - 1,fc=-1;
        while (low <= high) 
        { 
        int mid = (low + high) / 2;
        if(arr[mid]==0)
        {
            fc=mid;
            high=mid-1;
        }
        else
            low=mid+1;
        }
        if(fc==-1)
            return 0;
        else
            return n-fc;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.countZeroes(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends