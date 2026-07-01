class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        if (v.size() == 1) {
            return 0;
        }

        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int i=0;
        int j=1;
        int k=0;
        while(j<v.size()){
            if(v[i][0]<=v[j][0]  && v[j][1]<=v[i][1]){
                i=j;
                // j++;
                k++;
            }
            else if(v[i][0]<=v[j][0] && v[j][0]<v[i][1] && v[j][1]>v[i][1]){
                // j++;
                k++;
            }
            else{
                i=j;
            }
            j++;
        }
        return k;

        // sort(i.begin(), i.end());
        // int k=0;
        // auto it=i.begin();
        // int j=0;
        // while(it!=--i.end()){
        //     auto at=it;
        //     // it++;
        //     // i++;
        //     if(*it==*(++at)){
        //         j++;
        //         i.erase(at);
        //         //it++;
        //     }
        //     else{
        //         at=it;
        //         it++;
        //         auto kt=it;
        //         kt++;
        //         if(kt!=i.end()){
        //         if((*at)[1]>(*it)[0] && (*at)[1]<=(*it)[1] ){
        //             if((*it)[1]>(*kt)[0] && (*it)[1]<=(*kt)[1]){
        //             i.erase(it);
        //             j++;
        //             }
        //             else if((*at)[0]==(*it)[1]){
        //                 i.erase(at);
        //                 j++;
        //             }
        //         }
        //         // else{
        //         //     it++;
        //         // }
        //         }
        //     }
        // }
        // return j;
    }
};