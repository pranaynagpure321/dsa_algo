class Solution {
    /* solution from lee215  Use two stack s1 and s2.
Similar to "Next Greater Element"
s1 stores the index of elements
that have not found their first greater element.

s2 stores the index of elements
that have found their first greater element,
have not found their second greater element.

For each a = A[i] in A
We first compare the a with the tail elements in s2,
pop all element smaller than a,
because a is their second greater element.

Then we compare the a with the tail elements in s1,
move all elements smaller than a to the tail of s2,
because a is their first greater element.

third stack is used for elements to swich stack to s2

We repeatly do this for all A[i] and finally return the result.


Complexity
All A[i] is pushed in s1 and s2 at most once.
All A[i] is pushed in s1 and s2 at most once.

Time O(n)
Space O(n)*/
    
    
    public int[] secondGreaterElement(int[] nums) {
     
        Stack<Integer> s1 = new Stack<>() , s2 = new Stack<>(), tmp= new Stack<>();
        int[] res = new  int[nums.length];
        Arrays.fill(res,-1);
        for (int i = 0; i < nums.length; i++) {

            while (!s2.isEmpty() && nums[s2.peek()] < nums[i] )
                res[s2.pop()] = nums[i];

            while (!s1.isEmpty() && nums[s1.peek()] < nums[i])
                tmp.push(s1.pop());

            while (!tmp.isEmpty())
                s2.push(tmp.pop());

            s1.push(i);
        }


        return res;
    }
}
