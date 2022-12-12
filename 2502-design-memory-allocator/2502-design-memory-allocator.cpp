class Allocator {
public:
    vector<int> vec;
    int sz;
    unordered_map<int, vector<int>> um;
    Allocator(int n) {
       
        vec.assign(n,-1);
        sz=n;
    }
    
    int allocate(int size, int mID) {
        
        // first check if continuous block free, idx is starting point of free block
        int free=0, idx;
        for(int i=0;i<sz;i++)
        {
            if(free==0) idx=i;
            if(vec[i]==-1) free++; // empty continuous block
            else free=0;
            
            if(free>=size) break; // break from for inner loop not func
        }
        
        if(free>=size)
        {
            for(int i=idx;i<idx+size;i++)
            {
                vec[i]=mID;
                um[mID].push_back(i);
            }
        }
        
        return free>=size ? idx : -1 ; // returning starting point if free found else -1
        
    }
    
    int free(int mID) {
        
        int count=0;
        for(auto x: um[mID])
        {
            vec[x]=-1; // deallocate to -1
            count++;
        }
        // remove mID from map
        um.erase(mID);
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

// for allocate, check the free memory first. Traverse the vec and if vec[i]==-1, make free=0 and keep going right
// till vec[i]!=-1 and then compare free and size, if free<size free=0 otherwise break as free==size 

// for indices of each element we can use map which stores element and it's indices