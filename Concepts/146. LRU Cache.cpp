class LRUCache {
public:

    list<int> q;          // do not use dequq as it invalidates the iteratore after isertion or deletion in middle
    map<int,pair<list<int> :: iterator, int>> mp;                 // map to store key and interator to LRU list key position, and value
    int cap =0; 
    LRUCache(int capacity) {
        this->q = list<int>();
        this->cap = capacity;
        this->mp =  map<int,pair<list<int> :: iterator, int>> ();
    }

    void pushFront(int key)                 //after every insertion push value to front of the queue
    {
        auto it = mp[key].first;           
        q.erase(it);
        q.push_front(key);
        mp[key].first = q.begin();
    }

    int get(int key) {

        auto  it = mp.find(key);                    // get value based on key

        if(it == mp.end()) return -1;

        pushFront(key);

        return mp[key].second;
    }

    void put(int key, int value) {


        auto it = mp.find(key);

        if(it != mp.end())          //update function
        {
            mp[key].second = value;
            pushFront(key);
        }
        else if(it == mp.end())      // if value not in map
        {
            if(q.size() == cap)        // pop if oversized
            {
                mp.erase(q.back());
                mp[key].second = value;
                q.pop_back();
                q.push_front(key);
                mp[key].first = q.begin();
            }
            else
            {
                mp[key].second = value;
                q.push_front(key);
                mp[key].first = q.begin();
            }
        }
    }
};
