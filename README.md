# C_UnitTest-QiuckSort-assert-By_cmocka-
###### 學習C的單元測試，使用cmocka，第一個範例斷言，stub
###### 測試範例 快速排序

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


