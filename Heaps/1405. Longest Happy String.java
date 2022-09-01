class Solution {
    int i =0;
    public Pair<Character,Integer> app(char ch , int count , StringBuilder s, boolean isFirst)
    {
        if(count >2)
        {
             if(!isFirst || ( s.length()>0 &&  s.charAt(s.length()-1) == ch) ) 
            {
                s.append(ch);
                i+=1;
                return new Pair<>(ch,count-1);
            }
            s.append(ch+""+ch);
            i+=2;
            return new Pair<>(ch,count-2);
        }
        else if(count  == 2)
        {
            s.append(ch);i+=1;return new Pair<>(ch,1);
        }
        else if(count == 1)
        {
             s.append(ch ); i++;
        }
        return null;
    }
    
    public String longestDiverseString(int a, int b, int c) {
         
        
        int len = a + b + c;
        StringBuilder s = new StringBuilder();
        i = 0;
        
        String lastappend ="";
        PriorityQueue<Pair<Character,Integer>> q  = new PriorityQueue<Pair<Character,Integer>>( (m, n) -> n.getValue() - m.getValue() ) ; 
        
        if(a>0)
        q.add(new Pair<>('a', a));
        
        if(b>0)
        q.add(new Pair<>('b', b));
        
        if(c>0)
        q.add(new Pair<>('c', c));
        
        while(i < len)
        {
            if(q.size()  < 2) break;    
            var first = q.poll();
            var sec = q.poll();
        
           first = app( first.getKey() , first.getValue(),s, true);
           sec =  app( sec.getKey() , sec.getValue(),s,false);
        
            if(first != null)
                q.add(first);
            
            if(sec != null)
                q.add(sec);
        }
        
        //to handle case where one char remain in q and can be added to string example s = "aaccb"  q = "c=>2" so s would be aaccbcc
        var first = q.poll();
        
        if( first != null )
        {
            if(s.length() == 0)
            {
                  if(first.getValue()> 1)
                    return   s.append(first.getKey() + "" + first.getKey()).toString();
                  
                  return    s.append(first.getKey()).toString();
            }
             
            
            else if(s.charAt(s.length()-1) != first.getKey() )
            {
                if(first.getValue()>1)
                 s.append(first.getKey() +""+first.getKey());
                
                else
                    s.append(first.getKey());
            }
        }
        
 //too complex solution
        
        
        return s.toString();
    }
}
