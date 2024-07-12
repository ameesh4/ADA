#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Search {
    public:
    void bfs(vector<vector<int> >& adjList, int startNode,
            vector<bool>& visited)
    {
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            cout << currentNode << " ";
            for (int neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void addEdge(vector<vector<int> >& adjList, int u, int v)
    {
        adjList[u].push_back(v);
    }
};

long long getTime(std::function<void()> f){
    auto start = clock();
    f();
    auto end = clock();
    long double duration = end - start;
    return (duration/CLOCKS_PER_SEC) * 1000000000;
}

int main()
{
    int vertices = 100;
    Search search;

    vector<vector<int> > adjList(vertices);

    for (int i = 0; i < vertices; i++) {
        search.addEdge(adjList, i, (i + 1) % vertices);
    }

    vector<bool> visited(vertices, false);

    auto bfs = [&](){
        search.bfs(adjList, 0, visited);
        cout << endl;
    };
    

    cout << "BFS: " << endl;
    cout << getTime(bfs);
    cout << "ns";

    return 0;
}