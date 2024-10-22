//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int a=0;
        vector<int> v(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            if (v[arr[i]-1] != 0){
                a=arr[i];
            }
            v[arr[i]-1]=1;
        }
        for (int i=0;i<arr.size();i++){
            if (v[i]==0){
                return {a,i+1};
            }
        }
        return {a,0};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends