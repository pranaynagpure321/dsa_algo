class Solution {
public:
    
    string checkEmail(string email)
    {
        string  ans ="";
        
        for(int i=0 ;i< email.length() ;i++)
        {
            if(email[i] == '+' || email[i] == '@') break;
            if(!(email[i] == '.'))
            {
                ans += email[i];
            }
        }
        
        int pos = email.find('@');
        
        ans += email.substr(pos);
        
        return ans;
        
    }
    int numUniqueEmails(vector<string>& emails) {
        
        set<string> set;
        for(int i = 0; i< emails.size() ; i++)
        {
            string email = checkEmail(emails[i]);
            
            set.insert(email);
            
        }
        
        
        return set.size();
    }
};
