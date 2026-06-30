class Solution {
public:
    bool canJump(vector<int>& a) {
        //if( !count(a.begin(), a.end(), 0)) return 1;
        // if(a[0]==0) return 0;
        int i=0;
        stack<int>s;
        while(i<a.size()-1){
            if(a[i]==0){
                if(s.empty()) return 0;
                //int j=i-1;
            while(i<a.size()-1 && a[i]==0){
                i++;
            }
            //int j=i
            while(!s.empty() && a[s.top()]<i-s.top()){
                // return 0;
                s.pop();
            }
            if(s.empty()) return 0;
            }
            else if(!s.empty() && a[s.top()]<=a[i]){
                while(!s.empty() && a[s.top()]<=a[i]){
                    s.pop();
                }
                s.push(i);
                i++;
            }
            else{
                s.push(i);
                i++;
            }
            // i++;
        }
        return 1;
    }
};