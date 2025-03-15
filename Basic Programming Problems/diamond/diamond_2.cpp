/*

Hollow Diamond Shape Aligned on Both Sides
This program generates a hollow diamond shape aligned on both sides, based on user input for the height.

Input & Output Examples:
Example 1:
Input: 5
Output:
  *
 * *
*   *
 * *
  *
  
Example 2:
Input: 6
Output:
  *
 * *
*   *
*   *
 * *
  *
  
*/ 

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mid = (n + 1) / 2;  // �W�b�����

    // �W�b���]�]�t�̼e����^
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid - i - 1; j++) cout << " ";  // �ť�
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) cout << "*";  // �Ĥ@�� & �̫�@�Ӧ�m
            else cout << " ";  // �����ť�
        }
        cout << endl;
    }

    // �U�b��
    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i - 1; j++) cout << " ";  // �ť�
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) cout << "*";  // �Ĥ@�� & �̫�@�Ӧ�m
            else cout << " ";  // �����ť�
        }
        cout << endl;
    }

    return 0;
}

