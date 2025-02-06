//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int can1=-1,can2=-1,c1=0,c2=0;
        for (auto it:arr)
        {
            if(can1==it)
                c1++;
            else if(can2==it)
                c2++;
            else if(c1==0)
            {
                can1=it;
                c1++;
            
            }
            else if(c2==0)
            {
                can2=it;
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
            

        }
        int n=arr.size();
        vector<int> list;
        c1=0,c2=0;
        for(auto it:arr)
        {
            if(can1==it)c1++;
            if(can2==it)c2++;
        }
        if(c1>n/3)list.push_back(can1);
        if(c2>n/3 && can1!=can2) list.push_back(can2);
        
        if(list.size()==2 && list[0]>list[1])
            swap(list[0],list[1]);
        return list;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends