#include <iostream>
#include <fstream>
#include "bit_vector.h"
using namespace std;

int main() {
  int n = 10000000;
  string i;
  devstacks::BitVector * bvptr = new devstacks::BitVector(n);
  ifstream input ("input.txt");
  if (input.is_open()) {
    while (getline(input, i)) {
      bvptr->Set(stoi(i));
    }
  }
  input.close();

  ofstream output ("output.txt");
  ofstream outputTest ("output_test.txt");
  if (output.is_open()) {
    for(int i = 1; i <= n; i++) {
      if (bvptr->Test(i)) {
        output << i << "\n";
      } else {
        outputTest << i << "\n";
      }
    }
  }
  output.close();
  outputTest.close();

  delete bvptr;
  return 0;
}


