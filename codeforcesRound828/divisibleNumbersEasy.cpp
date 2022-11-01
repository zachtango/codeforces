#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

void solve(ll a, ll b, ll c, ll d){
    ll ab = a * b;
    // cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    // edge case
    if(ab == 1){
        cout << (a + 1) << ' ' << (b + 1) << endl;
        return;
    }

    unordered_map<ll, int> factors;

    // prime factorize ab
    for(ll i = 2; i * i <= ab; i++){
        while(ab % i == 0){
            factors[i] += 1;

            ab /= i;
        }
    }

    if(ab > 2){
        factors[ab] += 1;
    }

    // cout << "Factorization\n";
    // for(auto factor : factors){
    //     cout << factor.first << ' ' << factor.second << endl;
    // }

    // check every x
    for(ll x = a + 1; x <= c; x++){
        unordered_map<ll, int> factorsLeft = factors;

        ll xCopy = x;
        // prime factorize x
        for(ll i = 2; i * i <= xCopy; i++){
            while(xCopy % i == 0){
                factorsLeft[i] -= 1;

                xCopy /= i;
            }
        }
            
        if(xCopy > 2){
            factorsLeft[xCopy] -= 1;
        }

        // cout << x << " factorization:\n";
        // for(auto factor : factorsLeft){
        //     cout << factor.first << ' ' << factor.second << endl;
        // }

        ll product = 1;

        for(auto factor : factorsLeft){
            int count = factor.second;

            while(count > 0){
                product *= factor.first;
                count -= 1;
            }
        }

        ll y = ( (b + product) / product ) * product;
        if(y <= d){
            cout << x << ' ' << y << endl;
            return;
        }
    }

    cout << "-1 -1\n";
}

int main(){
    /*
        x * y
        a * b

        prime factorize ab, counting each prime

        for x in (a, c]:
            prime factorize x
            subtract the factors from the prime factorization of ab

            number left that you need is the product of the prime factors left

            ( (b + product) / product ) * product will get you a number close to b that's divisible by numberLeft
                bc you multiplied by product

            check if this expression is <= d, if it is, it's valid

            and you don't have to look anymore
    
    */

    int t;
    cin >> t;

    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        solve(a, b, c, d);
    }

    return 0;
}
