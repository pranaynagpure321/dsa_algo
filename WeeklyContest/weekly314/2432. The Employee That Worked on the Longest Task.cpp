class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
          int maxdura = 0, prev = 0;
        int emploID = 0;

        for (auto &v : logs)
        {
            if (v[1] - prev > maxdura)
            {
                maxdura = v[1] - prev;
                emploID = v[0];
            }
            else if (v[1] - prev == maxdura and  emploID > v[0])
            {
                emploID = v[0];
            }

            prev = v[1];
        }

        return emploID;
    }
};
