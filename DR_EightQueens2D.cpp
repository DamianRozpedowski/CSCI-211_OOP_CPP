#include <iostream>
using namespace std;

int main(){
  int numSolutions = 0;
  int q[8][8] = {};     
  int r = 0, c = 0;
  q[r][c] = 1; // Queen placed in row 0, col 0

nc:
  c++;
  if (c == 8) goto print; //Once last column is passed, print
  r = -1;  // Else start at the top of the colomn

nr:
  r++;
  if (r == 8) goto backtrack;

  // Row Test
  for (int i = 0; i < c; i++){
    if (q[r][i] == 1) goto nr;
  }

  // Up Diagonal Test
  for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){
    if (q[r-i][c-i] == 1) goto nr;
  }

  // Down Diagonal Test
  for (int i = 1; ((r+i)<=7 && (c-i)>=0); i++){
    if (q[r+i][c-i] == 1) goto nr;
  }

  q[r][c] = 1;
  goto nc;

backtrack:
  c--; //Go back a column
  if (c == -1){ // if out of bounds
    return 0;
  }
 
  r = 0;
  while (q[r][c] != 1){ // Find the Queen
    r++;
  }
  q[r][c] = 0; //Remove the Queen
  goto nr;

print:
  cout << "Solution #" << ++numSolutions << endl;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      cout << q[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  goto backtrack;
}