/*
PROBLEM LINK: https://leetcode.com/problems/greatest-sum-divisible-by-three/

SOLUTION IDEA:

Sum all the values and then try to remove the min possible values.
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem2, rem1;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(nums[i]%3 == 1){
                rem1.push_back(nums[i]);
            }else if(nums[i]%3 == 2){
                rem2.push_back(nums[i]);
            }
        }
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());
        if(sum%3 == 0) return sum;
        if(sum%3 == 1){
            int mn = INT_MAX;
            if(rem1.size()){
                mn = min(mn, rem1.front());
            }
            if(rem2.size() > 1){
                mn = min(mn, rem2[0]+rem2[1]);
            }
            if(mn != INT_MAX) sum -= mn;
        }else{
            int mn = INT_MAX;
            if(rem2.size()){
                mn = min(mn, rem2.front());
            }
            if(rem1.size() > 1){
                mn = min(mn, rem1[0]+rem1[1]);
            }
            if(mn != INT_MAX) sum -= mn;
        }
        return sum;
    }
};
