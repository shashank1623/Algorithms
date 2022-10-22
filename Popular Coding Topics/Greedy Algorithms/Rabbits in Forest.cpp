/*
problem statement
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.
*/

class Solution {
public:
    int numRabbits(vector<int>& a) {
        sort(a.begin(),a.end()); // Sort The Values
        int ans = 0,count = 1; // Initilize Variables
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] != a[i-1]) { // Checking If Previous Value is Equal To Current
                int t = a[i-1] + 1; // Store Total Amount Of Rabits
                ans += ((count/t) + (count%t > 0))*t; // Formula
                count = 1;
            }
            else ++count;
        }
        int t = a[a.size() -1] + 1;
        ans += ((count/t) + (count%t > 0))*t;
        return ans;
    }
};

//  problem link-https://leetcode.com/problems/rabbits-in-forest/
 
