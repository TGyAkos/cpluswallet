cmake_minimum_required(VERSION 3.27)
project(cpluswallet)

set(CMAKE_CXX_STANDARD 20)
# To make it standalone
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(cpluswallet main.cpp
        src/utils/parseFile.cpp
        src/utils/parseFile.h
        src/data/data.h
        src/utils/expenseWrapper.cpp
        src/utils/expenseWrapper.h
        src/utils/uiDisplay.cpp
        src/utils/uiDisplay.h
        src/utils/convert.cpp
        src/utils/convert.h
        src/data/data.cpp
        src/runtime/run.cpp
        src/runtime/run.h
)

# download gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#create_test_sourcelist (Tests gtest_main.cpp
#tests/main_test.cpp
#tests/test.cpp
#)

add_executable(cpluswallet_tests tests/main_test.cpp
    tests/test.cpp
)

#set(TestsToRun ${Tests})
#list(REMOVE_ITEM TestsToRun tests/gtest_main.cpp)

target_link_libraries(cpluswallet_tests gtest_main)

enable_testing()

#foreach (oneTest ${TestsToRun})
#    get_filename_component(TName ${oneTest} NAME_WE)
    add_test(NAME Default COMMAND cpluswallet_test)
#endforeach ()

