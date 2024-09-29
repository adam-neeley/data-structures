
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

void bubble_sort(int *arr, int arr_len) {
  for (int i = 0; i < arr_len - 1; i++)
    for (int j = i + 1; j < arr_len; j++)
      if (arr[i] > arr[j])
        swap(arr[i], arr[j]);
}

void selection_sort(int *arr, int arr_len) {
  for (int i = 0; i < arr_len - 1; i++) {
    int min = i;
    for (int j = i + 1; j < arr_len; j++)
      if (arr[min] > arr[j])
        min = j;
    if (min != i)
      swap(arr[i], arr[min]);
  }
}

void insertion_sort(int *arr, int arr_len) {
  for (int i = 1; i < arr_len; i++)
    for (int j = i; j > 0; j--)
      if (arr[j - 1] > arr[j])
        swap(arr[j - 1], arr[j]);
}

//
// main
//

void print_ints(int *ints, int arr_len) {
  for (int i = 0; i < arr_len; i++)
    cout << ints[i] << " ";
  cout << endl;
}

void process_arr(int *arr, int arr_len) {
  cout << endl;

  int *a;

  print_ints(arr, arr_len);

  cout << "bubble_sort" << endl;
  a = new int[arr_len];
  for (int i = 0; i < arr_len; i++)
    a[i] = arr[i];
  bubble_sort(a, arr_len);
  print_ints(a, arr_len);

  cout << "selection_sort" << endl;
  a = new int[arr_len];
  for (int i = 0; i < arr_len; i++)
    a[i] = arr[i];
  // print_ints(a, arr_len);
  selection_sort(a, arr_len);
  print_ints(a, arr_len);

  cout << "insertion_sort" << endl;
  a = new int[arr_len];
  for (int i = 0; i < arr_len; i++)
    a[i] = arr[i];
  // print_ints(a, arr_len);
  insertion_sort(a, arr_len);
  print_ints(a, arr_len);
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
