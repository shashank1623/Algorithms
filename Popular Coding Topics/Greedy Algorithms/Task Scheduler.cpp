/*
problem statement:-

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

solution:-

*/

int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(auto i :tasks)
        {
            mp[i-'A']++;
        }
        sort(mp.begin(),mp.end());
        int maxFreq = mp[25]-1;
        int idleSlot = maxFreq*n;
        
        for(int i=24;i>=0;i--)
        {
            idleSlot-=min(mp[i],maxFreq);
        }   
        return idleSlot>0?idleSlot+tasks.size():tasks.size(); 
    
  
}

//problem link:- https://leetcode.com/problems/task-scheduler/
