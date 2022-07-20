#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool balanced(queue<char> q) {
  stack<char> s;

  while (!q.empty())
  {
    char c = q.front();
    if (c == ']')
    {
      if (!s.empty() && s.top() == '[')
      {
        s.pop();
      }
      else
      {
        return false;
      }
    }
    else if (c == '[')
    {
      s.push(c);
    }

    q.pop();
  }

  return s.empty();
}

int main() {
    string s = "[cs225]";
    queue<char> q;
    for(int i = 0; i < s.size(); i++){
      q.push(s[i]);
    }

    cout << (balanced(q) ? "It is balanced" : "It is not balanced") << endl;
    return 0;
}