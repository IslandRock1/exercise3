cmake_minimum_required(VERSION 3.31)
project(exercise3)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        pugixml
        GIT_REPOSITORY https://github.com/zeux/pugixml.git
        GIT_TAG   e86ffc5b47bb42e94b57b3e39d8ef5ac4870ef77
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG   e181e941409a350a93aaea92187f9ba9071a5d09
)
FetchContent_MakeAvailable(pugixml fmt)

add_executable(exercise3 main.cpp)
target_link_libraries(exercise3 PRIVATE pugixml fmt)
target_compile_definitions(exercise3 PRIVATE DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
