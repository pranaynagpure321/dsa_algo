class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int d = a | b;
        int cnt =0;
        for(int i =0 ;i <32 ; ++i)
        {
            int mask = 1<<i;
           // cout<< " b mask "<<(b&mask) << " d mask "<< (d & mask) << endl;
            if((c & mask)  and  !(d & mask))
            cnt++;

            else if( !(c & mask))
            {
                if( (a & mask))
                cnt++;

                if( (b & mask))
                cnt++;
            }
             
        }


        return cnt;
    }
};
