class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
       int n = gas.size();
       if (!n) return -1;
       int ret = 0;
       int start = 0;
       for (int i = 0; i < n; i++) {
           if (ret <= 0 && gas[i] < cost[i]) start = i + 1;
           ret += gas[i] - cost[i];
       }
       if (ret >= 0)
        return start;
    
        return -1;
    }
    
    //-----------------------------------------------//
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!gas.size()) 
            return 0;
        int cur = 0;
        int total = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            //If from xi to xj, sum of gas[i]-cost[i] < 0, 
            //it means you cannot start from any station from xi to xj.
            // (the gas left from xi -> x(i+1) >= 0)
            if (cur < 0) {
                index = i + 1;
                cur = 0;
            }    
        }
        return total >= 0 ? index : -1;        
    }

    /* O(n2) Solution
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!gas.size()) 
            return 0;
        for (int start = 0; start < gas.size(); start++) {
            int cnt = 0;
            //int total = 0;
            int cur = 0;
            int i = start;
            while (cnt < gas.size()) {
                //total += gas[i] - cost[i];
                cur += gas[i] - cost[i];
                cnt ++;
                i++;
                i %= gas.size();
                if (cur < 0) {
                    start = i;
                    break;
                }    
                if (cnt == gas.size()) return start;
            }
        }
        return -1;
    }
    */
};