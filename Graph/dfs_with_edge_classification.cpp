#include<bits/stdc++.h>
using namespace std;

vector<int> start;
vector<int> finish;
int counter=0;

void dfs(vector<list<int> > &graph, int u, vector<bool> &visited)
{
    cout<<"visited:"<<u<<endl;
	visited[u]=true;
    counter++;
    start[u]=counter;
	list<int>::iterator itr;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++)
    {
		int v=(*itr);
		if(!visited[v])
        {
            dfs(graph,v,visited);
        }       
	}
    counter++;
    finish[u]=counter;
}

void print_edges(vector<list<int> > &graph){
    int nodes=graph.size()-1;
    list<int>::iterator itr;
    for(int i=1;i<=nodes;i++)
    {
        int u=i;
        for(itr=graph[u].begin();itr!=graph[u].end();itr++)
        {
            int v=(*itr);
            cout<<u<<"--->"<<v<<" edge is a ";
            if(start[u]>start[v]){
                if(finish[u]>finish[v])
                    cout<<"Cross edge\n";
                else
                    cout<<"Back edge\n";
                
            }
            else{
                if(finish[u]>finish[v])
                    cout<<"Tree edge\n";
                else
                    cout<<"Forward edge\n";
                
            }
        }
    }   
}


int main()
{
	int u,v,s,nodes,edges;
	cin>>nodes>>edges;
	vector<list<int> >graph(nodes+1);
    vector<bool> visited(nodes+1,false);
    start.resize(nodes+1);
    finish.resize(nodes+1);
    for(int i=1;i<=edges;i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }
    cin>>s;
    dfs(graph,s,visited);
    print_edges(graph);
    return 0;
}
