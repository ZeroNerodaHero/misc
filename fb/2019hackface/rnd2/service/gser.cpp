#include <iostream>
#include <queue>

using namespace std;

int T, N, M;
int adj[51][51];
int edge[1000][3];
bool visited[51];
int dist[51];

struct node {
    int id, w;
    node() {}
    node(int id, int w){
        this->id = id;
        this->w = w;
    }
    bool operator < (const node &o) const{
        return w > o.w;
    }
};

bool shortest(int u, int v, int w)
{
 //   cout << "edge " << u << ' ' << v <<' '<< w << endl;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0x1f, sizeof(dist));

    priority_queue<node> q;
    q.push(node(u, 0));
    dist[u] = 0;

    while(!q.empty()) {
        node a = q.top();
        q.pop();
        int x = a.id;
        if(x == v) break;
        if(visited[x]) continue;
        visited[x] = true;
        for (int i = 1; i<=N; ++i) {
            if(adj[x][i]>0 && !visited[i] && dist[i] > dist[x]+adj[x][i]) {
                dist[i] = dist[x]+adj[x][i];
                q.push(node(i, dist[i]));
            }
        }
    }

    //for(int i = 1; i<=N; ++i) cout << dist[i] << ' '; cout << endl;

    return dist[v] == w;
}

int main()
{
    cin >>T;
    for (int i = 1; i<= T; ++i) {
        cin >> N >> M;
        
        memset(adj, 0, sizeof(adj));
        int j;
        for (j = 0; j<M; ++j) {
            int a, b, c;
            cin >> a >> b >> c;
            edge[j][0] = a;
            edge[j][1] = b;
            edge[j][2] = c;
            adj[a][b] = adj[b][a] = c;
        }
        for (j = 0; j<M; ++j) {
            if(!shortest(edge[j][0], edge[j][1], edge[j][2])) break;
        }

 //       cout << j << " == " << M << endl;
        cout << "Case #" << i << ": ";
        if (j < M) {
            cout << "Impossible\n";
        } else {
            cout << M << endl;
            for (j = 0; j<M; ++j) {
                cout << edge[j][0] << ' ' << edge[j][1] << ' ' <<edge[j][2] << endl;
            }
        }
    }
    
}
