#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
  static int a[8][5] = { // Helper Array
  {-1}, // 0
  {0,-1}, // 1
  {0,1,-1}, // 2
  {0,2,-1}, // 3
  {1,2,-1}, // 4
  {1,2,3,4,-1}, // 5
  {2,3,5,-1}, // 6
  {4,5,6,-1} // 7
  };
  //Checks Repeating Values
  for(int i =0; i < c; i++){
    if(q[c]==q[i]) return false;
  }
  //Checks Consecutive Values
  for(int i=0; a[c][i] != -1; i++){
    if(abs(q[a[c][i]]-q[c]) == 1) 
      return false;
  }
  return true;
}

void print(int q[]) {
static int sol = 1;
cout << "Solution#:" << sol++ << endl;
cout << " " << q[1] << q[4] << endl;
cout << q[0] << q[2] << q[5] << q[7] << endl;
cout << " " << q[3] << q[6] << endl;
cout << endl;
}

int main() {
int q[8],c=0;
  q[c]=1;
  
  while(c >= 0){
    //nc
    c++;
    if (c==8) {
      print(q);
      c--;
    }
    else q[c] = 0;
    while(c >=0){
      //nr
      q[c]++;
      if (q[c] == 8) c--;
      else if (ok(q,c)) break;  
    }
  }
}