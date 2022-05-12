public class Solution {
	
	 public static int search(int arr[], int key)
    {
        int min =0;
        int max = arr.length-1;

        while (min<= max)
        {
            int mid= (min+max)/2;

            if(arr[mid]==key)
                return mid;

            if(arr[min]<=arr[mid])
            {
                if(key>=arr[min] && key<=arr[mid])
                {
                    max = mid-1;
                }
                else
                {
                    min = mid+1;
                }
            }
            else{
                   if(key>=arr[mid] && key<=arr[max])
                   {
                      min =mid+1;
                    }
                    else
                   {
                      max = mid-1;
                   }
            }
        }

        return -1;

    }
}
