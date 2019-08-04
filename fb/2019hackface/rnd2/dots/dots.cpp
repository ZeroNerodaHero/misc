#include <iostream>
#include <queue>
#define MAXN 800000
using namespace std;

int T, N, H, V;
long long  ax,bx,cx,dx,ay,by,cy,dy;
int x[MAXN];
int y[MAXN];
int mx, my;

int main()
{
    cin >>T;
    for (int i = 1; i<= T; ++i) {
        cin >> N >> H >> V;
        cin >> x[0] >> x[1] >> ax >> bx >> cx >> dx; 
        cin >> y[0] >> y[1] >> ay >> by >> cy >> dy; 
        mx = max(x[0],x[1]);
        my = max(y[0],y[1]);    

        if(H + V < N){
            cout <<"Case #" << i << ": "<< "-1" << endl;
            continue;
        }

        for(int j = 2; j < N; j++){
            x[j]  = ((ax * x[j-2] + bx * x[j-1] + cx)%dx)+1;
            y[j]  = ((ay * y[j-2] + by * y[j-1] + cy)%dy)+1;
            mx = max(mx,x[j]);
            my = max(my,y[j]);    
        }
        //for(int j = 0; j < N; j++){ cout << "x\t" << x[j] << " y\t" << y[j] << endl; }

        cout << "Case #" << i << ": " << min(mx,my) << endl;
    }
    
}
