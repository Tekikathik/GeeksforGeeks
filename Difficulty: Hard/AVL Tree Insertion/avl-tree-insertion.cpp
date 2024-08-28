//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    int height(Node * node){
        if (node==NULL) return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        return 1+max(lh,rh);
    }
    int getbalance_factor(Node* node){
        if (node==NULL) return 0;
        return height(node->left)-height(node->right);
    }
    Node * leftR(Node * node){
        Node * y=node->right;
        Node * t=y->left;
        y->left=node;
        node->right=t;
        return y;
    }
    Node * rightR(Node * node){
        Node * x=node->left;
        Node * t=x->right;
        x->right=node;
        node->left=t;
        return x;
    }
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if (node ==NULL){
            Node * newnode=new Node(data);
            return newnode;
        }
        else if (data > node->data){
            node->right=insertToAVL(node->right,data);
        }
        else if (data < node->data){
            node->left=insertToAVL(node->left,data);
        }
        
        int balancefactor=getbalance_factor(node);
        
        if (balancefactor > 1 && data <node->left->data){
            return rightR(node);
        }
        if (balancefactor < -1 && data >node->right->data){
            return leftR(node);
        }
        if (balancefactor > 1 && data > node->left->data){
            node->left=leftR(node->left);
            return rightR(node);
        }
        if (balancefactor < -1 && data < node->right->data){
            node->right=rightR(node->right);
            return leftR(node);
        }
        return node;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends