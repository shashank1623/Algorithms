/*
PROBLEM LINK: https://leetcode.com/problems/minimum-money-required-before-transactions/
*/

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<vector<int> > lossMakers;
        vector<vector<int> > profitMakers;
        
        for(int i = 0; i<transactions.size(); i++){
            if(transactions[i][1] > transactions[i][0]){
                profitMakers.push_back(transactions[i]);
            }else{
                lossMakers.push_back(transactions[i]);
            }
        }
        long long ans = 0;
        sort(lossMakers.begin(), lossMakers.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[1] > v2[1];
        });
        sort(profitMakers.begin(), profitMakers.end(), [](vector<int> &v1, vector<int> &v2){
           return v1[0] > v2[0]; 
        });
        for(int i = 0; i<lossMakers.size(); i++){
            ans += lossMakers[i][0] - lossMakers[i][1];
        }
        long long ex = 0;
        if(profitMakers.size() == 0){
            ex = lossMakers.front()[1];
        }else{
            if(lossMakers.size()) ex = max(lossMakers.front()[1], profitMakers.front()[0]);
            else ex = profitMakers.front()[0];
        }
        ans += ex;
        return ans;
    }
};
