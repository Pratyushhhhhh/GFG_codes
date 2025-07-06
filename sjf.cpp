// User function Template for C++

//Back-end complete function Template for C++

class Solution {
    struct process 
    {
        double at,bt,ct,tt,wt;
    };
  public:
    vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n) {
        // Write your code here
        vector<process>pro(n);
        for(int i=0;i<n;i++)
        {
            pro[i]={arrivalTime[i],burstTime[i],0,0,0};
        }
        
      int currTime=0,completed=0;
      vector<bool>done(n,false);
      double TWT=0,TAT=0;
      while(completed<n)
      {
          int idx=-1;
          int minBurst = INT_MAX;
          
          for(int i=0;i<n;i++)
          {
              if(!done[i] && pro[i].at<=currTime)
              {
                  if(pro[i].bt<minBurst)
                  {
                      minBurst=pro[i].bt;
                      idx=i;
                  }
              }
          }
          if(idx!=-1)
          {
              currTime+=pro[idx].bt;
              pro[idx].ct=currTime;
              pro[idx].tt=pro[idx].ct-pro[idx].at;
              pro[idx].wt=pro[idx].tt-pro[idx].bt;
              
              TWT+=pro[idx].wt;
              TAT+=pro[idx].tt;
              done[idx]=true;
              completed++;
              
          }
          else{
              currTime++;
          }
      }
        vector<double>ans;
        ans.push_back(TWT/n);
        ans.push_back(TAT/n);
        return ans;
    }
};
s