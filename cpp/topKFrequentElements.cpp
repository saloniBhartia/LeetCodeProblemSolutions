vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        
        unordered_map<int, int> occ;
        
        for (int i =0; i < nums.size(); i++) {
            occ[nums[i]]++;
        }
        
        auto itr = occ.begin();
        while(itr != occ.end()) {
            min_heap.push({itr->second, itr->first});
            ++itr;
            
            if (k < min_heap.size()) {
                min_heap.pop();
            }
        }
        
        vector<int> result(k);
        while (!min_heap.empty()) {
            pair<int, int> element = min_heap.top();
            min_heap.pop();
            result[--k] = element.second;
        }
        
        return result;
    }