#include <iostream>              
#include <vector>                
#include <string>                

using namespace std;

int main() {
    int row, col;                // �ŧi��ƻP�C��
    string encrypted;            // �ŧi�K��r��

    cin >> row >> col;           // �q�зǿ�JŪ�J��P�C
    cin.ignore();                // ������ cin ���᪺����Ÿ�
    getline(cin, encrypted);     // �q�U�@��Ū�J����K��]�]�A�Ů�^

    // �ˬd�K����׬O�_�P row �� col �۲šA�_�h��X���~�T��
    if (encrypted.length() != row * col) {
        cout << "[encrypted length error]" << endl;
        return 0;
    }

    // �إ� row x col ���x�}�A��l�ȳ��]�� *�]�N��|����J�^
    vector<vector<char> > matrix(row, vector<char>(col, '*'));

    int idx = 0; // �ΨӰl�ܱK�媺���ަ�m
    /*
    
    {[�﨤�uno.] row col}
	[0] 00 / [1] 01 10 / [2] 20 11 02 / [3] 03 12 21 30 / 
	[4] 40 31 22 13 04 / [5] 14 23 32 41 50 / 
	[6] 60 51 42 33 24 / [7] 34 43 52 61 / 
	[8] 62 53 44 / [9] 54 63 / [10] 64 
	
	*/ 
    // �﨤�u���y�G�`�@ row + col - 1 ���﨤�u (7+5-1=11,sum:0-10) 
    for (int sum = 0; sum < row + col - 1; ++sum) { // 
        if (sum % 2 == 0) {
            // ���ƹ﨤�u(0 2 4 6 8 10)�G�q���U���k�W�� ��(>6:8 10), sum�W�L6��, r=6, r�q6�}�l 
            int r = min(sum, row - 1);  
            int c = sum - r;            

            // �u�n�S�X�ɴN�~�򩹥k�W���]r--, c++�^
            while (r >= 0 && c < col) {
                matrix[r][c] = encrypted[idx++]; // ��J�K�夤���r��
                r--; c++; //���� r�V�k�W��֡Ac�V�k�W�W�[�F[r--:r���i�p��0, c++:C���i�W�Lcol]
            }
        } else {
            // �_�ƹ﨤�u(1 3 5 7 9)�G�q�k�W�����U�� ��(>4:5 7 9), sum�W�L4��, r=4, r�q4�}�l 
            int c = min(sum, col - 1);  
            int r = sum - c;            

            // �u�n�S�X�ɴN�~�򩹥��U���]r++, c--�^
            while (r < row && c >= 0) {
                matrix[r][c] = encrypted[idx++]; // ��J�K�夤���r��
                r++; c--; //�_�� r�V���U�W�[�Ac�V���U��֡F[r++:r���i�W�Lrow, c--:C���i�p��0]
            }
        }
    }

    // �ѽX�G�ĥ����u���]�����^Ū���C�@�Ӧr�� ,row��++ 
    /*
    
    00 �� 
	10 �� 
	20 ��
	30 ��
	40 ��
	50 ��
	60 ��
	   
	*/ 
	
    string decoded;
    for (int j = 0; j < col; ++j) {
    	for (int i = 0; i < row; ++i) {
        	if (matrix[i][j] != '*')  {    // ������R�� *�]����J����l�^
                decoded += matrix[i][j];  // �N���Ħr���[�J�ѽX�r��
            }
		}
	}                             
    cout << decoded << endl; // ��X�ѽX���������G
    return 0;
}
