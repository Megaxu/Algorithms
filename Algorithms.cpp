#include <iostream>

void sort(int[], size_t, size_t);
void swap(int[], size_t, size_t);

int main() {
    int nums[]{ 3, 0, 6, -2, -6, 11, 3 };
    sort(nums, 0, std::size(nums) - 1);
    for (auto num : nums) {
        std::cout << num << "\t";
    }
    std::cout << std::endl;
}

void sort(int numbers[], size_t start, size_t end) {
    // ��������� ������ ������ ���� ������ ��������� ������� ��� ������� �� 2 � ����� ���������
    if (start >= end)
        return;
    // ��������� ��� �������� ������������ �������� � �������� start
    size_t current{ start };
    for (size_t i{ start + 1 }; i <= end; i++) {
        // ���� i-�� ������� ������ ����������
        if (numbers[i] < numbers[start]) {
            swap(numbers, ++current, i); // ������ ��� � �����
        }
    }
    swap(numbers, start, current); // ������ ��������� (start) � ��������� ���������� ��������
    if (current > start) {
        sort(numbers, start, current - 1); // ��������� �������� �����
    }
    if (end > current + 1) {
        sort(numbers, current + 1, end); // ��������� �������� ������
    }
}
void swap(int numbers[], size_t first, size_t second) {
    auto temp{ numbers[first] };
    numbers[first] = numbers[second];
    numbers[second] = temp;
}