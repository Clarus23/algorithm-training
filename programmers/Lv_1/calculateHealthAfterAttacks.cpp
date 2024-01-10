#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    const int maxHealth = health;
    int prev = 0;
    for(vector<int> attack : attacks) {
        int time = attack[0]-prev-1;
        prev = attack[0];
        
        int success = time/bandage[0];
        
        health += (success*bandage[2] + time*bandage[1]);
        health = (health > maxHealth) ? maxHealth : health;
        health -= attack[1];
        if(health <= 0) return -1;
    }
    
    return health;
}