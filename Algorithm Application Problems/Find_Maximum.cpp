/*
�D�̤j��
Input file: pf.txt
���D�ԭz
���]���@�n�餽�q���F�Y�z�ӭp�e�A�C�ӭp�e�Ҧ����ת�����Ωһݪ��u�@
�ѼơA�t�~�C�@�ӭp�e�p�G��b���������u���סA�����t�ӱN�����B�~�����C��
²�ư��D�A���]���פ�����@����ƥB�C�@�p�e�@���}�l����N�����s����檽
�쵲�׬���A���~�]��������L�p�e�C�ռg�@�{���ƥX�̨Ϊ�����p�e���ǡA
�ϯ���o�̦h�������C�`�N�A�����Ҧ����p�e����p�������צ���o�����C
��J�榡
��J�ɤ����T�մ��ո�ơA�C�@�զ��@�C��J�A��J�榡���G
n d1 t1 b1 d2 t2 b2 �K dn tn bn
�䤤 n <100��ܭp�e���ӼơA�����N i�A i d ���@��ƥΨӪ�ܲ�i �ӭp�e��
���פ���A i t ��ܲ�i �ӭp�e�һݪ��ѼơA i b ��ܲ�i �ӭp�e�p���δ��e���ת�
�����C
��X�榡
�C�մ��ո�Ƥ����i����o���̰��������B�C
��J�d��
3 1 1 1 3 2 2 5 2 2
2 1 3 2 2 2 3
4 1 1 1 2 2 2 3 3 3 4 2 2
��X�d��
5
3
4
*/ 

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// �w�q�@�ӵ��c�N��C�ӱM�ת��T���ݩ�
struct Project {
    int deadline;  // �M�ת��I���� d
    int duration;  // �����M�׻ݭn���u�@�Ѽ� t
    int bonus;     // �p������������ b
};

// �֤��޿��ơG�p��̤j�i��o������
int solve(vector<Project>& projects) {
    // �N�M�ר̷ӺI�������ƧǡA�����I����M�פ�����e�����L����
    // lambda
    sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) { 
        return a.deadline < b.deadline;
    });

    int maxTime = 0;  // �p��z�פW�̦h�i��ݭn���`�ɶ��]�����M�׳����^
    for (auto& p : projects) {
        maxTime += p.duration;
    }

     // �w�q dp �}�C�Adp[t] ��ܲ� t �ѫ�ү���o�̦h������
    vector<int> dp(maxTime + 1, -1); // ��l�Ƭ� -1 ��ܸӮɶ����i�F
    dp[0] = 0; // �ɶ� 0 �ɨS���������M�סA������ 0

    // �v�@�Ҽ{�C�ӱM��
    for (auto& p : projects) {
        // �q�᩹�e���A�H�קK�b�P�@���j�餤���ƿ���P�@�ӱM��
        for (int t = maxTime - p.duration; t >= 0; --t) {
            if (dp[t] != -1) { // �p�G�ɶ� t �O�i�F���A
                int end_time = t + p.duration; // �����o�ӱM�׫᪺�s�ɶ��I
                // �Y�b deadline �e�����A�h�i��o�����A�_�h�� 0
                int reward = (end_time <= p.deadline) ? p.bonus : 0;
                // ��s dp[end_time] ���̤j�i���
                dp[end_time] = max(dp[end_time], dp[t] + reward);
            }
        }
    }

    // �q�Ҧ��ɶ��I����X�̤j������
    return *max_element(dp.begin(), dp.end());
}

int main() {
    string line;
    // ����Ū���C�@�檽�� EOF �ιJ��Ŧ�
    while (getline(cin, line)) {
        if (line.empty()) break; // �Ŧ�N����

        stringstream ss(line); // �إߦr���J��y
        vector<int> input_data; // �Ψ��x�s�@��檺�Ҧ��Ʀr
        int num;
        // ��r���y�����Ʀr�v�@���X�s�J input_data
        while (ss >> num) {
            input_data.push_back(num);
        }

        int n = input_data[0]; // �Ĥ@�ӼƦr�O�M�׼ƶq n
        vector<Project> projects(n); // �إ� n �ӱM�ת����c�}�C 
        
        // �̧�Ū�J�C�ӱM�ת��T�ӰѼơGdeadline�Bduration�Bbonus
        for (int i = 0; i < n; ++i) {
            projects[i].deadline = input_data[i * 3 + 1]; // �� i �ӱM�ת� deadline
            projects[i].duration = input_data[i * 3 + 2]; // �� i �ӱM�ת� duration
            projects[i].bonus    = input_data[i * 3 + 3]; // �� i �ӱM�ת� bonus
        }

        // �I�s�Ѫk�ÿ�X�̤j����
        int result = solve(projects);
        cout << result << endl;
    }

    return 0;
}
