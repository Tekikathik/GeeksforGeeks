//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        
        int can1=0,can2=0,count1=0,count2=0;
        for (int i=0;i<arr.size();i++){
            if (can1==arr[i]) count1++;
            else if (can2==arr[i]) count2++;
            else if (count1 ==0){
                can1=arr[i];
                count1++;
            }
            else if (count2==0){
                can2=arr[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int vote1=0,vote2=0;
        for (auto x:arr){
            if (can1==x) vote1++;
            if (can2==x) vote2++;
        }
        int n=arr.size();
        vector<int> v;
        if (vote1>(n/3)) v.push_back(can1);
        if (vote2 > (n/3)) v.push_back(can2);
        if (v.size()==0) v.push_back(-1);
        return v;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends