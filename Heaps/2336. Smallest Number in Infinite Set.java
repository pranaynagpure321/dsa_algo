/*2336. Smallest Number in Infinite Set
Medium

223

19

Add to List

Share
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
 

Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5] */


class SmallestInfiniteSet {

       int cur = 1;
       SortedSet<Integer> set ;
        public SmallestInfiniteSet() {
            set = new TreeSet<>();
        }

        public int popSmallest() {
            
            if(!set.isEmpty())
            {
                int ans  = set.first();
                set.remove(ans);
                
                return ans;
            }
            
            return cur++;
        }

        public void addBack(int num) {

            if(num < cur)
                set.add(num);
        }
    }
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */
