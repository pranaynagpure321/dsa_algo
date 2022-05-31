class Solution {
    public int longestValidParentheses(String s) {
        
        Stack<Character> stack = new Stack<>();
        Stack<Integer> index= new Stack<>();
        index.push(-1);
        int len =0;

        for (int i =0;i<s.length();i++)
        {
            if(s.charAt(i)=='(')
            {
                stack.push('(');
                index.push(i);
            }

           else
            {
                if (!stack.isEmpty() && stack.peek()=='(') {
                    stack.pop();
                    index.pop();
                   // len= Math.max(len,i-index.peek());
                    int last_index=  index.peek();

                    if (i - last_index > len)
                        len = i-last_index;
                }
                else  
                {
                    index.push(i);
                }
            }

        }
        return len;
    }
    
}
