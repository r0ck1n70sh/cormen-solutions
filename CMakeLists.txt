cmake_minimum_required (VERSION 3.13)

project (cormen-solutions)

set (CHAPTER_NO "chapter_04")
set (CHAPTER "${CMAKE_CURRENT_SOURCE_DIR}/${CHAPTER_NO}")
set (PROBLEM "4.1-3")
add_executable (main "${CHAPTER}/${PROBLEM}/main.c")

set (lib_name "max_sum_subarr")
set (lib "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set (src "${CMAKE_CURRENT_SOURCE_DIR}/src/${CHAPTER_NO}")

# debug
set (CMAKE_BUILD_TYPE Debug)

target_include_directories (main PUBLIC "${lib}")
target_sources (main PUBLIC "${src}/${lib_name}.c")
