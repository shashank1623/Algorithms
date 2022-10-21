// problem statement:-
// Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

// Return the minimum number of substrings in such a partition.

// Note that each character should belong to exactly one substring in a partition.

// solution:-

int partitionString(string s) {
    int pos[26] = {}, res = 0, last = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (pos[s[i] - 'a'] >= last) {
            ++res;
            last = i + 1;
        }
        pos[s[i] - 'a'] = i + 1;
    }
    return res;        
}



// problem link:-https://leetcode.com/problems/optimal-partition-of-string/
