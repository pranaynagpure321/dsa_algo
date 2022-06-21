 static int findNoOnesInrow(int[] arr)
    {
        int i =0,j=arr.length-1;
        int mid =(i+j)/2;

        while (i<j)
        {
            mid =(i+j)/2;
            if (arr[mid]==1)
            {
                //traversin left find first zero
                j=mid-1;
            }
            else if (arr[mid]==0)
            {
                //traverse in right find last zero
                i=mid+1;
            }

        }

        if (arr[i]==1)
            return arr.length-i;

        return arr.length-(i+1);
    }
    static int findMaxOnesInrow(int matrix[][])
    {
        int count = Integer.MIN_VALUE;
        for (int[] arr: matrix)
        {
            int temp = findNoOnesInrow(arr);
            if (count<temp)
                count=temp;

        }

        return count;

    }
