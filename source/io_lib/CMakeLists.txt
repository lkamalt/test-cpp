# Поддержка CMake не ниже указанной версии
cmake_minimum_required(VERSION 3.12)

project(IO_lib)

# Исходные файлы
set(SOURCE_FILES 
	tools.h
	tools.cpp
	csv_loader.h
	csv_loader.cpp
	bin_loader.h
	bin_loader.cpp
	bin_writer.h
	bin_writer.cpp
)

add_library(IO_lib STATIC ${SOURCE_FILES})