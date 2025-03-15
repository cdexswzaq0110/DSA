/*

Matrix Transpose Program
This program takes a matrix as input, computes its transpose, and prints both the original and transposed matrices.

Problem Description:
Write a program that first reads two integers:

m (number of columns of matrix A)
n (number of rows of matrix A)
Then, it reads m �� n integers in sequence, forming matrix A. The program calculates the transpose of A, denoted as A?, and outputs both matrices.

Definition:
A matrix is a two-dimensional data structure of size m �� n, where a?? represents the element at column i and row j.
The transpose of a matrix A is another matrix A?, where each element at position (i, j) in A is moved to position (j, i) in A?.
Input & Output Format:
Input:
An integer m (number of columns)
An integer n (number of rows)
m �� n integers representing the matrix elements, read row-wise.
Output:
Print the original matrix A, using square brackets ([ ]) to enclose rows, with elements separated by a half-width space.
Print the transposed matrix A?, formatted the same way.

Example 1:
Input:
2
3
1
2
3
4
5
6
Output:
Original:
[1 2 3]
[4 5 6]
Transpose:
[1 4]
[2 5]
[3 6]
Example 2:
Input:
3
3
-1
25
-5
33
100
-78
56
63
-99
Output:
Original:
[-1 25 -5]
[33 100 -78]
[56 63 -99]
Transpose:
[-1 33 56]
[25 100 63]
[-5 -78 -99]

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int> > A(n, vector<int>(m)); // ���إ���m�᪺�x�}�Ŷ�
    vector<vector<int> > original(m, vector<int>(n)); // �x�s��l�x�}

    // Ū���x�}����
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> original[i][j];
            A[j][i] = original[i][j]; // ������m�s�J A
        }
    }

    // ��X��l�x�}
    cout << "Original:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j > 0) cout << " ";
            cout << original[i][j];
        }
        cout << "]" << endl;
    }

    // ��X��m�x�}
    cout << "Transpose:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < m; j++) {
            if (j > 0) cout << " ";
            cout << A[i][j];
        }
        cout << "]" << endl;
    }

    return 0;
}

