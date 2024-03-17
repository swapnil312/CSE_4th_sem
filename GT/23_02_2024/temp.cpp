#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

vector<int> bfsTraversal(int start, const vector<vector<int>> &adj, vector<bool> &vis) {
    vis[start] = true;
    queue<int> q;
    q.push(start);
    vector<int> traversal_print;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        traversal_print.push_back(x);
        for (auto it : adj[x]) {
            if (!vis[it]) {
                vis[it] = true;
                q.push(it);
            }
        }
    }
    return traversal_print;
}

int countComponents(const vector<vector<int>> &adjList) {
    int count_components = 0;
    int vertices = adjList.size();
    vector<bool> vis(vertices, false);
    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            bfsTraversal(i, adjList, vis);
            count_components++;
        }
    }
    return count_components;
}

int rtrn_cmpnts_edge_rm(int vertices, pair<int, int> p, vector<vector<int>> &adjList) {
    adjList[p.first].erase(remove(adjList[p.first].begin(), adjList[p.first].end(), p.second), adjList[p.first].end());
    adjList[p.second].erase(remove(adjList[p.second].begin(), adjList[p.second].end(), p.first), adjList[p.second].end());
    return countComponents(adjList);
}

vector<vector<int>> rtrn_adjList_edge_rm(const pair<int, int> &p, const vector<vector<int>> &adjList) {
    vector<vector<int>> updated_adjList = adjList;
    updated_adjList[p.first].erase(remove(updated_adjList[p.first].begin(), updated_adjList[p.first].end(), p.second), updated_adjList[p.first].end());
    updated_adjList[p.second].erase(remove(updated_adjList[p.second].begin(), updated_adjList[p.second].end(), p.first), updated_adjList[p.second].end());
    return updated_adjList;
}

int rtn_cmpnts_vertex_rm(int vertex, const vector<vector<int>> &adjList) {
    int count_components = 0;
    int vertices = adjList.size();
    vector<bool> vis(vertices, false);
    vis[vertex] = true;
    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            bfsTraversal(i, adjList, vis);
            count_components++;
        }
    }
    return count_components;
}

int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

vector<vector<int>> functionx(string str_edge, int vertices, const pair<int, int> edge_arr[], const vector<vector<int>> &adjList) {
    int swapnil = factorial(str_edge.size());
    vector<vector<int>> v(swapnil);
    vector<vector<int>> updated_adjList = adjList;
    int x = 0;
    string s = str_edge;
    sort(s.begin(), s.end());
    do {
        string str = s;
        updated_adjList = adjList;
        for (int i = 0; i < str.length(); i++) {
            int e = str[i] - '0';
            updated_adjList = rtrn_adjList_edge_rm(edge_arr[e], updated_adjList);
            if (countComponents(updated_adjList) > 1) {
                v[x].emplace_back(e);
                break;
            }
            v[x].emplace_back(e);
        }
        x++;
    } while (next_permutation(s.begin(), s.end()));
    return v;
}

vector<vector<int>> functiony(string str_vertices, const vector<vector<int>> &adjList) {
    int swapnil = factorial(str_vertices.size());
    vector<vector<int>> v(swapnil);
    int vertices = adjList.size();
    int x = 0;
    string s = str_vertices;
    sort(s.begin(), s.end());
    do {
        string str = s;
        vector<bool> updated_vis(vertices, false);
        for (int i = 0; i < str.length(); i++) {
            int e = str[i] - '0';
            updated_vis[e] = true;
            for (int z = 0; z < vertices; z++) {
                updated_vis[z] = false;
            }
            for (int h = 0; h <= i; h++) updated_vis[str[h] - '0'] = true;
            int count_components = 0;
            for (int j = 0; j < vertices; j++) {
                if (!updated_vis[j]) {
                    bfsTraversal(j, adjList, updated_vis);
                    count_components++;
                }
            }
            if (count_components > 1) {
                v[x].emplace_back(e);
                break;
            }
            v[x].emplace_back(e);
        }
        x++;
    } while (next_permutation(s.begin(), s.end()));
    return v;
}

int main() {
    int vertices, edges;
    string str_edge = "";
    string str_vertex = "";
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Note: Vertices and edges follow 0 based indexing...." << endl;
    vector<vector<int>> adjList(vertices);
    pair<int, int> edges_arr[edges];
    for (int i = 0; i < vertices; i++) {
        str_vertex += to_string(i);
    }
    for (int i = 0; i < edges; i++) {
        int x, y;
        cout << "Enter vertices associated with edge " << i << ": ";
        cin >> x >> y;
        adjList[x].push_back(y);
        edges_arr[i] = {x, y};
        adjList[y].push_back(x);
        str_edge += to_string(i);
    }

    int components_when_edge_removed[edges];
    vector<int> cut_edges;
    for (int i = 0; i < edges; i++) {
        components_when_edge_removed[i] = rtrn_cmpnts_edge_rm(vertices, edges_arr[i], adjList);
        if (components_when_edge_removed[i] > 1) {
            cut_edges.emplace_back(i);
        }
    }

    if (cut_edges.empty()) {
        vector<vector<int>> vect = functionx(str_edge, vertices, edges_arr, adjList);
        auto temp_it = min_element(vect.begin(), vect.end(), [](const vector<int> &a, const vector<int> &b) { return a.size() < b.size(); });
        int min = (*temp_it).size();

        set<set<int>> st;
        for (auto it = vect.begin(); it != vect.end(); it++) {
            if ((*it).size() == min) {
                set<int> st1;
                for (int z = 0; z < min; z++) st1.insert((*it)[z]);
                st.insert(st1);
            }
        }
        cout << "We have to cut a minimum of " << min << " edges of the graph to make it disconnected." << endl;
        cout << "Possible cut sequences of edges are..." << endl;
        for (auto it : st) {
            for (auto it1 : it) {
                cout << "Edge: " << it1 << "    ";
            }
            cout << endl;
        }
        cout << "So edge connectivity = " << min << endl;

    } else {
        cout << "Number of cut edges are " << cut_edges.size() << endl;
        cout << "Cut edge(s) are ..." << endl;
        for (auto it : cut_edges) {
            cout << "Edge: " << it << endl;
        }
        cout << "So edge connectivity = 1" << endl;
    }

    int components_when_vertex_removed[vertices];
    vector<int> cut_vertices;
    for (int i = 0; i < vertices; i++) {
        components_when_vertex_removed[i] = rtn_cmpnts_vertex_rm(i, adjList);
        if (components_when_vertex_removed[i] > 1) {
            cut_vertices.emplace_back(i);
        }
    }

    if (cut_vertices.empty()) {
        vector<vector<int>> vect = functiony(str_vertex, adjList);
        auto temp_it = min_element(vect.begin(), vect.end(), [](const vector<int> &a, const vector<int> &b) { return a.size() < b.size(); });
        int min = (*temp_it).size();
        set<set<int>> st;
        for (auto it = vect.begin(); it != vect.end(); it++) {
            if ((*it).size() == min) {
                set<int> st1;
                for (int z = 0; z < min; z++) st1.insert((*it)[z]);
                st.insert(st1);
            }
        }
        cout << "We have to cut a minimum of " << min << " vertices of the graph to make it disconnected." << endl;
        cout << "Possible cut sequences of vertices are..." << endl;
        for (auto it : st) {
            for (auto it1 : it) {
                cout << "Vertex: " << it1 << "   ";
            }
            cout << endl;
        }
        cout << "So vertex connectivity = " << min << endl;
    } else {
        cout << "Number of cut vertices are " << cut_vertices.size() << endl;
        cout << "Cut vertice(s) are ..." << endl;
        for (auto it : cut_vertices) {
            cout << "Vertex: " << it << endl;
        }
        cout << "So vertex connectivity = 1" << endl;
    }

    return 0;
}
