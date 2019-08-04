#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> br[65];
int r[65];
int p[65];
bool v[65];
int cnt = 0;
bool change;
int limit = 10;


void print2(int N){
    cout <<p[1];
    for(int i = 2; i <= N; i++){
        cout << ' ' << p[i];
    }
    cout << endl;
}

void print(int N){
    for(int i = 1; i <= N; i++){
        cout << r[i] << ' ';
    }
    cout << endl;
}

void dfs(int i){
    if(v[i]) return;

    v[i] = true;
    cnt++;
    for(auto& j: br[i]){
        if(!v[j]) {
            r[j] = max(r[j], r[i]+1);
            dfs(j);
        }
    }
}

void dfs2(int i, int d){
    if(d > limit){
        return;
    }
    for(auto& j: br[i]){
        if(r[j] <= r[i]+1){
            r[j] = r[i]+1;
            dfs2(j,d+1);
        }
    }
}

void dfs3(int i){
    for(auto& j: br[i]){
        if(r[j] == r[i]+1){
            dfs3(j);
            p[j] = i;
        } 
    }
}

int main(){
    int T;
    cin >> T;
    for(int cur = 1; cur <= T; cur++){
        int N,M;
        cin >> N >> M;

        memset(r,0,sizeof(r));
        memset(p,0,sizeof(p));
        memset(v,0,sizeof(v));
        for(int i = 0; i < N; i++){
            br[i].clear();
        }

        for(int i = 0; i < M; i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(a != c){ 
                br[c].insert(a); 
                r[a] = max(r[c]+1,r[a]);
            }
            if(b != c){
                br[c].insert(b); 
                r[b] = max(r[c]+1,r[b]);
            }
        }
        //iprint(N);
        vector<int> z;
        cnt = 0;
        for(int i = 1; i <= N; i++){
            if(r[i] == 0){
                z.push_back(i);
            }
        }
        //cout << z.size() << endl;


        for(auto& i: z){
            dfs(i);
        }
        cout << "Case #" << cur << ": ";;
        if(cnt < N){
            cout << "Impossible\n";
            continue;
        } 
        for(int k = 1; k < z.size(); k++){
            r[z[k]] = r[z[0]]+1;
            br[z[0]].insert(z[k]);
        }
        //cout << "count " << cnt << "\tN " << N<< endl;
        int ccc=0;
        do{
            //cout << "change " << change <<  endl;
 
            change = false;
            for(auto& i: z){
                dfs2(i,0);
            }
            ccc++;
        } while(change&& ccc<10);
            
        dfs3(z[0]);
        ccc = 0;
        for(int i = 1; i <= N; i++){
            if(p[i] == 0){
                ccc++;
            }
            if(ccc >= 2){
                break;
            } 
        }
        if(ccc >= 2) cout << "Impossible\n";
        else print2(N);
    }
}
