//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int> prefix(arr.size(),0);
        vector<int> suffix(arr.size(),0);
        prefix[0]=arr[0];
        for (int i=1;i<arr.size();i++){
            prefix[i]=arr[i]*prefix[i-1];
        }
        suffix[arr.size()-1]=arr[arr.size()-1];
        for (int i=arr.size()-2;i>=0;i--){
            suffix[i]=arr[i]*suffix[i+1];
        }
        arr[0]=suffix[1];
        for (int i=1;i<arr.size()-1;i++){
            arr[i]=prefix[i-1]*suffix[i+1];
        }
        arr[arr.size()-1]=prefix[arr.size()-2];
        return arr;
    }
};
 

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends