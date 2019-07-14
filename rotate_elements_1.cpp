#include <iostream>

using namespace std;

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
  int multiple = 0;
  int temp = data[0];
  int j, k;
  while (true) {
    j = (multiple * i) % n;
    k = ((multiple + 1) * i) % n;
    if (k == 0) break;
    data[j] = data[k];
    multiple++;
  }
  data[j] = temp;
  cout << "Rotated left by " << i << " positions" << endl;
  for(int j = 0; j < n; j++) {
    cout << data[j] << " ";
  }
  cout << endl;
  return 0;
}
