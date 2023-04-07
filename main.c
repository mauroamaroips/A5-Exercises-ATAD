#include <stdio.h> 
#include <stdlib.h>
#include "input.h"

/* protótipos de funções */

//Recursividade - 1
int sumGreaterThanIt(int arr[], int arrLength, int threshold);
int sumGreaterThanRec(int arr[], int arrLength, int threshold);

//Recursividade - 2
int max(int a, int b);
int largestElementIt(int arr[], int arrLength);
int largestElementRec(int arr[], int arrLength);

//Recursividade - 3

int manyDigitsIt(unsigned int number);
int manyDigitsRec(unsigned int number);

// Recursividade - 4
int fibonacciIt(int num);
int fibonacciRec(int num);

int main() {

int values[] = {19, 30, 4, 49, 21, 32, 12, 37, 8, 28};
int arrSize = 10;
int thresholdValue = 1;

/* Invocação de funções... */

// Recursividade - 1
int sumGreaterIt = sumGreaterThanIt(values, arrSize, thresholdValue);
printf("Sum greater than threshold (iterative): %d\n", sumGreaterIt);

int sumGreaterRec = sumGreaterThanRec(values, arrSize, thresholdValue);
printf("Sum greater than threshold (recursive): %d\n", sumGreaterRec);

// Recursividade - 2
int maxNumIt = largestElementIt(values, arrSize);
printf("Maximum number on array (iterative): %d\n", maxNumIt);

int maxNumRec = largestElementRec(values, arrSize);
printf("Maximum number on array (recursive): %d\n", maxNumRec);

// Recursividade - 3

 unsigned int digitsNum = 2452;

 int numDigitsIt = manyDigitsIt(digitsNum);
 printf("Number of digits (iterative): %d\n", numDigitsIt);

 int numDigitsRec = manyDigitsRec(digitsNum);
 printf("Number of digits (recursive): %d\n", numDigitsRec);

 // Recursividade - 4

int fibIt = fibonacciIt(5);
printf("Fibonacci result (iterative): %d\n", fibIt);
int fibRec = fibonacciRec(5);
printf("Fibonacci result (iterative): %d\n", fibRec);



return EXIT_SUCCESS;

}



/* Implementação de funções... */

// Recursividade - 1 (Iterativamente)

int sumGreaterThanIt(int arr[], int arrLength, int threshold){

    int sum = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if(arr[i] > threshold){
            sum += arr[i];
        }
    }

    return sum;
    
}

// Recursividade - 1 (Recursivamente)

int sumGreaterThanRec(int arr[], int arrLength, int threshold){

    int sum = 0;

    if(arrLength <= 0) return -1;
    else if(arrLength == 1) return arr[0];

    if(arr[arrLength-1] > threshold){
        sum += arr[arrLength-1];
    }
    
    return sum + sumGreaterThanRec(arr, arrLength-1, threshold);

}

// Recursividade - 2 (Função auxiliar)

int max(int a, int b){

    if (a > b) return a;
    return b;
}

// Recursividade - 2 (Iterativamente)

int largestElementIt(int arr[], int arrLength){

    int maxNum = 0;

    for (int i = 0; i < arrLength; i++){
     maxNum = max(maxNum, arr[i]);
    }
    
    return maxNum;
}

// Recursividade - 2 (Iterativamente)

int largestElementRec(int arr[], int arrLength){

    if(arrLength <= 0) return -1;
    else if(arrLength == 1) return arr[0];

    return max(arr[arrLength - 1], largestElementRec(arr, arrLength - 1));

}

// Recursividade - 3 (Iterativamente)

int manyDigitsIt(unsigned int number){

    int numDigits = 0;
    
    do
    {
        number = number / 10;
        numDigits++;

    } while (number != 0);

    return numDigits;
    
}

// Recursividade - 3 (Recursivamente)

int manyDigitsRec(unsigned int number){

    int numDigits = 0;

    if(number == 0) return numDigits++;

    numDigits++;

    return numDigits + manyDigitsRec(number/10);

}

// Recursividade - 4 (Iterativamente)

int fibonacciIt(int num) {

  int first = 0;
  int second = 1;
  int result = 0;

  for (int i = 0; i <= num; i++) {
    if (i <= 1)  {
      result = i;
    }
    else {
      result = first + second;
      first = second;
      second = result;
    }
  }
  return result;

}

// Recursividade - 4 (Recursivamente)

int fibonacciRec(int num){

  if (num <= 0)
    return 0;
  else if (num == 1)
    return 1;
  else
    return fibonacciRec(num - 1) + fibonacciRec(num - 2);

}

// Reposta às questões da pergunta 4

/* • Mais fácil ou díficil de exprimir a solução?
    R: É mais fácil exprimir a solução de forma recursiva. */

/* • Mais fácil ou díficil de exprimir a solução?
    R: A complexidade algorítimica é de O(n) */

/* Como avalia o balanço entre a dificuldade de implementação versus a eficiência algorítmica? Vale a pena?
   R: Vale a pena pois enquanto a complexidade algorítmica da solução iterativa é linear - O(n),
   a complexidade algorítimica da solução recursiva é exponencial - O (2^n).*/



