#include <iostream>
#include <vector>

void MaxHeapify(std::vector<int>& nums, int i, int heap_size) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  if (left < heap_size && nums[left] > nums[largest]) {
    largest = left;
  }
  if (right < heap_size && nums[right] > nums[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(nums[i], nums[largest]);
    MaxHeapify(nums, largest, heap_size);
  }
}

// heap_size / 2, heap_size / 2 - 1, ..., heap_size - 1 is leaf node
void BuildMaxHeap(std::vector<int>& nums, int heap_size) {
  for (int i = heap_size / 2 - 1; i >= 0; --i) {
    MaxHeapify(nums, i, heap_size);
  }
}

void HeapSort(std::vector<int>& nums) {
  int heap_size = nums.size();
  BuildMaxHeap(nums, heap_size);
  for (int i = nums.size() - 1; i >= 1; --i) {
    std::swap(nums[0], nums[i]);
    --heap_size;
    BuildMaxHeap(nums, heap_size);
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 7, 0, 44, 3, 5};
  HeapSort(nums);
  for (int num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}
