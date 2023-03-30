#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // vector<int>�^�̕ϐ�v��錾
    std::vector<int> v;

    // v��1����10�܂ł̒l������
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
    }

    // ������������쐬
    std::random_device rd;
    std::mt19937 g(rd());

    // shuffle�֐���v�̗v�f�������_���ɕ��בւ���
    std::shuffle(v.begin(), v.end(), g);

    // v�̗v�f���o�͂���
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}