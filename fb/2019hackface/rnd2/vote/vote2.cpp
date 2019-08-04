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
string str;

void add(int i){
    while(i <= N){
        f[i]++;
        i += i&(-i);
    }
}

void del(int i){
    while(i <= N){
        f[i]--;
        i += i&(-i);
    }
}

int sum(int i){
    int s = 0;
    while(i > 0){
        s += f[i];
        i -= i&(-i);
    }
    return s;
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
        cout << N << ' ' << K << endl << str << endl;
        for(int i = 0; i <= N; i++) f[i] = 0;
        s.clear();

        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'B'){
                s.insert(i+1);
                add(i+1);
            }
        }

        cout << "insert\n";
        //for(int m = K+1; m <= N; m++){
        for(int m = N; m >= K+1; m--){
            for(int i = N; i >= m; i--){
                int b = sum(i)-sum(i-m);
                cout << "M " << m << " i " << i << " B " << b << endl;
                int diff = 2*b-m-K;
                if(diff > 0){
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
                }               
            }
        }
        int c = 0;
        for(auto& i: res){
            //cout << i << ' ';
            c += power(i);
            if(c >= MOD) c -= MOD;
        }
        cout << endl;
        cout << "Case #" << t << ": " << c << endl;;
    }
    

}
