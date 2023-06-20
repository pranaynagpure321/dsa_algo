class Solution {
public:

    int candy(vector<int>& ratings) {
    
       int sum = ratings.size();
       vector<int> cadies(sum,1);

       for(int i =0 ;i< ratings.size() ; ++i)
       {
           if(i-1>=0 and cadies[i-1] >= cadies[i] and ratings[i] > ratings[i-1])
           cadies[i] = cadies[i-1] +1;
       }

       for(int i = ratings.size()-1 ; i>=0 ; i--)
       {
           if(i+1 <ratings.size() and cadies[i+1] >= cadies[i] and ratings[i] > ratings[i+1])
           cadies[i] = cadies[i+1]+1;
       }

        sum =0;

        for(int a : cadies)
        sum+=a;

        return sum;
    }
};
