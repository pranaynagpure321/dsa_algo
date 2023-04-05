class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        
        //getting all the indexs of the word1 and word2
        vector<int> v1,v2;
        for(int i =0 ;i< wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1)
            {
                v1.push_back(i);
            }
            else if( wordsDict[i] == word2 )
            {
                v2.push_back(i);
            }
        }

        int dis = wordsDict.size();
        int i =0 ,j=0;
        //min distance between two arrays

        if(word1 != word2)
        while(i< v1.size() && j< v2.size())
        {
            dis = min ( abs(v1[i] - v2[j]) , dis);
            if(v1[i] < v2[j]) i++;
            else j++;
        }

        else
        {
            for(int i =1 ;i< v1.size(); i++ )
            {
                dis = min (abs (v1[i-1] - v1[i]), dis);
            }
        }
        return dis;
    }
};
