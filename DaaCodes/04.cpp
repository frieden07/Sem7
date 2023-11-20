#include<bits/stdc++.h>
using namespace std;

int main(){
    int capacity;
    cout<< "Enter Maximum weight of box : ";
    cin >> capacity;
    int items;
    cout<< "Enter the number of box : ";
    cin >> items;

    int price[items + 1];
    int wt[items + 1];
    
    price[0] = 0;
    wt[0] = 0;

    cout<< "Enter the profit and weight of box : \n";

    for(int i=1;i<=items;i++){
        cin >> price[i] >> wt[i];
    }

    int dp[items + 1][capacity + 1];
    
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(wt[i] <= j){
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/