//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// #include <algorithm>


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        size_t n=arr.size();
        for(size_t i=0;i<n-1;i+=2)
        {
            
                int t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
                
            
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t; // Input testcases
    cin.ignore();
    while (t--) // While testcases exist
    {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        sort(a.begin(), a.end());
        Solution ob;
        ob.convertToWave(a);

        for (size_t i = 0; i < a.size(); i++)
            cout << a[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
/*
2
5 6 7 8 9 10 11 12
6 5 8 7 10 9 12 11
~
2 5 6 7 8 9 10 11 12 
5 2 7 6 9 8 11 10 12
~
1
2 5 6 44 85 69 100 123 456 47778 
5 2 44 6 85 69 123 100 47778 456*/