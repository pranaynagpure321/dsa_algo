class Solution {
public:

    void dfs(vector<vector<int>>& rooms,vector<bool> &vis , int idx,int cnt)
    {
        vis[idx] = true;
        auto &room = rooms[idx];
        for(int k : room)
        {
            if(!vis[k])  
            { 
                dfs(rooms,vis, k, cnt+1);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> vis(rooms.size()+1, false);
        dfs(rooms,vis,0,0);

        for(int i =0 ;i<rooms.size();i++)
        if(!vis[i]) return false;

        return true;
    }
};
