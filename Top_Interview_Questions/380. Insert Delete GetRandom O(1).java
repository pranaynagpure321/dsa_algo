class RandomizedSet {

    ArrayList<Integer> arr   ;
    HashMap<Integer,Integer> mp ;
    Random random = new Random();   
    public RandomizedSet() {
        mp = new HashMap<Integer, Integer>();
        arr  = new ArrayList<Integer>();
    }
    
    public boolean insert(int val) {
        boolean present = mp.containsKey(val);
        if(present) return false;
        arr.add(val);
        mp.put(val, arr.size()-1);  
        return true;
    }
    
    public boolean remove(int val) {

        if(!mp.containsKey(val)) return false;
        if(arr.size()==1 ) {arr.remove(0); mp.remove(val); return true;}

        //swap last element with element we want to remove
        // then remove last element from array as well as map
        int last = arr.get(arr.size()-1);
        int idx = mp.get(val);
         // System.out.println("before removal=> "+Arrays.toString(arr.toArray()));
        arr.set(idx,last);
        arr.remove(arr.size()-1);

        //System.out.println("After removal=> "+Arrays.toString(arr.toArray()));
        mp.remove(val);
        mp.replace(last,idx);  //if element is not presnet in map replace will do nothing hence used
         
        return true;
    }
    
    public int getRandom() {
        return arr.get(random.nextInt(arr.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
