class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
        
        for(int i=0;i<rocks.size();i++)
        {
            capacity[i] = capacity[i]-rocks[i];
        }
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        
        for(auto c: capacity)
        {
            if(c!=0) pq.push(c);
        }
        
        while(!pq.empty() && extra >0)
        {
            int top=pq.top();
            
            if(extra < top) break;
            extra-=top;
            pq.pop();    
        }
        
        return capacity.size()-pq.size();
    }
};

// store the differences for rocks and capacity, push elements in priority queue(greater<int>) if not 0(difference)
// check top element and if additional >= pq.top(), pq.pop() and additional-= pq.top()