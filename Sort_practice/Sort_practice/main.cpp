#include <iostream>
//const int MAX_N = 100;
//int n;
//int arr[MAX_N];

using namespace std;
int sorted[1000000+1];
int arr[1000000+1];
int num;

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    // 작은 순서대로 배열에 삽입
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }
    // 남은 데이터도 삽입
    if(i > mid) {
        for(int t = j; t<= right; t++) {
            sorted[k++] = arr[t];
        }
    }
    else {
        for(int t = i; t<= mid; t++) {
            sorted[k++] = arr[t];
        }
    }
    // 정렬된 배열 삽입
    for(int t = left; t<= right; t++) {
        arr[t] = sorted[t];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    for (int i=0; i<num; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, num-1);
    for (int i=0; i<num; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// 퀵정렬은 이미 정렬된 상태에선 최악의 시간복잡도 N^2!!
void quickSort(int *arr, int start, int end) {
    if(start >= end) { // 원소가 한개인 경우
        return;
    }
    
    int key = start; // 키 = 피벗값.
    int i = start + 1, j = end, tmp;
    
    while (i <= j) { // 엇갈릴때까지
        while (arr[i] <= arr[key]) { // 키값보다 큰값을 만날 때 까지.
            i++;
        }
        while (arr[j] >= arr[key] && j > start) { // 키보다 작은값을 만날 때 까지
            j--;
        }
        if (i > j) { // 현재 엇갈린 상태면 키값과 교체
            tmp = arr[j];
            arr[j] = arr[key];
            arr[key] = tmp;
        }
        else { // 큰 작은 스왑
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    
    //키값 기준으로 왼쪽과 오른쪽에서 다시 퀵정렬 수행
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}
