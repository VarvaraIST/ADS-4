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
    int left = 0;
    int right = len - 1;
    int per = 0;
    while (left < right) {
        int currSum = arr[left] + arr[right];
        if (currSum == value) {
            if (arr[left] == arr[right]) {
                int llen = right - left + 1;
                per = per + llen * (llen - 1) / 2;
                break;
            }
            int leftVal = arr[left];
            int rightVal = arr[right];
            int indx = left;
            int leftCount = 0;
            while (indx <= right && arr[indx] == leftVal) {
                leftCount++;
                indx++;
            }
            indx = right;
            int rightCount = 0;
            while (indx >= left && arr[indx] == rightVal) {
                rightCount++;
                indx--;
            }
            per = per + leftCount * rightCount;
            left = left + leftCount;
            right = right - rightCount;
        }
        else if (currSum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return per;   
}

int countPairs3(int* arr, int len, int value) {
    int per = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int ne = value - arr[i];
        if (ne < arr[i]) {
            break;
        }
        int low = i + 1;
        int high = len - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == ne) {
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < ne) {
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
            if (arr[mid] == ne) {
                last = mid;
                low = mid + 1;
            } else if (arr[mid] < ne) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (arr[i] == ne) {
            int lLen = last - i + 1;
            per = per + lLen * (lLen - 1) / 2;
            break;
        }
        int leftCount = 1;
        while (i + leftCount < len && arr[i + leftCount] == arr[i]) {
            leftCount++;
        }
        per = per + leftCount * (last - first + 1);
    }
    return per;
}
