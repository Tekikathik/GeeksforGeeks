//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int carry=-1;
        for (int i=str.size()-1;i>=0;i--){
            if (carry==-1){
                if (str[i] <='5'){
                    str[i]='0';
                    carry=0;
                }
                else {
                    str[i]='0';
                    carry=1;
                }
            }
            else if (carry!=0){
                carry+=str[i]-'0';
                // cout << carry%10+'0' << endl;
                // break;
                char ch=carry%10+'0';
                str[i]=ch;
                carry/=10;
                
            }
            else if (carry==0) break;
        }
        if (carry != 0){
            auto it = str.insert(str.begin(), '1');
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends