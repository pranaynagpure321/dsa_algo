class Solution {
public:
    
    vector<int> countLR(string s, char c)
    {
        vector<int> v;
        if(c== 'L')
        {
            for(int i =0 ; i< s.length() ; i++)
            {
                if(s[i] == 'L')
                v.push_back(i);
            }

            return v;
        }

         for(int i =0 ; i< s.length() ; i++)
            {
                if(s[i] == 'R')
                v.push_back(i);
            }

            return v;
    }
   
    bool canChange(string start, string target) {
        
       if(start.length() != target.length()) return false;
    
    vector<int> Ls = countLR(start,'L');
    vector<int> Rs = countLR(start,'R');

    vector<int> LTar = countLR(target,'L');
    vector<int> RTar = countLR(target,'R');
    if(Ls.size() != LTar.size() || Rs.size() != RTar.size()) return false;
    //move Ls
    for(int i =0 ;i< Ls.size() ; i++)
    {
        if(LTar[i] == Ls[i] ) continue;
        if(LTar[i] < Ls[i])
        {
            //check there is no R in between
            int a = LTar[i], b = Ls[i];

            if(Rs.size() != 0)
            for(int j =a; j<= b ; j++){
               if(start[j] == 'R') return false; }
             
            start[a] = 'L';
            start[b] = '_';

        }
        else
        return false;
    }
   // cout<<start<<endl;
    //move Rs
    for(int i =Rs.size()-1 ; i >=0 ; i-- )
    {
        if(RTar[i] == Rs[i] ) continue;
        if(RTar[i] > Rs[i])
        {
            //check there is no R in between
            int a = RTar[i], b = Rs[i];

            if(Ls.size() != 0)
            for(int j =b; j<= a ; j++){
               if(start[j] == 'L') return false; }
             
            start[a] = 'R';
            start[b] = '_';
              
        }
        else
        return false;
    }

    ///cout<<start << " " << target<<endl;
    if(start != target) return false;

    //cout<<start<<endl;

    return true;
    }
};
