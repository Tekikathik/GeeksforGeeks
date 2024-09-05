//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int n, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        int sm=arr[0]+k;
        int la=arr[n-1]-k;
        int mi=INT_MAX;
        int ma=INT_MIN;
        for(int i=0;i<n-1;i++){
            mi=min(sm,arr[i+1]-k);
            ma=max(la,arr[i]+k);
            if (mi <0) continue;
            ans=min(ans,ma-mi);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            c.push_back(num);
        if (c.size() == 1) {
            n = c[0];
            getline(cin, input);
            ss.clear();
            ss.str(input);
            while (ss >> num)
                a.push_back(num);
        } else {
            a = c;
            n = a.size();
        }
        // cin >> k;
        // cin >> n;
        // int arr[n];
        // for (int i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }
        Solution ob;
        auto ans = ob.getMinDiff(a, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends