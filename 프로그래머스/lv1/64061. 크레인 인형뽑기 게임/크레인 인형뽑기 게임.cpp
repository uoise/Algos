#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  stack<int> stk;
  int answer = 0, siz = board.size();

  for (auto& mov : moves) {
    mov -= 1;
    for (int i = 0; i < siz; i++) {
      if (board[i][mov]) {
        if (!stk.empty() && board[i][mov] == stk.top()) {
          stk.pop();
          answer += 2;
        } else {
          stk.push(board[i][mov]);
        }
        board[i][mov] = 0;
        break;
      }
    }
  }
  return answer;
}