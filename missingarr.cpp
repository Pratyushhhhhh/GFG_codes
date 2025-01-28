//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // code here
        int s1=0,s2=0,nos;
        nos=arr.size()+1;
        s1=nos*(nos+1)/2;
       
        for(size_t i=0; i<arr.size();i++)
        {
            s2+=arr[i];
        }
        return (s1-s2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        //int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends