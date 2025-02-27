//count no of 1s in a sorted array in non increating order
// 1 1 1 1 0 0 0 o/p->4
// TC O(log n)
#include<bits/stdc++.h>
using namespace std;
class soln
{
    public:
        void create(vector<int>&arr,int size)
        {
            cout<<"Input values to array\n";
            int x;
            for(int i=0;i<size;i++)
            {
            cin>> x;
            arr.push_back(x);   
            }
        } 
            

        int c_ones(vector<int>arr,int low,int high)
        {
            if(low<=high)
            {
                int mid=low+(high-low)/2;
                if((mid==high || arr[mid+1]==0)&&arr[mid]==1)
                return mid+1;//if cond true that means no more 1s ahead of this point
                if(arr[mid]==1)
                return c_ones(arr,mid+1,high);

                return c_ones(arr,low,mid-1);
            }
            return 0;
        }

};

int main()
{
    soln obj;
    int n;
    cout<<"Enter no of test cases\n";
    cin>>n;
    
    int size,low=0,high;
    for(int i=0;i<n;i++)
    {
        vector<int> arr;
        cout<<"input size\n";
        cin>>size;
        obj.create(arr,size);
        high=arr.size()-1;
        int x=obj.c_ones(arr,low,high);
        cout<<"OUTPUT\n"<<x<<"\n";
    }

}