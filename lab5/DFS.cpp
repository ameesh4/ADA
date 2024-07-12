#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

long long getTime(std::function<void()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

int main()
{
    Graph g;
    for (int i = 0; i < 100; i++)
        g.addEdge(i, i + 1);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    auto dfs = [&](){
        g.DFS(2);
        cout << endl;
    };

    cout << getTime(dfs) << "ns Time taken" << endl;

    return 0;
}