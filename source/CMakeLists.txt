# Поддержка CMake не ниже указанной версии
cmake_minimum_required(VERSION 3.12)

# Название проекта
set(PROJECT_NAME "cpp_test")
project(${PROJECT_NAME})
	
# Исходные файлы
set(SOURCE_FILES 
	main.cpp
	funcs.h
	funcs_test.h
	funcs_test.cpp
	test.h
	test.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/../libs/IO_lib.lib)