// �w�b�_�[�t�@�C�����C���N���[�h����
#include <iostream>
#include <array>

// ���`�T���̊֐�
int linear_search(std::array<int, 10>& array, int target) {
    // �z��̗v�f��擪���珇�ɒ��ׂ�
    for (int i = 0; i < array.size(); i++) {
        // �ړI�̒l�����������炻�̃C���f�b�N�X��Ԃ�
        if (array[i] == target) {
            return i;
        }
    }
    // �ړI�̒l��������Ȃ�������-1��Ԃ�
    return -1;
}

// ���C���֐����`����
int main()
{
    // �z���錾����
    std::array<int, 10> array = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    // �ړI�̒l����͂���
    int target;
    std::cin >> target;
    // ���`�T�������s����
    int index = linear_search(array, target);
    // ���ʂ��o�͂���
    if (index != -1) {
        std::cout << "Found at index " << index << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }
    // �v���O�������I������
    return 0;
}