#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // vector<int>�^�̕ϐ�v��錾
    std::vector<int> v;

    // v��1����10�܂ł̒l������
    for (int i = 1; i <=7; i++) {
        v.push_back(i);
    }

    // ������������쐬
    std::random_device rd;
    std::mt19937 g(rd());

    // shuffle�񐔂��J�E���g����ϐ�count��錾���A0�ɏ���������
    int count = 0;

    // do-while����shuffle���J��Ԃ�
    do {
        // shuffle�֐���v�̗v�f�������_���ɕ��בւ���
        std::shuffle(v.begin(), v.end(), g);

        // shuffle�񐔂��C���N�������g����
        count++;

        // v�̗v�f���o�͂���
        for (int x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";

    } while (!std::is_sorted(v.begin(), v.end())); // v�������Ƀ\�[�g����Ă��Ȃ��Ԃ͌J��Ԃ�

    // shuffle�񐔂�\������
    std::cout << "shuffle��: " << count << "\n";

    return 0;
}