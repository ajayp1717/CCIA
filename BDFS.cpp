#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Depth First Search (DFS)
void dfs(vector<vector<int>> & graph,int start, vector<bool> &vis){
    vis[start]=1;
    cout<<start<<" ";
    
    for(int i=0;i<graph[start].size();i++){
        int neighbor=graph[start][i];
        if(vis[neighbor]!=1){
            dfs(graph,neighbor,vis);
        }
    }
}

// Breadth First Search (BFS)
void bfs(vector<vector<int>> &graph,int start, vector<bool> &vis){
    queue<int> q;
    vis[start]=1;
    q.push(start);
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int i=0;i<graph[node].size();i++){
            int neighbor=graph[node][i];
            if(vis[neighbor]!=1){
                vis[neighbor]=1;
                q.push(neighbor);
            }
        }
    } 
}

int main(){

    int n=7;
    vector<vector<int>>graph(n);
    vector<bool> vis(n,0);

    graph[0]={1,2};
    graph[1]={0,3,4};
    graph[2]={0,5};
    graph[3]={1};
    graph[4]={1,5};
    graph[5]={2,4,6};
    graph[6]={5};

    int start=0;
    int choice;
    
    while(true){
        
        cout<<"\nEnter choice of traversal to be performed: \n1.DFS\n2.BFS\n3.Exit\n";
        cin>>choice;
        
        switch(choice){
            
            case 1:
                cout<<"DFS traversal: ";
                vis.assign(n,0);
                dfs(graph,start,vis);
                cout<<endl;
                break;
                
            case 2:
                cout<<"BFS traversal: ";
                vis.assign(n,0);
                bfs(graph,start,vis);
                cout<<endl;
                break;
                
            default:
                cout<<"Enter Correct Choice!"<<endl;
                return 0;
        }
    }
}

