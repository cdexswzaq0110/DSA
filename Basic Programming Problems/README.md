*** This is a Basic Programming Problem Solving Exercises. ***

---Advance C/C++ Programs---
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/75ca41b6-8c54-43bc-b7ed-997d97265b0d)
```
#include <iostream>
int compute(int arr[]) {
    int rowStars = arr[0]; //每列星星數
int rowsNum=arr[1];  //列數
int totalStars = rowStars * rowsNum; // 總星數

    for (int i = 0; i != rowsNum; i++) {
        for (int j = 0; j != rowStars; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return totalStars; // 回傳總星數
}

int main() {
int arr[2];
    std::cin >> arr[0] >> arr[1];
    int total = compute(arr);
    std::cout << total << std::endl;

    return 0;

}
```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/81a51561-8786-48e1-83cf-09757c3446cf)
```
#include <iostream>
#include <cmath>  
#include <iomanip>  

int main() {
    double num1, num2;

    std::cin >> num1;
    std::cin >> num2;

    double result = sqrt(num1 + num2);
    double roundedResult = floor(result * 100 + 0.5) / 100;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "result=" << roundedResult << std::endl;

    return 0;
}
```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/53c35e6d-0610-4683-8684-e69d27659efd)

```
#include <iostream>

int main() {
    int num1, num2;
    char op;

    // 讀取輸入
    std::cin >> num1 >> num2 >> op;

    // 判斷運算符號並計算結果
    if (op == '+') {
        std::cout << num1 << "+" << num2 << "=" << (num1 + num2) << std::endl;
    } else if (op == '-') {
        std::cout << num1 << "-" << num2 << "=" << (num1 - num2) << std::endl;
    } else if (op == '*') {
        std::cout << num1 << "*" << num2 << "=" << (num1 * num2) << std::endl;
    } else {
        std::cout << "error" << std::endl;
    }

    return 0;
}
```

--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/936a634a-43ae-4127-b0ee-b3ebc7768e36) ![image](https://github.com/user-attachments/assets/4fb59362-d6ef-4d28-b23c-2d653492c8e5)


```
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    if (input == "0") {
        cout << "0=0" << endl;
        return 0;
    }

    int product = 1;
    for (int i = 0; i < input.length(); i++) {
        cout << input[i];
        if (i != input.length() - 1) {
            cout << "*";
        }
        product *= (input[i] - '0');  // 將字元轉為數字再乘
    }
    cout << "=" << product << endl;

    return 0;
}

```
--------------------------------------------------------------










