#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool almostIncreasingSequence(int *sequence) {
    bool isAscending = false;
    int loopStep = 0;
    int seqLen = 5;

    if(seqLen == 2) return true; // if array has 2 arguments, removing one always makes it ascending

    while(loopStep < seqLen) {
    	int checkAscendedPairCount = 0;
    	printf("Entering while with loopStep: %d\n", loopStep);
        if(!isAscending) {
            for(int i = 1; i < seqLen; i++) {
                if(loopStep == i - 1) {
        			if(i - 1 == 0) continue; // if loopstep is on first member
        			if(i == seqLen - 1) break; // if loopstep is on last member

                    if(sequence[i - 1] >= sequence[i + 1]) {
                        ++loopStep;
                        printf("[loopstep == i] case is not in ascending order on i: %d\n", i);
                        break;
                    } else {
                    	printf("[loopstep == i] case is in ascending order on i: %d.\n", i);
                        ++i;
                    }
                } else if(sequence[i - 1] >= sequence[i]) {
                    printf("[loopstep != i] case is not ascending entered with i: %d.\n", i);
                    ++loopStep;
                    break;
                }
                if(++checkAscendedPairCount == seqLen - 2) {
                	isAscending = true;
                	break;
                }
                printf("For loop iteration currently on i: %d and checkAscendedPairCount: %d\n", i, checkAscendedPairCount);
            }
            printf("Out of for loop\n");
        } else break;
        loopStep++;
    }

    return isAscending;
}

int matrixElementsSum(int matrix[][4]) {
    int sum = 0, i = 0;
    SKIP_ZERO:while(i++ < 3) {
        for(int j = 0; j < 4; j++) {
            if(!matrix[j][i]) goto SKIP_ZERO;
            sum += matrix[j][i];
        }
    }
    
    return sum;
}

int allLongestStrings(char inputArray[][4]) {
    size_t largestSize = 0; //int outerIndex = 0;
    //arr_string buffArray;
    
    for(int i = 0; i < 5; i++) { // find the largest size of a string
    	printf("%s %lu\n", inputArray[i], strlen(inputArray[i]));
        if(sizeof(inputArray[i]) > largestSize) largestSize = strlen(inputArray[i]);
    }

    return largestSize;
    
    // for(int i = 0; i < inputArray.size; i++) {
    //     if(strlen(inputArray.arr[i]) == largestSize) {
    //         buffArray.arr[outerIndex] = inputArray.arr[i];
    //         outerIndex++;
    //     }
    // }
    
    // return buffArray;
}

int main(void) {
  // int arr1[8] = {10, 1, 2, 3, 4, 5, 6, 1};
  // int arr2[5] = {1, 2, 5, 3, 5};
  // int arr3[2] = {1, 1};

//  int mat1[3][4] = {{0, 1, 1, 2}, {0, 5, 0, 0}, {2, 0, 3, 3}};
	char strArr[5][4] = {"aba", "aa", "ad", "vcd", "aba"};
//  printf(almostIncreasingSequence(arr2) ? "true\n" : "false\n");
//  printf("%d\n", matrixElementsSum(mat1));
	printf("%d\n", allLongestStrings(strArr));
  return 0;
}
