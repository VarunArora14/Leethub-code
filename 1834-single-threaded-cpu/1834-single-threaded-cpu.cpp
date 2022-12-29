using pii  = pair<int,int>;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i); // push index to store and later use in ans
        }
        
        sort(tasks.begin(), tasks.end()); // sort per their starting time
        
        int idx=0; // index of tasks we traverse
        long long time=tasks[0][0]; // set starting time as smallest to avoid iterating idle
        vector<int> ans;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq; // stores smallest process time task with it's index
        
        while(ans.size()<tasks.size())
        {
            // push all tasks in pq having start time <= time considering all tasks can be same time
            while(idx<tasks.size() && tasks[idx][0]<=time)
            {
                pq.push({tasks[idx][1], tasks[idx][2]}); // push the process time and index
                idx++; // go to next task
            }
            
            if(!pq.empty())
            {
                auto [tprocess, tidx] = pq.top(); // top processing time and it's index
                pq.pop();
                
                ans.push_back(tidx); // push index as ans 
                time+=tprocess; // add processing time for next process to be considered whose time will now be
                // smaller than this new 'time'
            }
            else if(idx<tasks.size())
            {
                // if there happens to be idle gap between 2 tasks, cover it by going to next task starting time
                // here we just increase the time to when the next task can be pushed into the heap
                time = tasks[idx][0];
            }
            
        }
        
        return ans;
    }
};
// here we have to not just care abt early time but smallest processing_time as well

// we sort the tasks first as per their time and when their starting_time comes, push into another DS
// which stores them as per their processing time

// since we need to get the index, we have to find way to hold it, we can push index in each vector<int>
// and then later sort and use min heap