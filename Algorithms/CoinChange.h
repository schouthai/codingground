#include <iostream>
#include <vector>

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

int coinChange(int val, vector<int>& coins) {
    return 0;    
}
