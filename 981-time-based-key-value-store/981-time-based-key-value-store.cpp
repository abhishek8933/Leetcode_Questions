class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<string,int>>>map;
    
    string search(vector<pair<string,int>> &v,int stamp){
        int start=0,end=v.size()-1;
        while(end>=start){
            int mid=start-(start-end)/2;
            
            if(v[mid].second>stamp){
                end=mid-1;
            }else if(v[mid].second<stamp){
                start=mid+1;
            }else{
                return v[mid].first;
            }
        }
        
        return end>=0 ?v[end].first:"";
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(map.find(key)==map.end()){
            return "";
        }
        return search(map[key],timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */