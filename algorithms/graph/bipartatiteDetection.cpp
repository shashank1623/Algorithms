/*
Problem Statement: WAP to check whether a given graph is BiPartite or Not

To know about BiPartite Graph: https://en.wikipedia.org/wiki/Bipartite_graph



SOLUTION IDEA:
    BiPartite graph is a  graph in which adjacent nodes have a different colour when colored with only 2 colors.
    
    For a tree(Graph with NO CYCLE) it's always possible bcoz we can give diff colors to diff levels of the tree.
    
    Therefore a simple Logic can be if(!cycle()) isBiPartite = true.
    But if it's false then we have to travel the graph again which isn't efficient.
    One key obs. is that when the cycle is off ODD length then, graph is NOT BiPartite.
    Solution lies in simulating the coloring processs and checking whether the next node to us has a same colour (parity).

*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, list<int> > graph;
unordered_set<int> Vis;

void pre(){  // for the case if we have TEST CASES to work on
     graph.clear();
     Vis.clear();
}

void addEdge(int u, int v){ // undirected Edge
     graph[u].push_back(v);
     graph[v].push_back(u);
}

void takeEdges(){
     int e;cin>>e;
     for(int i = 0; i<e; i++){
          int u, v;cin>>u>>v;
          addEdge(u, v);
     }
}

int n;

unordered_map<int, bool> parity;

bool isBipartite_helper(int src, int prnt, bool prti){
    parity[src] = prti;
    Vis.insert(src);
    for(auto nbr: graph[src]){
        if(Vis.find(nbr) == Vis.end()){
            bool chk  = isBipartite_helper(nbr, src, !prti);
            if(!chk) return false;
        }else{
            if(src != prnt and parity[src] == parity[nbr])return false;
        }
    }
    return true;
}

bool isBipartite(){
    bool chk = false;
    for(int i = 0; i<n; i++)
       if(Vis.find(i) == Vis.end())
         chk |= isBipartite_helper(i, -1, 1);
    return chk;
}

int main(){
    int _TC = 1; 
    // Enable for TEST CASES:  
    // cin>>_TC;  
    while(_TC--){
       pre();  // IMPORTANT! to clear the previous inputs.
       cin>>n;
       takeEdges();
       if(isBipartite()){
         cout<<"YES\n";
       }else{
        cout<<"NO\n";
       }
    }
}
