#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Helper(const string& p);
string Reverse(const string& s);
bool isBalance(const string& s);
bool isCorrect(const string& s);


string solution(string p) {
    string answer = "";
	answer = Helper(p);
    return answer;
}

string Helper(const string& p) {
    if (p.empty()) {
        return "";
    }
    string u = "";
    string v = "";
    for (int i = 2; i <= p.length(); i += 2) {
        if (isBalance(p.substr(0, i))) {
            u = p.substr(0, i);
            v = p.substr(i, p.length() - u.length());
            break;
        }
    }
    if (isCorrect(u)) {
        return u + Helper(v);
    }
    return "(" + Helper(v) + ")" + Reverse(u.substr(1, u.length() - 2));
}

string Reverse(const string& s) {
    string reversed_str = "";
    for (char c : s) {
        if (c == '(') {
            reversed_str += ")";
        } else {
            reversed_str += "(";
        }
    }
    return reversed_str;
}

bool isBalance(const string& s) {
    int par_count = 0;
	for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            par_count++;
        } else {
            par_count--;
        }
    }
    return par_count == 0;
}

bool isCorrect(const string& s) {
   	int num_open = 0;
    for (char c : s) {
        if (c == ')') {
           	if (num_open == 0) {
                return false;
            }
            num_open--;
        } else {
            num_open++;
        }
    }
    return num_open == 0;
}