class OrderedStream {   
private:
    vector<string> stream;
    int ptr;

public:
    OrderedStream(int n) {
        // Initialize stream with size n+1 to handle 1-indexing easily
        stream.resize(n + 1, "");
        ptr = 1; // Start looking for the first element
    }
    
    vector<string> insert(int idKey, string value) {
        // 1. Place the value in its designated spot
        stream[idKey] = value;
        
        vector<string> result;
        
        // 2. If the current idKey matches the pointer, 
        // collect all consecutive non-empty strings
        if (idKey == ptr) {
            while (ptr < stream.size() && !stream[ptr].empty()) {
                result.push_back(stream[ptr]);
                ptr++;
            }
        }
        
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */