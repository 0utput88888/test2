#include <iostream> // ���o�͂��������C�u����
#include <cstdlib> // �������������C�u����
#include <ctime> // �������������C�u����

int main() {
    // �����̎�����ݎ����ŏ���������
    srand(time(NULL));
    // �v�f��10�̐����^�̔z���錾����
    int a[10];
    // �z��̊e�v�f��0����99�܂ł̃����_���Ȓl��������
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    // �z��̗v�f�����ׂĕ\������
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " "; // �z���i�Ԗڂ̗v�f�Ƌ󔒂��o�͂���
    }
    std::cout << std::endl; // ���s���o�͂���
}