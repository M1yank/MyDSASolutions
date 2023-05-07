class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> a;
        bool res = false;
        for(auto &i:nums){
            if(a.find(i) == a.end()){
                a[i] = true;
            }
            else{
                return true;
            }
        }
        return false;
    }
};