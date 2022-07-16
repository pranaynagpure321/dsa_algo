class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        
        vector<int> vec(fruits.size(),0);
        
        
        for(int i =0 ;i< fruits.size() ;i++)
        {
            int index = fruits[i]-1;
            
            vec[index] +=1;
            //cout<<i<<" "<<index <<" " <<vec[index]<<endl;
            
            
        }
        int max=-1;
        int max2= -1;
        for(int i =0 ;i< vec.size() ;i++)
        {
            //cout<<vec[i]<<endl;
            if(vec[i] > max)
            {
                max2 = max;
                max = vec[i];
            }
            //cout<<max<<" "<<max2<<endl;
            
            else if(vec[i]<max && vec[i]>max2)
                max2 = vec[i];
            
        }
        
        return max+ max2;
    }
};
