class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int k=0;
        int i=1;
        int l=n[0];
        int x=1;
        while(i<n.size()){
            if(n[i]==l){
                // if(x==-1){
                //     x=i;
                // }
                while(i<n.size() && n[i]==l){
                    k++;
                    i++;
                }
                if(i<n.size()){
                    l=n[i];
                    swap(n[x],n[i]);
                    x++;
                }
            
            }
            else{
                    l=n[i];
                    swap(n[x],n[i]);
                    x++;
                }
            
            i++;
        }
        return (n.size()-k);
    }
};