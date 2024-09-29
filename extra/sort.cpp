
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

//
// sort
//

void bubble_sort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] > arr[j])
        swap(arr[i], arr[j]);
}

void selection_sort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    int min = i;
    for (int j = i + 1; j < len; j++)
      if (arr[min] > arr[j])
        min = j;
    if (min != i)
      swap(arr[i], arr[min]);
  }
}

void insertion_sort(int *arr, int len) {
  for (int i = 1; i < len; i++)
    for (int j = i; j > 0; j--)
      if (arr[j - 1] > arr[j])
        swap(arr[j - 1], arr[j]);
}

void shell_sort(int *arr, int len) { return; }

void merge(int *arr, int left, int mid, int right) {
  int len = right - left + 1;
  int *merge_arr = new int[len];
  int merge_i = 0;
  int merge_left = left;
  int merge_right = mid + 1;

  while (merge_left <= mid && merge_right <= right) {
    if (arr[merge_left] <= arr[merge_right]) {
      merge_arr[merge_i] = arr[merge_left];
      merge_left++;
    } else {
      merge_arr[merge_i] = arr[merge_right];
      merge_right++;
    }
    merge_i++;
  }

  while (merge_left <= mid) {
    merge_arr[merge_i] = arr[merge_left];
    merge_left++;
    merge_i++;
  }

  while (merge_right <= right) {
    merge_arr[merge_i] = arr[merge_right];
    merge_right++;
    merge_i++;
  }

  for (merge_i = 0; merge_i < len; merge_i++)
    arr[left + merge_i] = merge_arr[merge_i];

  delete[] merge_arr;
}

void merge_sort_rec(int *arr, int left, int right) {
  if (left >= right)
    return;
  int mid = (left + right) / 2;
  merge_sort_rec(arr, left, mid);
  merge_sort_rec(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

void merge_sort(int *arr, int len) { merge_sort_rec(arr, 0, len - 1); }

void quick_sort(int *arr, int len) { return; }

void radix_sort(int *arr, int len) { return; }

//
// main
//

void print_ints(int *ints, int len) {
  for (int i = 0; i < len; i++)
    cout << ints[i] << " ";
  cout << endl;
}

void process_arr(int *arr, int len) {
  cout << endl;

  int *a;

  print_ints(arr, len);

  cout << "bubble_sort" << endl;
  a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  bubble_sort(a, len);
  print_ints(a, len);

  cout << "selection_sort" << endl;
  a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  selection_sort(a, len);
  print_ints(a, len);

  cout << "insertion_sort" << endl;
  a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  insertion_sort(a, len);
  print_ints(a, len);

  cout << "merge_sort" << endl;
  a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  merge_sort(a, len);
  print_ints(a, len);

  cout << "quick_sort" << endl;
  a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  quick_sort(a, len);
  print_ints(a, len);

  cout << "radix_sort" << endl;
  a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  radix_sort(a, len);
  print_ints(a, len);
}

int main() {

  int arr1[] = {1, 5, 9, 2, 8, 3, 10, -40, 30, 100};
  int arr1_len = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
  int arr2_len = sizeof(arr2) / sizeof(arr2[0]);

  process_arr(arr1, arr1_len);
  process_arr(arr2, arr2_len);

  return 0;
}
