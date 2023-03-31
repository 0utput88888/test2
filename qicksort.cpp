#include <iostream> // ���o�͂��������C�u����
#include <cstdlib> // �������������C�u����
#include <ctime> // �������������C�u����
#include <algorithm>

// �z��̗v�f�����ւ���֐�
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// �z��̍ŏ��E�����E�Ō�̗v�f�̒����l��Ԃ��֐�
int median_of_three(int a[], int low, int high) {
    int mid = (low + high) / 2; // �����̃C���f�b�N�X
    // �ŏ��E�����E�Ō�̗v�f�������ɕ��ׂ�
    if (a[low] > a[mid]) swap(a[low], a[mid]);
    if (a[mid] > a[high]) swap(a[mid], a[high]);
    if (a[low] > a[mid]) swap(a[low], a[mid]);
    // �����̗v�f��Ԃ�
    return a[mid];
}

// �z���pivot����ɕ�������֐�
int partition(int a[], int low, int high) {
    // pivot��median-of-three�@�őI��
    int pivot = median_of_three(a, low, high);
    // low��high�̊Ԃ�pivot��菬�����v�f�Ƒ傫���v�f�����ւ���
    while (low <= high) {
        // pivot��菬�����v�f��������T��
        while (a[low] < pivot) low++;
        // pivot���傫���v�f���E����T��
        while (a[high] > pivot) high--;
        // �������������ւ���
        if (low <= high) {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    }
    // �����_�̃C���f�b�N�X��Ԃ�
    return low;
}

// �N�C�b�N�\�[�g�̊֐�
void quicksort(int a[], int low, int high) {
    // �͈͂�1�ȏ�Ȃ�\�[�g����
    if (low < high) {
        // �z��𕪊�����
        int index = partition(a, low, high);
        // �����̕����z����\�[�g����
        quicksort(a, low, index - 1);
        // �E���̕����z����\�[�g����
        quicksort(a, index, high);
    }
}

int main() {
    // �����̎�����ݎ����ŏ���������
    srand(time(NULL));
    // �v�f��10�̐����^�̔z���錾����
    int a[10];
    // �z��̊e�v�f��0����99�܂ł̃����_���Ȓl��������
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }

    quicksort(a, 0, 9);

    if (std::is_sorted(a, a + 10)) {
        // �z��̗v�f�����ׂĕ\������
        for (int i = 0; i < 10; i++) {
            std::cout << a[i] << " "; // �z���i�Ԗڂ̗v�f�Ƌ󔒂��o�͂���
        }
        std::cout << std::endl; // ���s���o�͂���
    }
}