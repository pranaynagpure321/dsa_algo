class Solution {
    public List<Integer> partitionLabels(String s) {
        
        int [] char_counts = new int[26];

        for(int i =0 ;i<s.length();i++)
        char_counts[s.charAt(i)-'a'] = i;   // calculate last index of each character

        int j =0,anchor =0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for(int i =0 ;i<s.length();i++) 
        {
            j = Math.max(j, char_counts[s.charAt(i)-'a']); // get the last index of current char

            if(i ==j )                  //check if last index match with current index
            {
                ans.add(i - anchor + 1);             // if matched then calculate the length of partation
                anchor = i+1;                       //updtae anchor
            }
        }

        return ans;

    }
}

class Solution {
public:
    vector<int> res;

    bool isValid(string s ,int i , int j)
    {
        int a =0, b=0;

        for(int  k =i ; k<=j && k<s.size() ;k++)
        {
            a = a | (1<<(s[k]-'a'));
        }

         for(int  k =j+1 ;  k<s.size() ;k++)
        {
            if(a & (1<<(s[k]-'a'))) return false;
        }

        return true;
    }
    vector<int> partitionLabels(string s) {
        
        int i =0;

        for(int j =0 ;j< s.size(); j++)
        {
            if(isValid(s,i,j))
            {
                res.push_back(j+1 -i);
                i = j+1;
            }
        }

        return res;
    }
};
