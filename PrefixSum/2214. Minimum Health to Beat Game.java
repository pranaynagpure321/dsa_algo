class Solution {
    public long minimumHealth(int[] damage, int armor) {
      
      long sum = 0, ele = 0;
      for(int i =0 ;i< damage.length ;i++)
      {
          sum+= damage[i];
          if(ele < damage[i])
          {
            ele = damage[i];
          }
      }

   //   System.out.println("sum => "+ sum + " ele => "+ele);
      return sum - Math.min(armor,ele) +1;
    }
}
