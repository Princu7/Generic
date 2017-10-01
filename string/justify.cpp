# include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &A, int B) {
    int counter = 0, prev = 0;
    vector < string > ans;
    while (counter < A.size()) {
        int tempLen = A[counter].length(), wordsLen = 0, noOfWords = 0, totalSpace = 0;
        int avgSpace = 0, extraSpace = 0;
        bool lastLine = 0;
        string avgSlot = "", extraSlot = "", tempAns = "", lastLineSlot = "";
        while ((counter + 1 < A.size()) && tempLen + A[counter + 1].length() + 1 <= B) {
            tempLen = tempLen + A[++counter].length() + 1;
        }
        //printf("prev = %d and counter = %d\n", prev, counter);
        noOfWords = counter - prev + 1;
        wordsLen = tempLen - (noOfWords -1);
        totalSpace = B - wordsLen;
        if (counter == A.size() - 1) {
          lastLine = 1;
          int lastLineSpace = B - (noOfWords - 1);
          for (int i = 0; i < lastLineSpace; i++) {
            lastLineSlot = lastLineSlot + ' ';
          }
        }
        if (noOfWords > 1) {
          avgSpace = totalSpace / (noOfWords - 1);
          extraSpace = totalSpace % (noOfWords - 1);
        } else {
          avgSpace = totalSpace;
          extraSpace = 0;
        }
        //printf("Words Num = %d wordsLen = %d leftSpace = %d avgSpace = %d extraSpace = %d\n", noOfWords, wordsLen, totalSpace, avgSpace, extraSpace);
        for (int i = 0; i < avgSpace; i++) {
            avgSlot = avgSlot + ' ';
        }
        extraSlot = avgSlot + ' ';
        if (lastLine) {
          for (int i = prev; i <= counter - 1; i++) {
            tempAns = tempAns + A[i] + ' ';
          }
          tempAns = tempAns + A[counter];
          tempAns = tempAns + lastLineSlot;
        } else {
          for (int i = prev; i < prev + extraSpace; i++) {
              tempAns = tempAns + A[i] + extraSlot;
          }
          for (int i = prev + extraSpace; i <= counter - 1; i++) {
              tempAns = tempAns + A[i] + avgSlot;
          }
          tempAns = tempAns + A[counter];
        }
        //cout<<tempAns<<endl;
        ans.push_back(tempAns);
        counter++;
        prev = counter;
    }
    return ans;
}

int main(void) {
  vector < string > input = {"What", "must", "be", "shall", "be."};
  int blockSize = 12;
  vector < string > ans = fullJustify(input, blockSize);
  for (int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<endl;
  }
  return 0;
}
