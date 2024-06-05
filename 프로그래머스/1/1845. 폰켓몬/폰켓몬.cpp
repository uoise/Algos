#include <algorithm>
#include <vector>
#include <unordered_set>


using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    for (const int& i : nums) s.insert(i);
    return std::min(nums.size() / 2, s.size());
}