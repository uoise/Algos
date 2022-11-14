#include <iostream>
#include <string>
using namespace std;

string start = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
string question = "\"재귀함수가 뭔가요?\"\n";
string pre0 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string pre1 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string pre2 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
string suffix = "라고 답변하였지.\n";
string block = "____";

void rcr(uint32_t end, uint32_t cur = 0) {
    if (cur == 0) {
        cout << start << question << pre0 << pre1 << pre2;
        rcr(end, cur + 1);
        cout << suffix;
        return;
    }
    if (cur == end) {
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << question;
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << answer;
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << suffix;
        return;
    }
    else if (cur > 0 && cur != end) {
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << question;
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << pre0;
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << pre1;
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << pre2;
        rcr(end, cur+1);
        for (uint32_t i = 0; i < cur; i++) cout << block;
        cout << suffix;
        return;
    }
    cout << suffix;
    return;
}
void solve() {
    uint32_t n;
    cin >> n;
    rcr(n);
}
int main() { solve(); }