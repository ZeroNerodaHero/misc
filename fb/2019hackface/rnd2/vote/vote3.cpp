#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define MAXN 1000005
#define MOD 1000000007

using namespace std;

int N,K;
set<int> s;
int f[MAXN];
int pre[MAXN];
string str;

struct inter{
    int l, r;
    inter(int l, int r): l(l),r(r) {}
};
vector<inter> v;

inline int sum(int i, int j){
//    cout << j << " pre " << i << endl;
    return pre[j] - pre[i];
}

long long dp[MAXN];
int power(int n){
    if(dp[n] > 0) return dp[n];
    dp[n] = power(n/2);
    dp[n] *= dp[n];
    if(n&1) dp[n] *= 2;    
    dp[n] %= MOD;
//    cout << n << ' ' << dp[n] << endl;
    return dp[n];
}

int main()
{
    int T;
    cin >>T;
    dp[0] = 1;
    dp[1] = 2;
    for (int t = 1; t<= T; ++t) {
        vector<int> res;
        cin >> N >> K >> str;
//        cout << N << ' ' << K << endl << str << endl;
        for(int i = 0; i <= N; i++) f[i] = 0;
        s.clear();

        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'B'){
 //               s.insert(i+1);
                pre[i+1] = pre[i]+1;
            } else{
                pre[i+1] = pre[i];
            }
        }


//for(int i = 0; i <= N; i++) cout << pre[i]<<' ';cout << endl;
        
        for(int m = K+1; m <= N; m++){
            for(int i = N; i >= m; i--){
                int b = sum(i-m, i);
//                cout << "M " << m << " i " << i << " B " << b << endl;
                int diff = 2*b-m-K;
                if(diff > 0){
                    v.push_back(inter(i-m+1,i));
#if 0
                    diff = (diff+1)/2;
                
                    for(int j = 0; j < diff; j++){
                        set<int>::iterator it;
                        it = s.lower_bound(i-m+1);                       
                        int n = *it;
                    cout << "Diff\t" << diff << "\tN\t" << n << endl;
                        
                        del(n); 
                        s.erase(it);
                        res.push_back(n);
                    }
#endif
                }               
            }
        }

        //for(auto& i: v){ cout <<"interval " << i.l << ' ' << i.r << endl; }

        cout << v.size() << endl;
        int c = 0;
#if 0
        for(auto& i: res){
            //cout << i << ' ';
            c += power(i);
            if(c >= MOD) c -= MOD;
        }
        cout << endl;
#endif 
        cout << "Case #" << t << ": " << c << endl;;
    }

}
