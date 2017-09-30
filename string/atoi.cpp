# include <bits/stdc++.h>
using namespace std;

int atoi(string s) {
  int counter = 0;
  while (s[counter] == ' ')
    counter++;
  if (s[counter] != '+' && s[counter] != '-' && (s[counter] < 48) && (s[counter] > 57)) {
    return 0;
  }
  int start = counter;
  bool neg = 0;
  if (s[counter] == '+' || s[counter] == '-') {
    start++;
    if (s[counter] == '-') {
      neg = 1;
    }
  }
  string temp = "";
  for (int i = start; i < s.length(); i++) {
    if (s[i] < 48 || s[i] > 57) {
      break;
    }
    temp = temp + s[i];
  }
  cout<<temp<<endl;
  if (temp.length() == 0)
    return 0;
  if (temp.length() >= 11) {
    if (neg) return INT_MIN;
    return INT_MAX;
  }
  long long num = 0, product = 1;
  reverse(temp.begin(), temp.end());
  cout<<temp<<endl;
  for (int i = 0; i < temp.length(); i++) {
    num = num + (product) * (long long)(temp[i] - 48);
    product = (long long)product * 10;
  }
  if (num > INT_MAX) {
    if (neg) return INT_MIN;
    return INT_MAX;
  }
  if (neg)
  return -num;
}

int main(void) {
  string input = "9 2704 01885D 9M 65291S844404U7463";
  cout<<atoi(input);
  return 0;
}
