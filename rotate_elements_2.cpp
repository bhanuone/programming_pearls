#include <iostream>

using namespace std;

void reverse(int * A, int i, int j) {
  int tmp;
  while (i <= j) {
    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
    i++;
    j--;
  }
}

int main() {
  int n, i;
  cout << "Enter n:" << endl;
  cin >> n;
  cout << "Enter i:" << endl;
  cin >> i;
  int data[n];
  for(int j = 0; j < n; j++) {
    cin >> data[j];
  }
  for(int j = 0; j < n; j++) {
    cout << data[j] << " ";
  }
  cout << endl;
  reverse(data, 0, i - 1);
  reverse(data, i, n - 1);
  reverse(data, 0, n - 1);
  for(int j = 0; j < n; j++) {
    cout << data[j] << " ";
  }
  cout << endl;
  return 0;
}
