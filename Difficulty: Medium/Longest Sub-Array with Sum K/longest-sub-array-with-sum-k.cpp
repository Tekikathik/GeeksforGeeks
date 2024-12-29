//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        mp[arr[0]]=0;
        // cout << arr[0] << " ";
        for (int i=1;i<arr.size();i++){
            // if (arr[i])
            arr[i]+=arr[i-1];
            if (mp.find(arr[i]) == mp.end())
            mp[arr[i]]=i;
            // cout << arr[i] << " ";
        }
        // cout << endl;
        int d=0; 
        for(int i=0;i<arr.size();i++){
            int c=arr[i]-k;
            // cout << c << endl;
            if (c==0) d=max(d,i+1);
            if (mp.find(c) != mp.end()){
                // cout << i <<  " " << mp[c]  << endl;
                d=max(d,i-mp[c]);
            }
        }
        return d;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends