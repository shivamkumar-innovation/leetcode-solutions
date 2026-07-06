// class Solution {
//     public: 
//     int f(vector<int>&d, int i, int j) {
    
//         int ans = 0;        
//             ans=1+d[j];
        
//         d[i]=max(ans,d[i]);  // 3 7 5 6 8
//         return d[i] ;
//     }
//     int lengthOfLIS(vector<int>& a,int k) {
//         vector<int> d(a.size(),1);
//         int n=a.size();
//         int ans = 1;

//         for (int i = 0; i < n; i++) {

//             for (int j = 0; j<i; j++) {
//                 if(a[i]-a[j]<=k && a[i]>a[j])
//                     ans = max(ans, f(d,i,j));
//             }
//         }

//         return ans;
//     }
// };

class Node{
public:
    int data;
    int le,re;
    Node *left,*right;

    Node(){
        data=0;
        le=re=0;
        left=right=nullptr;
    }
};

class Solution {
public:

    Node *root=nullptr;

    void call(Node *u,int l,int r){

        u->le=l;
        u->re=r;

        if(l==r) return;

        int m=(l+r)/2;

        u->left=new Node();
        u->right=new Node();

        call(u->left,l,m);
        call(u->right,m+1,r);
    }

    int query(Node* root, int l, int r) {
        if (root->le == l && root->re == r)
            return root->data;

        int k = (root->le + root->re) / 2;

        if (r <= k)
            return query(root->left, l, r);

        if (l > k)
            return query(root->right, l, r);

        return max(query(root->left, l, k),query(root->right, k + 1, r));
    }

    void upd(Node* l,int id,int val){
        if(l->re==l->le){
            l->data = max(l->data,val);
            return ;
        }
        int mid=(l->le+l->re)/2;
        if(id<=mid){
            upd(l->left,id,val);
        }
        else{
            upd(l->right,id,val);
        }
        // l->data=max(l->data,val);
        l->data=max(l->left->data,l->right->data);
        return ;
    }
    int lengthOfLIS(vector<int>& a,int k) {
        root=new Node();
        Node* r=root;
        call(r,1,*max_element(a.begin(),a.end()));
        int i=0;
        int ans=1;
        while(i<a.size()){
            if(a[i]!=1){
            r=root;
            int y=max(1,a[i]-k);
            int z=max(1,a[i]-1);
            int p=1+query(r,y,z);
            ans=max(ans,p);
            r=root;
            upd(r,a[i],p);
            }
            else{
                r=root;
            upd(r,a[i],1);
            }
            i++;
        }
        return ans;
    }

};