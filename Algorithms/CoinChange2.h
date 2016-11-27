#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;


int coinChange(int val, const vector<int>& coins);



int testCoinChange()
{
   vector<int> coins = {2, 3, 5};
   int val = 7;
   
   int minCoins = coinChange(val, coins);
   
   cout << "val = " << val << " minCoins = " << minCoins << endl;

    return 0;
}

template<class ContFwdIter>
void print(ContFwdIter &cont, string prefix="") {
    if(!prefix.empty())
        cout << prefix << ": ";
    
    copy(cont.begin(), cont.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int coinChange(int val, const vector<int>& coins) {
    vector<int> minCoins(val+1, numeric_limits<int>::max());
    
    for(int idx = 1; idx <= val; ++idx) {
        for(auto& coin : coins) {
            if(coin <= idx)
                minCoins[idx] = min( minCoins[idx], 1 + minCoins[idx - coin] );
        }
    }
    
    print(minCoins, "Done");
    return minCoins[val];
}