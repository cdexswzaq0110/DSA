![image](https://github.com/user-attachments/assets/0c3a36e1-e447-4e1e-bf20-8ae41d8a314d)
![image](https://github.com/user-attachments/assets/90d9f0b0-acf7-440b-9a3d-4b98b6c8834d)

```
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mid = (n + 1) / 2;  // 上半部行數

    // 上半部（包含最寬的行）
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }

    // 下半部
    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }

    return 0;
}
```
----------------------------------------------------------
![image](https://github.com/user-attachments/assets/978dac81-000d-4bb4-901f-d88347f23f9e)
![image](https://github.com/user-attachments/assets/c0410971-38bd-4096-b98b-d140ca7f6f87)

```
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mid = (n + 1) / 2;  // 上半部行數

    // 上半部（包含最寬的行）
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid - i - 1; j++) cout << " ";  // 空白
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) cout << "*";  // 第一個 & 最後一個位置
            else cout << " ";  // 中間空白
        }
        cout << endl;
    }

    // 下半部
    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i - 1; j++) cout << " ";  // 空白
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) cout << "*";  // 第一個 & 最後一個位置
            else cout << " ";  // 中間空白
        }
        cout << endl;
    }

    return 0;
}

```
