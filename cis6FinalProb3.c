/**
 *Program Name:  cis6FinalProb3.c
 *Discussion:    Arrays & Sorting
 *Written By:    Scott Kinney
 *Date:          Tue May 28 13:18:45 PDT 2013
 */
#include <stdio.h>
#define MAX 10

// Function Prototypes
void displayMenu(void);
void extractLargestDigit(void);
int* isLargestDigit(int [], int [], int, int);
void sort(int [], int);
void printAry(int [], int);

int main() {
  int opt, input1, input2, largest, inInput1, inInput2 = 0;

 do {
    displayMenu();
    printf("Enter your option (1 or 2): ");
    scanf("%d", &opt);

    if (opt == 1) {
      
      extractLargestDigit();

    } else if (opt == 2) {
      printf("\n  Have fun\n\n");    

    } else {
      printf("\n  WRONG OPTION\n\n");
    }
  } while (opt != 2);

  return 0;
} //  END of MAIN

// Function Definitions
void extractLargestDigit(void) {
  int temp; 
  int largest = 0;
  int inputAry[MAX + 2] = {0};
  int largestAry[100] = {0};
  int inAry[MAX + 2] = {0};
  int largestArySize;
  int i, j;
  int size;
  int factor = 1;
  int in;
  
  // how many numbers are we working with (size of inputAry)
  printf("    How many ints to work on: ");
  scanf("%d", &size);
  
  // read numbers into inputAry
  for (i = 0; i < size; i++) {
    printf("int %d\n", i + 1);
    scanf("%d", &inputAry[i]);
  }

  // store digits into largestAry 
  j = 1;
  for (i = j - 1; i < size; i++) {
    factor = 1;
    while ((inputAry[i] / factor) != 0) {
      largestAry[j] = inputAry[i] / factor % 10;
      if (largestAry[j] < 0)
	largestAry[j] = -largestAry[j];
      factor *= 10;
      j++;
    }
  }
  
  largestArySize = j;
 
  printf(" size = %d\n", j);
  printf("before sort\n");
  printAry(largestAry, largestArySize);
  sort(largestAry, largestArySize);
  printf("\nafter sort\n");
  printAry(largestAry, largestArySize);

  largest = largestAry[1];

  isLargestDigit(inputAry, inAry, largest, size);
  
  printf("\nin = %d\n", in);
  printf("\nThe largest digit: %d\n", largest);

}

void sort(int ary[], int n) {
  int a;
  int i, j;
  
  // straight insertion 
  for (j = 2; j < n; j++) {
    a = ary[j];
    i = j - 1;
    while (i >  0 && ary[i] < a) {
      ary[i + 1] = ary [i];
      i--;
    }
    ary[i + 1] = a;
  }
}

int* isLargestDigit(int inputAry[], int inAry[], int largest, int size) {
  int i;
  int j;
  int temp;
  int factor = 1;
  int in = 0;
  int count = 0;

  for (i = 0; i < size; i++) {
    while ((inputAry[i] / factor % 10) != 0) {
      if (inputAry[i] / factor % 10 == largest) {
	inAry[i] = 1;
	count++;
      }
      else {
	factor *= 10;
      }
    }
  }
  
  printAry(inAry, count);
  return inAry;
}

void printAry(int ary[], int size) {
  int i;
  
  for (i = 1; i < size; i++)
    printf(" %d ", ary[i]);
}

void displayMenu(void) {
  printf("MENU:\n");
  printf("  (1) Get largest digit information\n");
  printf("  (2) Quit\n");
}
