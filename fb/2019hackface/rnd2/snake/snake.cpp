#include <iostream>
#include <queue>
#define INF 0x6f6f6f6f
using namespace std;

struct S{
    int x, a, b;
    bool ok;
    bool operator< (const S& o) const{
        return a < o.a;
    }
    S(){}
    S(int x,int a, int b):x(x), a(a), b(b) {}
};

S l[50];
int N, H;
int a, b, res;

void print()
{
    cout << N << " N/H " << H << endl;
    for (int i = 0; i<N; ++i) cout << l[i].ok << ' ' << l[i].a << ' ' << l[i].b << ' ' << l[i].x << endl;
    cout << endl;
}
void sweepline(int k)
{
    int ans = 0, ans1 = 0;
    //cout << "swep " << k << endl;
    int x = l[k].x;
    for(int i=k+1; i<N; ++i){
        if(l[i].a<l[k].b) {
            l[i].ok = true;
            if(b<l[i].b) b=l[i].b;
            //cout << ans << " " << l[i].a<< "<"  << l[k].b << endl;

            //left
            if (l[i].x > x) {
                ans = max(ans, l[k].b - l[i].a);
            }
            if (l[i].x < x) {
                ans1 = max(ans1, l[k].b - l[i].a);
            }
        } 
    }

    ans += ans1;
    if (ans > 0 && res > ans) res = ans;
    //cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> N >> H;
        res = INF;
        for (int i=0; i<N; ++i) {
            cin >> l[i].x >> l[i].a >>l[i].b;
            if (l[i].a == 0) {
                l[i].ok = true;
                if (l[i].b==H) res = -1;
            } else l[i].ok = false;
        }

        if (res == -1) {
            cout << "Case #" << i << ": -1\n";
            continue;
        }
        sort(l, l+N);
        //print();

        a=0; b = 0;
        for(int i = 0; i < N; i++){
            if(l[i].a<=b&&l[i].ok) {
                if(b<l[i].b) b=l[i].b;
                sweepline(i);
            }
        }

        //cout << "b is " << b << endl;
        if(b!=H||res == INF) {
            cout << "Case #" << i << ": 0\n";
        } else{
            cout << "Case #" << i << ": " << res << endl;
        }
    }
}
