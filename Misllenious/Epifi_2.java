  public static void kDistictSubarray(int[] arr,int k)
    {
        HashMap<Integer, Integer> h1 = new HashMap<>();
        int start = 0;
        int size= arr.length;
        int end =0;
        int i =0 ,j=0;
        
        while (j<arr.length)
        {

            if (h1.containsKey(arr[j]))
            {
                h1.put(arr[j], h1.get(arr[j])+1);
                j++;
            }
            else
            {    h1.put(arr[j], 1); j++;}

            while (k==h1.size())
            {
                int winsize = j-i-1;

                if (winsize<size)
                {
                    start= i;
                    end = j-1;
                    size= winsize;
                }

                if (h1.get(arr[i])==1)
                    h1.remove(arr[i]);
                else
                    h1.put(arr[i], h1.get(arr[i])-1);

                i++;

            }

        }


        for (int m = start; m<=end ;m++)
            System.out.print(arr[m] + " " );

    }

    public static void main(String[] args) {
        int [] arr = {1,1,2,2,2,3,3,4};
        int k =3;

         kDistictSubarray(arr,k);
         //Kdistict(arr,k);

        //1,2,3,4

    }
