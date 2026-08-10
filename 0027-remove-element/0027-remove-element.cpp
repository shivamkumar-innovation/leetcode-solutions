class Solution {
public:
    int removeElement(vector<int>& n, int v) {
        int k = 0;
        int i = 0;
        int x;
        while (i < n.size()) {
            if (n[i] == v) {
                x = i;
                k++;
                break;
            }
            i++;
        }
        i++;
        while (i < n.size()) {
            if (n[i] != v) {
                swap(n[x], n[i]);
                x++;
            }
            else{
                k++;
            }
            i++;
        }
        return (n.size() - k);
    }
};