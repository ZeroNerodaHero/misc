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
        cout << "Case #" << c << ": ";
        if(f >= e && e > 0){
            cout << 'Y' << endl; 
        } else{
            cout << 'N' << endl;
        }
    }

    
}
