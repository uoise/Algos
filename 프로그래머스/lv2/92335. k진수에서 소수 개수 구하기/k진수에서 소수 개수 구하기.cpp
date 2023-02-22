#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_over(long long x, int y) {
  while (x) {
    if (x % 10 >= y) return false;
    if (x % 10 == 0) return false;
    x /= 10;
  }
  return true;
}

bool is_pr(long long x, int k, const vector<bool>& v) {
  if (!is_over(x, k)) return false;
  if (x < 2) return false;
  long long tmp = round(sqrt(x));
  for (int i = 2; i <= tmp; i++)
    if ((v[i]) && (x % i == 0)) return false;
  return true;
}

int solution(int n, int k) {
  int answer = 0;
  // 지수 변환

  vector<int> val;
  long long rnum = 0;
  int clc = k, mem = n;
  while (n > clc) clc *= k;
  clc /= k;
  while (clc >= k) {
    int cur = (mem / clc);
    val.push_back(cur);
    rnum *= 10;
    rnum += cur;
    mem -= cur * clc;
    clc /= k;
  }
  rnum *= 10;
  rnum += mem;
  val.push_back(mem);

  // 소수 배열
  long long prm = round(sqrt(rnum));
  vector<bool> isp(prm + 1, true);
  isp[0] = isp[1] = 0;
  for (int i = 2; i <= prm; i++)
    if (isp[i])
      for (int t = 2; i * t <= prm; t++) isp[i * t] = 0;

  // 소수 찾기
  long long tmp = 0;
  for (int i = 0; i < val.size(); i++) {
    if (val[i]) {
      tmp *= 10;
      tmp += val[i];
    } else {
      if (is_pr(tmp, k, isp)) ++answer;
      tmp = 0;
    }
  }
  if (is_pr(tmp, k, isp)) ++answer;
  return answer;
}