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
![image](https://github.com/user-attachments/assets/3afe500a-f916-4498-8e84-dfa19ddd1541)
![image](https://github.com/user-attachments/assets/1a00dcda-7f28-439b-b24f-7706dcc164e0)


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
----------------------------------------------------------
![image](https://github.com/user-attachments/assets/2e06bec7-4110-4134-ba74-398a2bbf1b3c)
![image](https://github.com/user-attachments/assets/3e3b6425-d420-42fa-a831-962529f6c3d3)

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int> > A(n, vector<int>(m)); // 先建立轉置後的矩陣空間
    vector<vector<int> > original(m, vector<int>(n)); // 儲存原始矩陣

    // 讀取矩陣元素
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> original[i][j];
            A[j][i] = original[i][j]; // 直接轉置存入 A
        }
    }

    // 輸出原始矩陣
    cout << "Original:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j > 0) cout << " ";
            cout << original[i][j];
        }
        cout << "]" << endl;
    }

    // 輸出轉置矩陣
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

```
----------------------------------------------------------
![image](https://github.com/user-attachments/assets/2264f5b4-8523-47bd-92b0-87ae4726ba04)
![image](https://github.com/user-attachments/assets/f4122bff-546f-4892-8f37-3f593a8727b3)


```
#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int> > grid;
vector<vector<bool> > visited;
int maxArea = 0;

// 方向向量 (上, 下, 左, 右)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 深度優先搜尋 (DFS) 計算相連區域面積
int dfs(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N || visited[x][y] || grid[x][y] != 0)
        return 0;

    visited[x][y] = true;  // 標記為已訪問
    int area = 1;  // 當前區塊計算進面積

    // 向四個方向擴展搜尋
    for (int i = 0; i < 4; i++) {
        area += dfs(x + dx[i], y + dy[i]);
    }

    return area;
}

int main() {
    cin >> M >> N;
    grid.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false));

    // 讀取輸入
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // 遍歷整個矩陣，找出最大的低窪區域
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                maxArea = max(maxArea, dfs(i, j));
            }
        }
    }

    cout << maxArea << endl;
    return 0;
}

```

----------------------------------------------------------


```


```

----------------------------------------------------------
































