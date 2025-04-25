/*
求最大值
Input file: pf.txt
問題敘述
假設有一軟體公司接了若干個計畫，每個計畫皆有結案的日期及所需的工作
天數，另外每一個計畫如果能在期限內完工結案，有關廠商將提供額外獎金。為
簡化問題，假設結案日期為一正整數且每一計畫一但開始執行就必須連續執行直
到結案為止，中途也不能執行其他計畫。試寫一程式排出最佳的執行計畫順序，
使能獲得最多的獎金。注意，未必所有的計畫均能如期的結案而獲得獎金。
輸入格式
輸入檔中有三組測試資料，每一組有一列輸入，輸入格式為：
n d1 t1 b1 d2 t2 b2 … dn tn bn
其中 n <100表示計畫的個數，對於任意 i， i d 為一整數用來表示第i 個計畫的
結案日期， i t 表示第i 個計畫所需的天數， i b 表示第i 個計畫如期或提前結案的
獎金。
輸出格式
每組測試資料中有可能獲得的最高獎金金額。
輸入範例
3 1 1 1 3 2 2 5 2 2
2 1 3 2 2 2 3
4 1 1 1 2 2 2 3 3 3 4 2 2
輸出範例
5
3
4
*/ 

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 定義一個結構代表每個專案的三個屬性
struct Project {
    int deadline;  // 專案的截止日期 d
    int duration;  // 完成專案需要的工作天數 t
    int bonus;     // 如期完成的獎金 b
};

// 核心邏輯函數：計算最大可獲得的獎金
int solve(vector<Project>& projects) {
    // 將專案依照截止日期做排序，先做截止早的專案比較不容易錯過獎金
    // lambda
    sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) { 
        return a.deadline < b.deadline;
    });

    int maxTime = 0;  // 計算理論上最多可能需要的總時間（全部專案都做）
    for (auto& p : projects) {
        maxTime += p.duration;
    }

     // 定義 dp 陣列，dp[t] 表示第 t 天後所能獲得最多的獎金
    vector<int> dp(maxTime + 1, -1); // 初始化為 -1 表示該時間不可達
    dp[0] = 0; // 時間 0 時沒有執行任何專案，獎金為 0

    // 逐一考慮每個專案
    for (auto& p : projects) {
        // 從後往前走，以避免在同一次迴圈中重複選取同一個專案
        for (int t = maxTime - p.duration; t >= 0; --t) {
            if (dp[t] != -1) { // 如果時間 t 是可達狀態
                int end_time = t + p.duration; // 做完這個專案後的新時間點
                // 若在 deadline 前完成，則可獲得獎金，否則為 0
                int reward = (end_time <= p.deadline) ? p.bonus : 0;
                // 更新 dp[end_time] 為最大可能值
                dp[end_time] = max(dp[end_time], dp[t] + reward);
            }
        }
    }

    // 從所有時間點中找出最大獎金值
    return *max_element(dp.begin(), dp.end());
}

int main() {
    string line;
    // 持續讀取每一行直到 EOF 或遇到空行
    while (getline(cin, line)) {
        if (line.empty()) break; // 空行就結束

        stringstream ss(line); // 建立字串輸入串流
        vector<int> input_data; // 用來儲存一整行的所有數字
        int num;
        // 把字串串流中的數字逐一取出存入 input_data
        while (ss >> num) {
            input_data.push_back(num);
        }

        int n = input_data[0]; // 第一個數字是專案數量 n
        vector<Project> projects(n); // 建立 n 個專案的結構陣列 
        
        // 依序讀入每個專案的三個參數：deadline、duration、bonus
        for (int i = 0; i < n; ++i) {
            projects[i].deadline = input_data[i * 3 + 1]; // 第 i 個專案的 deadline
            projects[i].duration = input_data[i * 3 + 2]; // 第 i 個專案的 duration
            projects[i].bonus    = input_data[i * 3 + 3]; // 第 i 個專案的 bonus
        }

        // 呼叫解法並輸出最大獎金
        int result = solve(projects);
        cout << result << endl;
    }

    return 0;
}
