# include <bits/stdc++.h>
using namespace std;

vector < string > groups;

string interval(string A, int start, int end) {
    string temp = "";
    for (int i = start; i <= end; i++) {
        temp = temp + A[i];
    }
    return temp;
}

void checkAndInsert(string A, vector < int > cuts) {
    cout<<"Printing cuts vector"<<endl;
    int from = 0, to = 0;
    cuts.push_back(A.length() -1 );
    for (int i = 0; i < 4; i++) printf("cuts[%d] = %d\n", i, cuts[i]);
    cout<<"Will now print the strings"<<endl;
    string answer = "";
    for (int i = 0; i < 4; i++) {
        to = cuts[i];
        printf("from = %d to = %d\n", from, to);
        string cur = interval(A, from, to);
        cout<<cur<<endl;
        if (cur.length() >= 4 || cur.length() == 0) return;
        if (cur[0] == '0' && cur.length() > 1) return;
        answer = answer + cur + '.';
        from = to + 1;
    }
    cout<<endl;
    groups.push_back(answer.substr(0, answer.length() -1));
    return;
}

void recurse(string A, int left, int index, vector < int > &cuts) {
    if (index == (A.length()))
        return;
    if (left == 0) {
        checkAndInsert(A, cuts);
        return;
    }
    recurse(A, left, index + 1, cuts);
    cuts.push_back(index);
    recurse(A, left - 1, index + 1, cuts);
    cuts.pop_back();
    return;
}

vector<string> restoreIpAddresses(string A) {
    groups.clear();
    vector < int > cuts;
    cuts.clear();
    recurse(A, 3, 0, cuts);
    sort(groups.begin(), groups.end());
    return groups;
}

int main(void) {
  string input = "0100100";
  vector < string > answer = restoreIpAddresses(input);
  sort(answer.begin(), answer.end());
  printf("length = %d\n", answer.size());
  for (int i = 0; i < answer.size(); i++) {
    cout<<answer[i]<<endl;
  }
}
