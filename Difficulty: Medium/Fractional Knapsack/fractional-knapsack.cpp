//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b){
         double r1=(double)a.value/(double)a.weight;
         double r2=(double)b.value/(double)b.weight;
         return r1>r2;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        double final=0;
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++){
            if (arr[i].weight <=w){
                w-=arr[i].weight;
                final+=(double)arr[i].value;
            }
            else{
                final +=((arr[i].value*1.0)/(arr[i].weight*1.0))*w;
                break;
            }
        }
        return final;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends