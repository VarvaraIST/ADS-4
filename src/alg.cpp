// Copyright 2026 NNTU-CS
#include "alg.h"

int countPairs1(int* arr, int len, int value) {
    int countNum = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                countNum++;
            }
        }
    }

    return countNum;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int leftArr = 0;
    int rightArr = len - 1;

    while (leftArr < rightArr) {
        int sum = arr[leftArr] + arr[rightArr];

        if (sum == value) {
            if (arr[leftArr] == arr[rightArr]) {
                int n = rightArr - leftArr + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftCount = 1;
                while (leftArr + 1 < rightArr && arr[leftArr] == arr[leftArr + 1]) {
                    leftCount++;
                    leftArr++;
                }

                int rightCount = 1;
                while (rightArr - 1 > leftArr && arr[rightArr] == arr[rightArr - 1]) {
                    rightCount++;
                    rightArr--;
                }

                count += leftCount * rightCount;
                leftArr++;
                rightArr--;
            }
        } else if (sum < value) {
            leftArr++;
        } else {
            rightArr--;
        }
    }

    return count;
}

int countPairs3(int* arr, int len, int value) {
    int per = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int need = value - arr[i];
        if (need < arr[i]) {
            break;
        }
        int low = i + 1;
        int high = len - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == need) {
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < need) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (first == -1) {
            continue;
        }
        low = first;
        high = len - 1;
        int last = first;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == need) {
                last = mid;
                low = mid + 1;
            } else if (arr[mid] < need) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (arr[i] == need) {
            int len = last - i + 1;
            per = per + len * (len - 1) / 2;
            break;
        }
        int leftCnt = 1;
        while (i + leftCnt < len && arr[i + leftCnt] == arr[i]) {
            leftCnt++;
        }
        per = per + leftCnt * (last - first + 1);
    }
    return per;
}
