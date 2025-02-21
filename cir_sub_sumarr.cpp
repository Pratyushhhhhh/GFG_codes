//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int tsum=0,cmxsum=0,cmnsum=0;
        int maxsum=arr[0],minsum=arr[0];
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            cmxsum=max(cmxsum+arr[i],arr[i]);
            maxsum=max(maxsum,cmxsum);
            
            cmnsum=min(cmnsum+arr[i],arr[i]);
            minsum=min(minsum,cmnsum);
            
            tsum+=arr[i];
        }
        int normalsum=maxsum;
        int cirsum=tsum-minsum;
        if(minsum==tsum)
        return normalsum;
        
        return max(normalsum,cirsum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends