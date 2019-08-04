#include <iostream>
using namespace std;
string s;

bool value(const bool v, const int i){
    bool ret;
    if(s[i] == '1'){
        ret = 1;
    } else if(s[i] == '0'){
        ret = 0;
    } else if(s[i] == 'X'){
        ret = !v;
    } else{
        ret = v;
    }
    return ret;
}

bool exc(bool a, char b, bool c){
    if(b == '|'){
        return a||c;
    } 
    if(b == '&'){
        return a&&c;
    }
    if(a){
        return !c;
    } else{
        return c;
    }
}

bool dfs(const bool v, int& i){
    bool a, b; 
    char op;
    if(s[i] == '('){
        a = dfs(v,++i);
    } else{
        a = value(v,i);
        i++;
    }
    op = s[i++];
    if(s[i] == '('){
        b = dfs(v,++i); 
    }else{
        b = value(v,i);
        i++;
    }
    cout << "end " << s[i] << endl;
    i++;
    return exc(a,op,b);
}

int main(){
    int N;
    cin >> N;
    for(int c = 1; c <= N; c++){
        cin >> s;
        int v1, v2;
        if(s[0] == '('){
            int i = 1;
            v1 = dfs(true,i);
            i = 1;
            v2 = dfs(false,i);
        } else{
            v1 = value(true,0);
            v2 = value(false,0);
        }
        cout << "Case #" << c << ": ";
        if(v1 == v2) cout << '0' << endl;
        else cout << '1' << endl; 
    }

    
}
