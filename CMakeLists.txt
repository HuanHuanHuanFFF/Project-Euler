cmake_minimum_required(VERSION 3.30)
project(Project_Euler LANGUAGES CXX)

# 要求 C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 收集所有源文件
file(GLOB_RECURSE PROJECT_SOURCES
        "${CMAKE_SOURCE_DIR}/*.cpp"
)

# 可执行目标
add_executable(Project_Euler ${PROJECT_SOURCES})

# 确保使用 C++23
target_compile_features(Project_Euler PUBLIC cxx_std_23)

# 根据不同配置添加编译选项
# Debug 模式只加 -g，不加 -O2
# Release 模式加 -O2 并关闭断言（-DNDEBUG）
target_compile_options(Project_Euler PRIVATE
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Release>:-O2;-DNDEBUG>
)
