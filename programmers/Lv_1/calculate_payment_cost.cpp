using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long cost = (long long)price * (count * (count+1) / 2);
    answer = (money >= cost) ? 0 : (cost - money);

    return answer;
}