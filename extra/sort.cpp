
#include <iomanip>
#include <iostream>

using namespace std;

typedef void (*v_sort)(int *arr, int len);

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

void shell_sort(int *arr, int len) { return; } // TODO

void merge(int *arr, int left, int mid, int right) {
  int len = right - left + 1;
  int *a = new int[len];
  int i = 0;
  int l = left;
  int r = mid + 1;

  while (l <= mid && r <= right)
    if (arr[l] <= arr[r])
      a[i++] = arr[l++];
    else
      a[i++] = arr[r++];

  while (l <= mid)
    a[i++] = arr[l++];

  while (r <= right)
    a[i++] = arr[r++];

  for (i = 0; i < len; i++)
    arr[left + i] = a[i];

  delete[] a;
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

int partition(int *arr, int left, int right, int pivot) {
  int i = left;
  int j = left;

  while (i <= right)
    if (arr[i] > pivot)
      i++;
    else
      swap(arr[i++], arr[j++]);

  return j - 1;
}

void quick_sort_rec(int *arr, int left, int right) {
  if (left < right) {
    int pivot = arr[right];
    int pos = partition(arr, left, right, pivot);
    quick_sort_rec(arr, left, pos - 1);
    quick_sort_rec(arr, pos + 1, right);
  }
}

void quick_sort(int *arr, int len) { quick_sort_rec(arr, 0, len - 1); }

void radix_sort(int *arr, int len) {
  int exp = 1;
  int max = arr[0];

  // find max
  for (int i = 1; i < len; i++)
    if (arr[i] > max)
      max = arr[i];

  while (max / exp > 0) {
    int *radix_arr = new int[10];
    for (int i = 0; i < 10; i++) {
      int num = radix_arr[i];
      radix_arr[(num / exp) % 10] = num;
    }

    // for (int i = 0; i < 10; i++) { // TODO
    //   int num = radix_arr[i];
    //   radix_arr[(num / exp) % 10] = num;
    // }

    exp *= 10;
  }

  return;
  //
}

//
// main
//

void print_ints(int *ints, int len) {
  for (int i = 0; i < len; i++)
    cout << right << ints[i] << " ";
}

void process_sort(string sort_name, v_sort sort_call, int *arr, int len) {
  cout << endl;
  cout << setw(10) << sort_name << ": ";
  int *a = new int[len];
  for (int i = 0; i < len; i++)
    a[i] = arr[i];
  sort_call(a, len);
  print_ints(a, len);
}

void process_arr(int *arr, int len) {
  cout << endl
       << setw(10) << "array"
       << ": ";

  print_ints(arr, len);

  process_sort("bubble", bubble_sort, arr, len);
  process_sort("selection", selection_sort, arr, len);
  process_sort("insertion", insertion_sort, arr, len);
  process_sort("shell", shell_sort, arr, len);
  process_sort("merge", merge_sort, arr, len);
  process_sort("quick", quick_sort, arr, len);
  process_sort("radix", radix_sort, arr, len);

  cout << endl;
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
