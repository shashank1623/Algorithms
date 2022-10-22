/*
problem statement:-
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

solution:-
*/
class Solution {
public:
    
	// O(logn)
    int countSetBits(int n){
        int c=0;
        while(n>0){
            int rmsb=n&(-n); // rightmost set bit
            n-=rmsb;
            c++;
        }
        return c;
    }
    
    int minimizeXor(int num1, int num2) {
        int c=countSetBits(num2);
        
        int x=0; // building answer by nullifying MSB's of 'num1' for 'Overall Minimum XOR'
        for(int bit=31;bit>=0;bit--){
            if((num1 & (1<<bit))>0 && c>0){
                x |= (1<<bit);
                c--;
            }
        }
        
	   // setting LSB's of 'x' so that 'count of set bits are same as num2' & keeping value of 'x' as minimum possible 
        for(int bit=0;bit<=31;bit++){
            if(c>0 && (x & (1<<bit))==0){
                x |= (1<<bit);
                c--;
            }
        }
        return x;
    }
};

//problem link:- https://leetcode.com/problems/minimize-xor/
