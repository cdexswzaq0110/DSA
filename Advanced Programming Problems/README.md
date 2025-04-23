*** This is a Advanced Programming Problem Solving Exercises. ***

---Advance C/C++ Programs---
![image](https://github.com/user-attachments/assets/1fda761a-bd0c-4f85-9e44-fe5ce7a76f2b)
![image](https://github.com/user-attachments/assets/65843fdd-cef6-4f4b-8797-589112b013f4)
![image](https://github.com/user-attachments/assets/2aee89c6-d8fd-4051-831a-33d4783e6216)

```

---Funny Decoder---

![image](https://github.com/user-attachments/assets/0c2af334-c6d5-42dc-ac8f-b5f55e0d7e35)
![image](https://github.com/user-attachments/assets/10011a41-10f9-4c55-828f-be204df3c6f3)
![image](https://github.com/user-attachments/assets/4dd01990-aab6-4db7-bb3d-fdcb7a3230e0)

/*

10 5
Anlld km  wna oyakoor e .*dspk l u**lJaayal** cb**

5 6
Kenodiwsgwle erp o.*

7 5
A ctsltopioeuhrdadanskens. r  w**o*

*/


#include <iostream>              
#include <vector>                
#include <string>                

using namespace std;

int main() {
    int row, col;                // 宣告行數與列數
    string encrypted;            // 宣告密文字串

    cin >> row >> col;           // 從標準輸入讀入行與列
    cin.ignore();                // 忽略掉 cin 之後的換行符號
    getline(cin, encrypted);     // 從下一行讀入完整密文（包括空格）

    // 檢查密文長度是否與 row × col 相符，否則輸出錯誤訊息
    if (encrypted.length() != row * col) {
        cout << "[encrypted length error]" << endl;
        return 0;
    }

    // 建立 row x col 的矩陣，初始值都設為 *（代表尚未填入）
    vector<vector<char> > matrix(row, vector<char>(col, '*'));

    int idx = 0; // 用來追蹤密文的索引位置
    /*
    
    {[對角線no.] row col}
	[0] 00 / [1] 01 10 / [2] 20 11 02 / [3] 03 12 21 30 / 
	[4] 40 31 22 13 04 / [5] 14 23 32 41 50 / 
	[6] 60 51 42 33 24 / [7] 34 43 52 61 / 
	[8] 62 53 44 / [9] 54 63 / [10] 64 
	
	*/ 
    // 對角線掃描：總共 row + col - 1 條對角線 (7+5-1=11,sum:0-10) 
    for (int sum = 0; sum < row + col - 1; ++sum) { // 
        if (sum % 2 == 0) {
            // 偶數對角線(0 2 4 6 8 10)：從左下往右上填 ↗(>6:8 10), sum超過6時, r=6, r從6開始 
            int r = min(sum, row - 1);  
            int c = sum - r;            

            // 只要沒出界就繼續往右上走（r--, c++）
            while (r >= 0 && c < col) {
                matrix[r][c] = encrypted[idx++]; // 填入密文中的字元
                r--; c++; //偶數 r向右上減少，c向右上增加；[r--:r不可小於0, c++:C不可超過col]
            }
        } else {
            // 奇數對角線(1 3 5 7 9)：從右上往左下填 ↙(>4:5 7 9), sum超過4時, r=4, r從4開始 
            int c = min(sum, col - 1);  
            int r = sum - c;            

            // 只要沒出界就繼續往左下走（r++, c--）
            while (r < row && c >= 0) {
                matrix[r][c] = encrypted[idx++]; // 填入密文中的字元
                r++; c--; //奇數 r向左下增加，c向左下減少；[r++:r不可超過row, c--:C不可小於0]
            }
        }
    }

    // 解碼：採用欄優先（直式）讀取每一個字元 ,row先++ 
    /*
    
        00 ↓ 
	10 ↓ 
	20 ↓
	30 ↓
	40 ↓
	50 ↓
	60 ↓
	   
    */ 
	
    string decoded;
    for (int j = 0; j < col; ++j) {
    	for (int i = 0; i < row; ++i) {
        	if (matrix[i][j] != '*')  {    // 忽略填充的 *（未填入的格子）
                decoded += matrix[i][j];  // 將有效字元加入解碼字串
            }
		}
	}                             
    cout << decoded << endl; // 輸出解碼完成的結果
    return 0;
}

```
