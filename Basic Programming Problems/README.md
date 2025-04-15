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
![image](https://github.com/user-attachments/assets/d47ff7c9-6c17-4c36-8615-3b1c621414dd)
```
#include <iostream>
#include <string>
#include <cctype>  // for islower, isupper, tolower, toupper
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;
    char original = str[n];
    char converted;

    if (islower(original)) {
        converted = toupper(original);
    } else if (isupper(original)) {
        converted = tolower(original);
    } else {
        converted = original;  // 非字母就不轉
    }

    str[n] = converted;

    cout << "The letter that was selected is: " << converted << endl;
    cout << str << endl;

    return 0;
}


```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/c45d0059-581c-4daf-8a82-f1d455f90ee1) ![image](https://github.com/user-attachments/assets/f4c5e62e-0958-40e5-9c64-fd541e2c8bfc)


```
#include <iostream>
#include <string>
#include <algorithm>  // for reverse
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    if (str1.length() < 4 || str1.length() > 20 || str2.length() < 4 || str2.length() > 20) {
        cout << "error" << endl;
        return 0;
    }

    cout << str1.length() << endl;
    cout << str2.length() << endl;

    string combined = str1 + str2;
    reverse(combined.begin(), combined.end());

    cout << combined << endl;

    return 0;
}

```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/2d9a0bf7-57aa-449e-be9b-4484bf2c122e) ![image](https://github.com/user-attachments/assets/eb1bd269-9500-4a97-9535-19c8382937d7)


```
#include <iostream>
using namespace std;

int compute(int score) {
    if (score < 0 || score > 100) {
        return -1;
    }
    if (score >= 60) {
        return score + 5;
    }
    return score + 10;
}

int main() {
    int score;
    cin >> score;
    int result = compute(score); // 呼叫 compute 函式
    cout << result << endl;
    return 0;
}
```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/ccf01011-7386-4d21-981e-75167ed53623)

```
#include <iostream>
#include <string>

int main() {
    std::string str1, str2;
    std::cin >> str1;
    std::cin >> str2;

    std::cout  << str1.size() << "\n";
    std::cout  << str2.length() << "\n";
   
    std::string result = str1 + str2;
    std::cout  << result << "\n";
   
    return 0;
}
```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/f56f1a85-f2e5-4a55-a943-02498c1e77c3)

```
#include <iostream>

int main() {
    int count[6] = {0}; // 0-1 1-2 2-3 3-4 4-5 5-6 (arr-num)
    int errorCount = 0;
    int num;
   
    for (int i = 0; i < 10; ++i) {
        std::cin >> num;
        if (num >= 1 && num <= 6) {
            count[num - 1]++;
        } else {
            errorCount++;
        }
    }
   
    for (int i = 0; i < 6; ++i) {
        std::cout << "number" << (i + 1) << ":" << count[i] << "\n";
    }
    std::cout << "error:" << errorCount << "\n";
    return 0;
}
```
--------------------------------------------------------------
![image](https://github.com/user-attachments/assets/a0610016-24c5-4efa-b344-4ca8f785b03b)
![image](https://github.com/user-attachments/assets/d2602e01-0870-4bda-ba87-e64ff2d39259)
![image](https://github.com/user-attachments/assets/cdc3e563-22cf-41da-aba9-58ecd957bbf6)

```
#include <iostream>
#include <cstring>

int main() {
    char str1[129], str2[129];
    int n;
   
    std::cin.getline(str1, 129);
	//fgets(str1, sizeof(str1), stdin); /*可以儲存包含空白的字串*/
    //str1[strcspn(str1,"\n")]='\0'; /*strcspn從字元陣列中找到目標字元的索引值*/
    std::cin.getline(str2, 129);
   
    if (std::strlen(str1) != std::strlen(str2)) {
        std::cout << "error" << std::endl;
        return 1;
    }
   
    std::cin >> n; //比較長度
   
    if (n > std::strlen(str1)) {
        std::cout << "error" << std::endl;
        return 1;
    }
   
    int cmp = std::strncmp(str1, str2, n);
    if (cmp > 0) {
        std::cout << str1 << " > " << str2 << std::endl;
    } else if (cmp < 0) {
        std::cout << str1 << " < " << str2 << std::endl;
    } else {
        std::cout << str1 << " = " << str2 << std::endl;
    }  
    return 0;
}
```
--------------------------------------------------------------

```

```
--------------------------------------------------------------











