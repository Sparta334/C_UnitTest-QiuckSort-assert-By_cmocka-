# C_UnitTest-QiuckSort-assert-By_cmocka-
###### 學習C的單元測試，使用cmocka，第一個範例斷言，stub
###### 測試範例 快速排序

## 目錄


## 檔案結構
```
C:.
│  .gitignore
│  CMakeLists.txt
│  list.txt
│  Main.c
│  
├─Algorithm
│  │  CMakeLists.txt
│  │  
│  ├─Headers
│  │  └─Quick_Sort
│  │          Quick_Sort.h
│  │          
│  └─Sources
│      │  CMakeLists.txt
│      │  
│      └─Quick_Sort
│              CMakeLists.txt
│              Quick_Sort.c
│              
├─Build
│  └─CMakeFiles
│      ├─3.26.4
│      │  ├─CompilerIdC
│      │  │  └─tmp
│      │  └─CompilerIdCXX
│      │      └─tmp
│      ├─CMakeScratch
│      └─pkgRedirects
└─Test
    │  CMakeLists.txt
    │  Main.c
    │  
    ├─Headers
    │      Header.h
    │      Test_QuickSort.h
    │      
    └─Sources
            Test_QuickSort.c
```


## Build

* **Step 1** 使用建立Build資料夾
> 必須在專案建立Build資料夾，讓cmake產生的東西在裡面  

* **Step 2** 切換到專案資料夾
```shell
cd Build
```
  
* **Step 3** cmake指令
> 尋找根目錄的CMakeLists.txt
```shell
cmake ..
```

* **Step 4** make
> 執行Build底下的Makefile
```shell
make
```


>生成完畢

## CMake 語法
>基本該加
```CMake

cmake_minimum_required(VERSION 3.16)
project(QUICKSORT LANGUAGES C CXX)

# C = C lauguage / CXX = C++
#setting standard liberary, C 
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#setting standard liberary, C++
set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

```

>接下來如果要使用專案底下的某個資料夾
```CMake
add_subdirectory( 資料夾名 )
```
**並保證目標資料夾裡有另一個CMakeLists.txt**

>接著如果你目標資料夾裡有.c要加入
>>假設為 Quick_Sort.c
```CMake
add_library(QSort 
	Quick_Sort.c
)
```
>標頭檔引入
```CMake
target_include_directories(QSort  PUBLIC ../../Headers/Quick_Sort )
```

## 生成Unit Test的執行檔

>生成執行檔的CMakeLists.txt
**檔名叫Test.exe**
```CMake
add_executable(Test

    ./Main.c
    ./Sources/Test_QuickSort.c

)

target_include_directories(Test PUBLIC ./Headers)
```

>加入Library
**用到剛剛的取名 QSort 的Library**
**cmocka 是單元測試的Library**
```CMake
target_link_libraries(Test

    QuickSortMain
    cmocka
    QSort
)
```

# cmocka 語法
## 引入 cmocka
```c
#pragma once
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
```

## Main.c
**在CMUnitTest tests宣告需要測試的function**<br>
**這裡只測試 test_QiuckSort**<br>
```c
const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_QiuckSort),
};

int main(void) {

    return cmocka_run_group_tests(tests, NULL, NULL);
}
```

## test_QiuckSort 定義
**這裡直接預測數值 Data_Sorted 是答案**<br>
**intarr2str 是把陣列轉成字串**<br>
**使用assert_string_equal( A , B ) 確認A、B 相不相等，即單元測試**<br>

```c
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
```
