//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool check(vector<int> &stalls,int mind,int k)
    {
        int cow=1;
        int lastcow=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if((stalls[i]-lastcow)>=mind)
            {
            cow++;
            lastcow=stalls[i];
            if(cow==k)
            {
                return true;
            }
            }
        }
        return false;
        
    }

    int aggressiveCows(vector<int> &stalls, int k) {
    int n=stalls.size(),result;
    sort(stalls.begin(),stalls.end());
    int mind=1,maxd=stalls[n-1]-stalls[0];
    while(mind<=maxd)
    {  
        int mid=mind+(maxd-mind)/2;
        if(check(stalls,mid,k))
        {
            result=mid;
            mind=mid+1;
        }
        else
        maxd=mid-1;
    }
    return result;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends