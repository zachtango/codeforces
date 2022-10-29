#include <iostream>
#include <string>

using namespace std;

int main(){

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        char c;
        string s;
        int n;

        cin >> n >> c >> s;

        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }

        s += s;

        int j = 0;
        int maxTime = 0;
        while(j < s.size()){
            if(s[j] != c){
                j += 1;
                continue;
            }
            
            int k = j;
            while(k < s.size() && s[k] != 'g'){
                k += 1;
            }
            
            if(k == s.size()){
                break;
            }
            
            maxTime = max(maxTime, k - j);
            j = k;
        }

        cout << maxTime << endl;
    }


    return 0;
}

