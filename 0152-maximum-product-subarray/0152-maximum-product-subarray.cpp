class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct = INT_MIN;
        int preProduct = 1, suffProduct = 1;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            preProduct *= nums[i];
            suffProduct *= nums[n - i - 1];

            maxProduct = max(max(preProduct, suffProduct), maxProduct);

            if(preProduct == 0) preProduct = 1;
            if(suffProduct == 0) suffProduct = 1;

        }

        return maxProduct;
        
    }
};