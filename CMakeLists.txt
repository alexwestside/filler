cmake_minimum_required(VERSION 3.6)

project(filler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c filler.h sub.c valid_type.c init_write.c)

add_executable(filler ${SOURCE_FILES})

target_link_libraries(filler ${CMAKE_SOURCE_DIR}/libft/libft.a)