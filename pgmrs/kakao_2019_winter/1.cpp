#include <string>
#include <vector>
#include <stack>

using namespace std;

void Pang(stack<int>& pipe, int& answer) {
    int first = pipe.top();
    pipe.pop();
    if (pipe.empty()) {
        pipe.push(first);
        return;
    }
    int second = pipe.top();
    pipe.pop();

    if (first == second) {
        answer += 2;
    } else {
        pipe.push(second);
        pipe.push(first);
        return;
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();

    stack<int> pipe;
    for (int c : moves) {
        for (int r = 0; r < n; ++r) {
            if (board[r][c - 1] == 0) {
                continue;
            }
            pipe.push(board[r][c - 1]);
            Pang(pipe, answer);
            board[r][c - 1] = 0;
            break;
        }
    }
    return answer;
}

