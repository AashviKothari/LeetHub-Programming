class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        // We can reduce the problem such that we have only 1 jar of capacity j1 + j2
        // We can do 4 operations on it namely : +j1, +j2, -j1, -j2
        // If we can reach the target ... Then return true .. else false
        
        // The currCap in jar can not be negative and cannot be more than the totalCap
        // Also, we will not make the curr state which we have already visited
        
        int totalCap = jug1Capacity + jug2Capacity;
        
        queue<int> q;
        q.push(0);
        
        vector<int> operations = {
            jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity
        };
        
        unordered_set<int> vis;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int nextStep : operations){
                int next = nextStep + curr;
                
                if(next == targetCapacity) return true;
                
                if(next >= 0 && next <= totalCap && vis.count(next) == 0){
                    q.push(next);
                    vis.insert(next);
                }
            }
        }
        
        return false;
    }
};