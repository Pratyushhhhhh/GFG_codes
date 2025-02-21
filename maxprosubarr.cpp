//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        int maxp=INT_MIN;
        int left =1,right=1;
        for(int i=0;i<n;i++)
        {
            if(left==0)
            left=1;
            if(right==0)
            right=1;
            
            left*=arr[i];
            int j=n-i-1;
            right*=arr[j];
            
            maxp=max({left,right,maxp});
            
        }
        return maxp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends