cmake_minimum_required(VERSION 3.5.0)
project(BreakOut VERSION 0.1.1 LANGUAGES NONE)


#C++ settings 
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})

#set src folders
add_subdirectory(core)

#setting names

set (PROJECT_EXEC_NAME ${PROJECT_NAME}_game)

#Program settings
add_executable(${PROJECT_EXEC_NAME} Source.cpp)

#Tests Executable
#add_executable(AsyncCalcTests tests.cpp)
set(CORE_PATH ${PROJECT_SOURCE_DIR}/core)


target_include_directories(${PROJECT_EXEC_NAME} PRIVATE ${CORE_PATH}/include)

#configuration files


target_link_libraries(${PROJECT_EXEC_NAME} Engine)

#GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# set test name
set (PROJECT_TEST_NAME ${PROJECT_NAME}_test)

add_executable(
  ${PROJECT_TEST_NAME}
  SourceTests.cpp
)

# linking 
target_link_libraries(
  ${PROJECT_TEST_NAME}
  GTest::gtest_main
)

target_include_directories(${PROJECT_TEST_NAME} PRIVATE ${CORE_PATH}/include)
target_link_libraries(${PROJECT_TEST_NAME} Engine)

include(GoogleTest)
gtest_discover_tests(${PROJECT_TEST_NAME})