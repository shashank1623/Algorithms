/*
    Infinite Knapsack in C++
    Submitted by Ashwin Prasanth (https://github.com/ashwinpra)  

    Problem Statement: 

    You are given a knapsack of a certain maximum capacity, 
    along with a certain number of items, each of which have a certain value and weight.

    You can add any item any number of times in the knapsack. 

    You have to find the optimal way of filling the knapsack such that the total value is maximised.


*/

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std; 

/*
	The problem is solved using dynamic programming as follows: 
		An array memo is made, of size C (capacity of the knapsack)

		The value at index i, i.e., memo[i] stores the maximum value that can be obtained from the given items, if the capacity of the 
		knapsack is "i". For our main problem, i=C

		We iterate through each item of the array, and we check whether we can choose a particular item (if there is enough capacity). 
		If we can, then we choose that item and recursively compute the total for the rest of the knapsack. 

		We keep track of the maximum possible value out of all such totals, and we store this in the memo array, and return it
		
*/

/* Function to recursively solve the problem using dynamic programming
	Arguments:
		1. int leftWeight: Keeps track of the remaining weight in the knapsack
		2. int n: Total number of items available
		3. vector<int>& v: Array (vector) storing value of each item
		4. vector<int>& w: Array (vector) storing weight of each item		
		5. vector<int>& memo: Array (vector) which helps in dynamic programming

*/	
int solveKnapsack(int leftWeight, int n, vector<int>& v, vector<int>& w, vector<int>& memo){

	if(memo[leftWeight]!= -1) {
		// This means that we have already obtained the maximum value for the given "leftWeight", hence we return it directly 
		// instead of computing it again
		return memo[leftWeight];
	}

	int currentMax=0; // Variable to keep track of the maximum possible value in the current recursion

	for(int i=0;i<n;i++){
		// Iterating through the items, and checking whether a certain item can be chosen 
		// If it can, it is then added to the knapsack and then recursion is carried out for the rest of the knapscck

		if (leftWeight>w[i]) currentMax = max(currentMax, solveKnapsack(leftWeight-w[i],n,v,w,memo)+v[i]);
	}

	// Finally, the maximum value is stored in the memo array, and returned as well
	memo[leftWeight] = currentMax;

	return currentMax;
}


int main()
{
	int C; // Capacity of the knapsack
	cout<<"Enter the capacity of the knapsack: ";
	cin>>C;

	int n; // Number of items 
	cout<<"Enter the number of items: ";
	cin>>n;

	vector<int> v; // Array to store value of each item
	cout<<"Enter the value of each item: ";
	for(int i=0;i<n;i++) {
		int a; 
		cin>>a;
		v.push_back(a);
	}

	vector<int> w; // Array to store weight of each item
	cout<<"Enter the weight of each item: ";
	for(int i=0;i<n;i++) {
		int a; 
		cin>>a;
		w.push_back(a);
	}

	vector<int> memo(C+1,-1); // Memo array which helps in dynamic programming -> it is pre-filled with -1 for convenience

	int maxValue = solveKnapsack(C,n,v,w,memo);

	cout<<"Maximum value is: "<<maxValue<<endl;

	return 0;
}