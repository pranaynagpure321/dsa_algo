class LFUCache {
public:
   map<int, list<int>> freq_mp; // all the frequency elemts are grouped together
   map<int, pair<int,int>> keyval;  // to store key-><value,frequency>
   map<int, list<int>:: iterator> pos;  // this is used to store the at whihc position in list presnt in frequncny_map the key is present;
   int cap, minfreq=0; // capacity and minfreq present at moment;

    LFUCache(int capacity) {
        this->cap = capacity;
        minfreq =0;
    }  
    int get(int key) {
         
        if(keyval.find(key) == keyval.end()) return -1;

        int val = keyval[key].first;
        int freq = keyval[key].second;keyval[key].second++;

        auto position_itr = pos[key];

        freq_mp[freq].erase(position_itr);
        freq_mp[freq+1].push_front(key);

        pos[key] = freq_mp[freq+1].begin();

        if(freq_mp[minfreq].size() == 0) minfreq++;

        return val;

    }
    
    void put(int key, int value) {
        
       // cout<<"key "<<key<<" v=> "<<value<<endl;
       
       if(keyval.find(key) != keyval.end())
       {
           keyval[key].first = value;
           int freq = keyval[key].second; keyval[key].second++;
           
           auto position_itr = pos[key];

           freq_mp[freq].erase(position_itr);
           freq_mp[freq+1].push_front(key);
           pos[key] = freq_mp[freq+1].begin();
           if(freq_mp[minfreq].size() == 0) minfreq++;
       }
       else
       {
            if(keyval.size() == cap)
            {
                int k = freq_mp[minfreq].back(); freq_mp[minfreq].pop_back();
                keyval.erase(k);
                pos.erase(k);
            }

            keyval[key]={value,1};
            minfreq = 1;
            freq_mp[1].push_front(key);
            pos[key] = freq_mp[1].begin();

       }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
