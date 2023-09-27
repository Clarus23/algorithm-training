#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> cache;
    
    if(!cacheSize) return 5*cities.size();
    
    for(string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if(cache.find(city) != cache.end()) {
            cache[city] = 0;
            answer++;
        } else {
            if(cache.size() >= cacheSize) {
                auto max = cache.begin();
                for(auto it = cache.begin(); it != cache.end(); it++)
                    max = (it->second > max->second) ? it : max;
                cache.erase(max);
            }
            
            cache.insert({city, 0});
            answer += 5;
        }
        for(auto it = cache.begin(); it != cache.end(); it++) it->second++;
    }
    
    return answer;
}