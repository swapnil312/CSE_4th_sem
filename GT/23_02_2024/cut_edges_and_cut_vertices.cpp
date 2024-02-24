# include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int start, int n, vector<vector<int>> &adj, int vis[])
{
    vis[start] = 1;
    queue<int> q;
    q.push(start);
    vector<int> traversal_print;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        traversal_print.push_back(x);
        for(auto it : adj[x])
        {
            if(vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return traversal_print;
}


int countComponents(int vertices, vector<vector<int>> adjList)
{
    int count_components = 0;
    int vis[vertices] = {0};
    for(int i = 0; i < vertices; i++)
    {
        if(vis[i] != 1)
        {
            vector<int> result = bfsTraversal(i,vertices, adjList, vis);
            count_components++;
        }
    }
    return count_components;
}

int rtrn_cmpnts_edge_rm(int vertices, pair<int, int> p, vector<vector<int>> adjList)
{
    vector<vector<int>> updated_adjList = adjList;
    auto iterator = updated_adjList[p.first].begin();
    for(auto it = updated_adjList[p.first].begin(); it != updated_adjList[p.first].end(); it++)
    {
        if(*it == p.second)
        {
            iterator = it;
        }
    }
    updated_adjList[p.first].erase(iterator);
    auto iterator1= updated_adjList[p.second].begin();
    for(auto it = updated_adjList[p.second].begin(); it != updated_adjList[p.second].end(); it++)
    {
        if(*it == p.first)
        {
            iterator1 = it;
        }
    }
    updated_adjList[p.second].erase(iterator1);
    return countComponents(vertices, updated_adjList);
}
vector<vector<int>> rtrn_adjList_edge_rm(int vertices, pair<int, int> p, vector<vector<int>> adjList)
{
    vector<vector<int>> updated_adjList = adjList;
    auto iterator = updated_adjList[p.first].begin();
    for(auto it = updated_adjList[p.first].begin(); it != updated_adjList[p.first].end(); it++)
    {
        if(*it == p.second)
        {
            iterator = it;
        }
    }
    updated_adjList[p.first].erase(iterator);
    auto iterator1= updated_adjList[p.second].begin();
    for(auto it = updated_adjList[p.second].begin(); it != updated_adjList[p.second].end(); it++)
    {
        if(*it == p.first)
        {
            iterator1 = it;
        }
    }
    updated_adjList[p.second].erase(iterator1);
    return updated_adjList;
}

int rtn_cmpnts_vertex_rm(int vertices, int vertex, vector<vector<int>> adjList)
{
    int count_components = 0;
    int vis[vertices] = {0};
    vis[vertex] = -1;
    for(int i = 0; i < vertices; i++)
    {
        if((vis[i] != 1)&&(vis[i] != -1))
        {
            vector<int> result = bfsTraversal(i,vertices, adjList, vis);
            count_components++;
        }
    }
    return count_components;
}

int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
}

vector<vector<int>> functionx(string str_edge, int vertices, pair<int, int> edge_arr[],vector<vector<int>> adjList)
{
    int swapnil = factorial(str_edge.size());
    vector<vector<int>> v(swapnil);
    vector<vector<int>> updated_adjList = adjList;
    int x = 0;
    string s = str_edge;
    sort(s.begin(), s.end());
    do{

        string str = s;    
        updated_adjList = adjList;
        for(int i = 0; i < str.length(); i++)
        {
            int e = (int)str[i] - 48;
            updated_adjList = rtrn_adjList_edge_rm(vertices, edge_arr[e], updated_adjList);
            if(countComponents(vertices, updated_adjList) > 1)
            {
                v[x].emplace_back(e);
                break;
            }
            v[x].emplace_back(e);
        }
        x++;
    }
    while(next_permutation(s.begin(), s.end()));
    return v;
}

int main()
{
    int vertices, edges;
    string str_edge = "";
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;
    cout<<"Note: Vertices and edges follow 0 based indexing...."<<endl;
    vector<vector<int>> adjList;
    pair<int, int> edges_arr[edges];
    for(int i = 0; i < vertices; i++)
    {
        adjList.push_back({});
    }
    for(int i = 0; i < edges; i++)
    {
        int x,y;
        cout<<"Enter vertices associated with edge "<<i<<": ";
        cin>>x>>y;
        adjList[x].push_back(y);
        edges_arr[i] = {x,y};
        adjList[y].push_back(x);
        str_edge = str_edge+(to_string(i));
    }
    
    int components_when_edge_removed[edges];
    vector<int> cut_edges;
    for(int i = 0; i < edges; i++)
    {
        components_when_edge_removed[i] = rtrn_cmpnts_edge_rm(vertices, edges_arr[i], adjList);
        if(components_when_edge_removed[i] > 1)
        {
            cut_edges.emplace_back(i);
        }
    }
    if(cut_edges.size() == 0)
    {
        cout<<"No singular cut edges..."<<endl;
        vector<vector<int>> vect = functionx(str_edge, vertices, edges_arr, adjList);
        auto temp_it = vect.begin();
        int min = (*temp_it).size();
        cout<<"We have to cut a minimum of "<<min<<" edges of the grpah..."<<endl;
        cout<<"Possible cut sequences are..."<<endl;
        set<set<int>> st;
        for(vector<vector<int>>::iterator it = vect.begin(); it != vect.end(); it++)
        {
            if((*it).size() == min) 
            {
                set<int> st1;
                for(int z = 0; z < min; z++) st1.insert((*it)[z]);
                st.insert(st1);
            }
            
        }
        for(auto it : st)
        {
            for(auto it1: it)
            {
                cout<<it1<<" ";
            }
            cout<<endl;
        }
        
        
    }
    else
    {
        cout<<"No of singular cut edges are "<<cut_edges.size()<<endl;
        cout<<"Cut edge(s) are ..."<<endl;
        for(auto it : cut_edges)
        {
            cout<<"Edge: "<<it<<endl;
        }
    }
    int components_when_vertex_removed[vertices];
    vector<int> cut_vertices;
    for(int i = 0; i < vertices; i++)
    {
        components_when_vertex_removed[i] = rtn_cmpnts_vertex_rm(vertices, i, adjList);
        if(components_when_vertex_removed[i] > 1)
        {
            cut_vertices.emplace_back(i);
        }
    }
    if(cut_vertices.size() == 0)
    {
        cout<<"No cut vertices..."<<endl;
    }
    else
    {
        cout<<"No of cut vertices are "<<cut_vertices.size()<<endl;
        cout<<"Cut vertice(s) are ..."<<endl;
        for(auto it : cut_vertices)
        {
            cout<<"Vertex: "<<it<<endl;
        }
    }
    
    return 0;
}