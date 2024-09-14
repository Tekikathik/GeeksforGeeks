//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> v,vr;
        for (int i=0;i<arr.size();i++){
            if (arr[i]>=0) v.push_back(arr[i]);
            if (arr[i]<0) vr.push_back(arr[i]);
        }
        int k=0,j=0,i=0;
        while(i<v.size() && j<vr.size()){
            if (k%2==0) arr[k++]=v[i++];
            else arr[k++]=vr[j++];
        }
        while (i<v.size()){
            arr[k++]=v[i++];
        }
        while (j<vr.size()){
            arr[k++]=vr[j++];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends