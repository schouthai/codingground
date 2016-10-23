#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;


int coinChange(int val, vector<int>& coins);



int testCoinChange()
{
   vector<int> coins = {7, 2, 3 , 6};
   int val = 13;
   
   int minCoins = coinChange(val, coins);
   
   cout << "val = " << val << " minCoins = " << minCoins << endl;

    return 0;
}

template<class FwdIterCont>
void print(FwdIterCont& cont, string prefix="") {

    if(!prefix.empty())
        cout << prefix << ": ";
    copy(cont.begin(), cont.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int coinChange(int val, vector<int>& coins) {
    

    vector<int> minCoins(val+1, numeric_limits<int>::max() - 1);
    vector<int> cc(val+1, -1);
    
    print(minCoins, "minCoins");
    print(cc, "using Coins");
    
    minCoins[0] = 0;
    
    for(size_t coinIdx = 0; coinIdx < coins.size(); coinIdx++) {
        for(int num = 1; num <= val; num++) {
        cout << "coin = " << coins[coinIdx] << " num = " << num;
            if(coins[coinIdx] <= num) {
                minCoins[num] = min( minCoins[num], 1 + minCoins[num - coins[coinIdx]] );            
                cout << " minCoins[" << num << "] = " << minCoins[num];
            }
            cout << endl;
        }
        
        print(minCoins, "minCoins after loop");
    }

    print(minCoins, "minCoins");
    print(cc, "using Coins");
    
    return 0;    
}
