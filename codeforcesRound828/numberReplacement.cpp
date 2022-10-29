#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main(){
    /*
    keep the indices of elements that are the same in a set  
    */


    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        unordered_map<int, vector<int>> nums;
        int n;
        string s;

        cin >> n;

        for(int j = 0; j < n; j++){
            int num;
            cin >> num;

            nums[num].push_back(j);
        }

        cin >> s;

        bool flag = true;
        for(auto const& p : nums){
            char c = s[p.second[0]];
            for(int i = 0; i < p.second.size(); i++){
                if(c != s[p.second[i]]){
                    flag = false;
                    break;
                }
            }

            if(!flag)
                break;
        }

        if(flag){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }

    }
    
    

    return 0;
}



