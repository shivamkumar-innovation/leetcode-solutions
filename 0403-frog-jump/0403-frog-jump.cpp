class Solution { // 10 13 15 
public:
    unordered_map<int,int> m;
    bool b = 0;
    void f(vector<int>& a, unordered_map<int, unordered_set<int>> &v,int k, int c,int l) {
        if(b) return ;
        if(k<=0) return ;
        if (k+c == l || c + k+ 1 == l || c+k-1==l){
            b=true;
            return;
        }
        if (m.find(c+k) !=m.end() && !v[(m.find(c+k))->second].count(k)){
            v[(m.find(c+k))->second].insert(k);
            f(a,v,k,c+k,l);
        }
        if(m.find(c+k+1) !=m.end() && !v[(m.find(c+k+1))->second].count(k+1)){
            v[(m.find(c+k+1))->second].insert(k+1);
             f(a,v,k+1,c+k+1,l);
        }
        if(k-1>0 && m.find(c+k-1) !=m.end() && !v[(m.find(c+k-1))->second].count(k-1)){
            v[(m.find(c+k-1))->second].insert(k-1);
            f(a,v,k-1,c+k-1,l);
        }
    }

    bool canCross(vector<int>& a) {
        int i = 0;
        if(a[1]!=1){
            return b;
        }
        if(a.size()==2){
            return 1;
        }
        unordered_map<int, unordered_set<int>> v;
        v[0].insert(0);
        v[1].insert(1);
        while (i < a.size()) {
            m[a[i]]=i;
            i++;
        }
        f(a,v,1,1,a[a.size()-1]);
        return b;
    }
};