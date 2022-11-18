class Solution {
public:
    int trailingZeroes(int n) {
        int res =0;
        for(int i = 5 ; i<= n ;i++)
        {
            if(i%5 ==0)
            {   
                int a = i;
                int tmp =0;
                while(a>=5 and a%5 ==0)
                {
                    a /=5; tmp++;
                }

                res += tmp;
                //cout<<"a=> "<<i<<" tmp=> "<<tmp<<endl;
            }

        }
        //time O(N)
        return res;
    }
};
