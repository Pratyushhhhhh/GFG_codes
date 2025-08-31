class Solution {
    private:
        void subsetsum(int ind, int s,vector<int>arr,vector<int>&sums)
        {
            if(ind==arr.size())
            {
                sums.push_back(s);
                return;
            }
            
            subsetsum(ind+1,s+arr[ind],arr,sums);
            subsetsum(ind+1,s,arr,sums);
        }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>sums;
        subsetsum(0,0,arr,sums);
        sort(sums.begin(), sums.end());
        return sums;
    }
};