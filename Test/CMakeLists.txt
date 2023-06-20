add_executable(Test

    ./Main.c
    ./Sources/Test_QuickSort.c

)

target_include_directories(Test PUBLIC ./Headers)

target_link_libraries(Test

    QuickSortMain
    cmocka
    QSort
)