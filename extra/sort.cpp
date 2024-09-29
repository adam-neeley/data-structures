
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

void merge_sort(int *arr, int len) { return; }

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
