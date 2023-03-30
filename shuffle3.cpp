#include <iostream>
#include <array>
#include <algorithm>
#include <random>

int main() {
    // array<int, 10>�^�̕ϐ�arr��錾���A1����10�ŏ���������
    std::array<int, 10> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // ������������쐬
    std::random_device rd;
    std::mt19937 g(rd());

    // �����ɂȂ��Ă�����̍ő�l���L�^����ϐ�max_count��錾���A0�ɏ���������
    int max_count = 0;

    // �����ɂȂ��Ă�������ő傾�����Ƃ��̔z����L�^����ϐ�max_arr��錾����
    std::array<int, 10> max_arr;

    // for����1���񎎂�
    for (int trial = 0; trial < 1000000; trial++) {
        // shuffle�֐���arr�̗v�f�������_���ɕ��בւ���
        std::shuffle(arr.begin(), arr.end(), g);

        // �����ɂȂ��Ă�������J�E���g����ϐ�count��錾���A0�ɏ���������
        int count = 0;

        // for����arr�̗v�f���`�F�b�N����
        for (int i = 0; i < arr.size() - 1; i++) {
            // arr[i] < arr[i+1]�Ȃ珸���Ɣ��f���Acount���C���N�������g����
            if (arr[i] < arr[i + 1]) {
                count++;
            }
        }

        // count��max_count���傫����΁Amax_count��max_arr���X�V����
        if (count > max_count) {
            max_count = count;
            max_arr = arr;
        }
    }

    // �����ɂȂ��Ă�����̍ő�l�Ƃ��̂Ƃ��̔z���\������
    std::cout << "�����ɂȂ��Ă�����̍ő�l: " << max_count << "\n";

    std::cout << "���̂Ƃ��̔z��: ";
    for (int x : max_arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}