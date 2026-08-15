class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<string,int>>>m;
    
    void set(string k, string v, int t) {
        m[k].push_back({v,t});
    }
    
    string get(string k, int t) {
        if(!m.count(k)) return "";
        auto it =m.find(k);
        int l=0;
        int r=it->second.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(it->second[m].second>t){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        if(r>=0) return it->second[r].first;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */