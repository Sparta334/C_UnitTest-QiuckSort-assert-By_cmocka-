#include "../Headers/Test_QuickSort.h"


void test_QiuckSort(void** state){

     int Data_Need_Sort[10] = { 9 , 23 , 13 , 45 , 1 , 8 , 3 , 15 , 99 , 30 };
     int Data_Sorted[10] = { 1 , 3 , 8 , 9 , 13 , 15 , 23 , 30 , 45 , 99};
     char Result[100] = "1,3,8,9,13,15,23,30,45,99,\0";

    

     char Test_itoa[100];   // test Data_Sorted  equal Result  or not

     char TarsResult[100];  //Data_Need_Sort to string

     intarr2str(Test_itoa, Data_Sorted, 10);

     assert_string_equal(Test_itoa , Result );

     // Start Sort

     Quick_Sort(Data_Need_Sort, 10);
     intarr2str(TarsResult, Data_Need_Sort , 10);

     assert_string_equal(TarsResult , Result );


}


void intarr2str(char* output, int* intarr_Source , int Num ){

    strcpy(output , "");
    int Strlen = 0;

    for(int i = 0 ; i< Num ;i++){
        char str[10];
        itoa(*(intarr_Source+i),str,10);
        strcat(output ,str );
        strcat(output,",");
        Strlen+=(int)strlen(str);
        Strlen+=1;

    } 

    output[Strlen] = '\0';

}