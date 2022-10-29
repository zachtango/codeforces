#include <iostream>
#include <numeric>

using namespace std;


int main(){
    /*

    */
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, q;
        cin >> n >> q;

        int evens = 0;
        int odds = 0;

        long long A[n];
        for(int j = 0; j < n; j++){
            cin >> A[j];
            if(A[j] % 2 == 0){
                evens += 1;
            } else{
                odds += 1;
            }
        }
        
        long long sum = 0;
        sum = accumulate(A, A + n, sum);

        for(int j = 0; j < q; j++){
            int type, x;

            cin >> type >> x;

            int r = x % 2;

            if(type == 1){
                sum += (x * odds);
            } else{
                sum += (x * evens);
            }

            if(r == 1){ // add odd numbers to odd numbers --> odd numbers become even
                if(type == 1){
                    evens += odds;
                    odds = 0;
                } else{
                    odds += evens;
                    evens = 0;
                }
            }

            cout << sum << endl;
        }
    }


    return 0;
}
