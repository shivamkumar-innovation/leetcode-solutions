class SmallestInfiniteSet {
public:
set<int>s;
    SmallestInfiniteSet() {
        int i=1;
        while(i<=1000){
            s.insert(i);
            i++;
        }
    }
    
    int popSmallest() {
        auto it=s.begin();
        int k=(*it);
        s.erase(it);
        return k;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */