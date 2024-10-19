//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node *head1=NULL, *head2=NULL;
        while (head != NULL){
            if (head1==NULL){
                head1=head;
                head=head->next;
                head1->next=NULL;
            }
            if (head2==NULL){
                head2=head;
                head=head->next;
                head2->next=NULL;
            }
            else {
                Node * temp=head1;
                Node * prev= head2;
                while (temp->next != NULL){
                    temp=temp->next;
                }
                temp->next=head;
                head=head->next;
                temp->next->next=NULL;
                if (head != NULL){
                while (prev->next != NULL){
                    prev=prev->next;
                }
                prev->next=head;
                head=head->next;
                prev->next->next=NULL;
                }
                // head=head->next->next;
            }
        }
        return {head1,head2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends