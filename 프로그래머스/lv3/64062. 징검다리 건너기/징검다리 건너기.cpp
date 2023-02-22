#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
  int ans = 2e9 + 1, siz = stones.size();
  deque<int> dq;
  for (int i = 0; i < siz; i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();
    while (!dq.empty() && stones[dq.back()] <= stones[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) ans = min(ans, stones[dq.front()]);
  }

  return ans;
}
