#include "../../Headers/Quick_Sort/Quick_Sort.h"

void Quick_Sort(int *intarr_Target, int Num) 
{ 

    Quick_Sorting(intarr_Target, 0, Num-1);

}

void Quick_Sorting(int *intarr_Target, int Left, int Right)
{
  if (Left < Right) {
    int Pivot = partition(intarr_Target, Left, Right);
    Quick_Sorting(intarr_Target, Left, Pivot - 1);
    Quick_Sorting(intarr_Target, Pivot + 1, Right);
  }
}

int partition(int *intarr_Target, int Left, int Right) 
{

  int i = Left - 1;
  int j;
  for (j = Left; j < Right; j++) {
    if (*(intarr_Target + j) <= *(intarr_Target + Right)) {
      i++;
      SWAP(intarr_Target + i, intarr_Target + j);
    }
  }

  SWAP(intarr_Target + i + 1, intarr_Target + Right);
  return i + 1;
}

void SWAP(int *A, int *B) 
{

  int Temp = *A;
  *A = *B;
  *B = Temp;

  return;
}