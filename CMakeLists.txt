cmake_minimum_required(VERSION 3.15)
project(cross_compile_learning
        VERSION 0.1.0
        DESCRIPTION 交叉编译学习)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-fPIC -Wall -Wextra -Wno-psabi)

message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
# message("CMAKE_SYSROOT: ${CMAKE_SYSROOT}")

set(DEFAULT_RUNPATH ${CMAKE_INSTALL_PREFIX}/lib)

add_subdirectory(src)

add_executable(cross_compile main.cpp)
target_link_libraries(cross_compile my_alg)
target_link_directories(cross_compile PUBLIC src)
target_include_directories(cross_compile PUBLIC ${CMAKE_SOURCE_DIR}/include)
set_target_properties(cross_compile PROPERTIES INSTALL_RPATH ${DEFAULT_RUNPATH})

install(
    TARGETS cross_compile my_alg
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
# set(CPACK_PACKAGE_NAME "cross-compile-learning")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "armhf")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "micah")
include(CPack)
