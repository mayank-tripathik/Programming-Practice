#include<bits/stdc++.h>
using namespace std;
typedef list<int> G;

void breadth_first_search(vector<G> &graph, int start_vertex){
    int nodes=graph.size()-1;
    vector<bool> visited(nodes+1,false);
    vector<int> parent(nodes+1,-1);
    queue<int> myqueue;
    myqueue.push(start_vertex);
    visited[start_vertex]=true;
    while(!myqueue.empty()){
        int u=myqueue.front();
        myqueue.pop();
        cout<<u<<endl;
        for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
            int v=(*itr);
            if(!visited[v]){
                visited[v]=true;
                parent[v]=u;
                myqueue.push(v);
            }
                
        }
    }
    cout<<"Parent array:\n";
    for(int i=1;i<=nodes;i++)
        cout<<parent[i]<<" ";
}

int main(){
    int nodes,edges,start_vertex;
    cin>>nodes>>edges;
    vector<G> graph(nodes+1);
    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>start_vertex;
    cout<<"Vertex are visited in following order:\n";
    breadth_first_search(graph,start_vertex);
}
