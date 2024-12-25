//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<int> r;
        vector<int> c;
        for (int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if (mat[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        int k=0;
        while (k<r.size()){
        for (int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if (i==r[k] || j==c[k]){
                    mat[i][j]=0;
                    // k++;
                }
            }
        }
        k++;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends