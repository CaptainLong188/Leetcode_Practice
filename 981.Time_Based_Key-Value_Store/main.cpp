#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class TimeMap1{
    public:

        map<string, vector<int>> KeyTimestamps;
        map<pair<string, int>, string> hashMap;

        TimeMap1(){}

        void set(string key, string value, int timestamp){

            if(KeyTimestamps.count(key) == 0){
                KeyTimestamps[key] = {timestamp};
            }else{
                KeyTimestamps[key].push_back(timestamp);
            }

            hashMap[make_pair(key, timestamp)] = value;
        }

        string get(string key, int timestamp){
            
            // Verify if key is in the vector keys

            if(KeyTimestamps.count(key) > 0){

                vector<int>& timestamps = KeyTimestamps[key];

                // Return max element that is less or equal to timestamp

                int n = timestamps.size();
                int l = -1, r = n;      

                while(r > l + 1){
                    
                    int m = l + (r - l)/2;

                    if(timestamps[m] > timestamp){
                        r = m;
                    }else{
                        l = m;
                    }
                }
                
                if(l == -1) return "";

                int value = timestamps[l]; 
                return hashMap[make_pair(key, value)];

            }else{
                return ""; // Key not found in keys vector
            }
        }
};

class TimeMap2{
    
    public:

        unordered_map<string, vector<pair<string, int>>> hashMap;

        TimeMap2(){

        }

        void set(string key, string value, int timestamp){
            
            if(hashMap.count(key) == 0){
                hashMap[key] = {make_pair(value, timestamp)};
            }else{
                hashMap[key].push_back(make_pair(value, timestamp));
            }
        }

        string get(string key, int timestamp){

            if(hashMap.count(key) == 0){
                return "";
            }

            int l = -1, r = hashMap[key].size();

            while(r > l + 1){

                int m = l + (r - l)/2;

                if(hashMap[key][m].second > timestamp){
                    r = m;
                }else{
                    l = m;
                }

            }

            if (l == -1) return "";
            else return hashMap[key][l].first;
        }
};

int main(){
    
    TimeMap1* obj1 = new TimeMap1();
    obj1->set("foo", "bar", 1);
    cout << obj1->get("foo", 1) << '\n';
    cout << obj1->get("foo", 3) << '\n';
    obj1->set("foo", "bar1", 4);
    cout << obj1->get("foo", 4) << '\n';
    cout << obj1->get("foo", 5) << '\n';

    TimeMap2* obj2 = new TimeMap2();
    obj2->set("foo", "bar", 1);
    cout << obj2->get("foo", 1) << '\n';
    cout << obj2->get("foo", 3) << '\n';
    obj2->set("foo", "bar1", 4);
    cout << obj2->get("foo", 4) << '\n';
    cout << obj2->get("foo", 5) << '\n';    

    return 0;
}
