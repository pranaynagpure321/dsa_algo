//not my solution 

public String alienOrder(String[] words) {
    Map<Character, Set<Character>> map=new HashMap<Character, Set<Character>>();
    Map<Character, Integer> degree=new HashMap<Character, Integer>();
    String result="";
    if(words==null || words.length==0) return result;
    for(String s: words){
        for(char c: s.toCharArray()){
            degree.put(c,0);
        }
    }
    for(int i=0; i<words.length-1; i++){
        String cur=words[i];
        String next=words[i+1];
        int length=Math.min(cur.length(), next.length());
        for(int j=0; j<length; j++){
            char c1=cur.charAt(j);
            char c2=next.charAt(j);
            if(c1!=c2){
                Set<Character> set=new HashSet<Character>();
                if(map.containsKey(c1)) set=map.get(c1);
                if(!set.contains(c2)){
                    set.add(c2);
                    map.put(c1, set);
                    degree.put(c2, degree.get(c2)+1);
                }
                break;
            }
        }
    }
    Queue<Character> q=new LinkedList<Character>();
    for(char c: degree.keySet()){
        if(degree.get(c)==0) q.add(c);
    }
    while(!q.isEmpty()){
        char c=q.remove();
        result+=c;
        if(map.containsKey(c)){
            for(char c2: map.get(c)){
                degree.put(c2,degree.get(c2)-1);
                if(degree.get(c2)==0) q.add(c2);
            }
        }
    }
    if(result.length()!=degree.size()) return "";
    return result;
}


//my solution
/*class Solution {
    
    static  boolean addchar( HashMap<Character , HashSet<Character>> adj ,String u, String v)
    {
        int i =0,j=0;
         if( u.length() > v.length() && u.indexOf(v) == 0)  //check if first string is larger than second and if second string is present in first than wrong lexiographicall ordering is present return false
        {
            return false;
        }


        while (i< u.length() &&  j < v.length()) // interate over both strings to find where the dont match
        {
            if(u.charAt(i) != v.charAt(j))
                break;
            i++;j++;
        }

       

        if(i<u.length() && j< v.length()) {
            char start = u.charAt(i);
            char end = v.charAt(j);

            if(adj.containsKey(start))
            adj.get(start).add(end);

            else {
                adj.put(start, new HashSet<>());
                adj.get(start).add(end);
            }
        }

        return true;
    }


    public static String alienOrder(String[] words) {

        HashMap<Character , HashSet<Character>> adj = new HashMap<>();  // create adj list 

        for (int i = 0; i < words.length; i++) {

            for (int j = i+1; j < words.length; j++) {

               if( !addchar(adj, words[i], words[j]))
                   return "";
            }

        }


        int[] indeg = new int[26];       //calculate indegree


        for ( var key: adj.keySet()) {

            var set = adj.get(key);
            for(char c : set)
            {
                indeg[c-'a']++;
            }

        }


        Queue<Character> q= new LinkedList<>();

        for (var key : adj.keySet())
        {
            if(indeg[key-'a'] ==0)
                q.add(key);
        }

        StringBuilder topo =new StringBuilder();

        while (!q.isEmpty())                    // do topo sort on graph created
        {
            char c  = q.poll();

           topo.append(c);
           var nodes = adj.get(c);
            if(nodes != null)
            for(var node : nodes)
            {
                indeg[node-'a']--;

                if(indeg[node-'a'] ==0 )
                    q.add(node);
            }
        }

        //count unique chars
        int[] char_counts = new int[26];        //count each char present 
       
        int ans =0;
        for (int i = 0; i < words.length; i++) {

            for (int j = 0; j < words[i].length(); j++) 
                char_counts[words[i].charAt(j)-'a']++;
        }

        String res = topo.toString();

        if(res.length()  < adj.size()) ///check if solution size is less than size of hashmap if yes return null
            return "";

        for (int i = 0; i < 26; i++)
        {
            if(char_counts[i]>0)
                ans++;
            if(char_counts[i]>0 && res.indexOf((char)(i+'a')) == -1)   //append each char whth no  edge in graph
                 res += ((char)(i+'a'));
        }

        //time O(n2*maxWordlength)

        return res;
    }
    
    //input
    /*["abc","ab"]
["wrt","wrf","her","ett","rfgt"]
["wrt","wrf","er","ett","rfgt"]
["rt","wrf","er","ett","rfgt"]
["wrt","wrf","er","ett","rftt"]
["z","x"]
["z","x","z"]
["qb","qts","qs","qa","s"]*/
    
    //op sequnce wise
   /* ""
"twfherg"
"wertfg"
""
"wertf"
"zx"
""
"qbtsa"*/
    
    //better solution
    //https://leetcode.com/problems/alien-dictionary/discuss/70119/Java-AC-solution-using-BFS


}*/
