#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<pair<int, int>> stack(1, {0,0});
    
    while(!stack.empty()) {
        int rank = stack.back().first;
        int sum = stack.back().second;
        stack.pop_back();
        
        if(rank == numbers.size()) {
            if(sum == target) answer++;
            continue;
        }
        
        stack.push_back({rank+1, sum+numbers[rank]});
        stack.push_back({rank+1, sum-numbers[rank]});
    }
    
    return answer;
}



// // 재귀함수를 이용한 구현
// #include <string>
// #include <vector>

// using namespace std;

// void dfs(vector<int>& numbers, int& target, int rank, int sum, int& answer) {
//     if(rank == numbers.size()) {
//         if(sum == target) answer++;
//         return;
//     }
    
//     dfs(numbers, target, rank+1, sum+numbers[rank], answer);
//     dfs(numbers, target, rank+1, sum-numbers[rank], answer);
// }

// int solution(vector<int> numbers, int target) {
//     int answer = 0;
    
//     dfs(numbers, target, 1, numbers[0], answer);
//     dfs(numbers, target, 1, -numbers[0], answer);
    
//     return answer;
// }