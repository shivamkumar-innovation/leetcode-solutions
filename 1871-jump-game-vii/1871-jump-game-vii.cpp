class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        int far = 0;

        while (!q.empty()) {
            int j = q.front();
            q.pop();

            int l = max(j + minJump, far);
            int r = min(j + maxJump, n - 1);

            for (int i = l; i <= r; i++) {
                if (s[i] == '0') {
                    if (i == n - 1)
                        return true;
                    q.push(i);
                }
            }

            far = max(far, j + maxJump );
        }

        return n == 1;
    }
};