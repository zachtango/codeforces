#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

	int t;
	cin >> t;

	while(t--){

		int n;
		int ops = 0, numTwos = 0;

		cin >> n;
		
		for(int i = 1; i <= n; i++){
			int k;

			cin >> k;

			// factor out 2^i --> i goes in numTwos
			while(k % 2 == 0){
				numTwos += 1;
				k /= 2;
			}
		}

		vector<int> twos;
		
		if(numTwos < n){

			for(int i = (n % 2 == 0) ? n : n - 1; i > 1; i -= 2){
				int k = i;

				int counter = 0;
				while(k % 2 == 0){
					counter += 1;
					k /= 2;
				}

				twos.push_back(counter);
			}

			sort(twos.begin(), twos.end(), greater<int>());

			for(int m : twos){
				numTwos += m;
				ops += 1;
				if(numTwos >= n){
					break;
				}
			}
		}

		if(numTwos < n){
			ops = -1;
		}

		cout << ops << endl;
	}


	return 0;
}