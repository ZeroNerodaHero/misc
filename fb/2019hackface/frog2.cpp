#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int c = 1; c <= N; c++){
        string s;
        cin >> s;
        int f = 0, e = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == 'B') f++;
            if(s[i] == '.') e++;   
        }
//        cout << f << ' ' << e << endl;
        cout << "Case #" << c << ": ";
        if(e < 1){
            cout << "N" << endl;
        } else if(s.size() < 4){
            if(f == 1) cout << 'Y' << endl;
            else cout << 'N' << endl; 
        } else{
            if(f >= 2) cout << 'Y' << endl;
            else cout << "N" << endl;
        }
    }
}
