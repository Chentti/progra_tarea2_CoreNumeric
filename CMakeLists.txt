cmake_minimum_required(VERSION 3.29)
project(Tarea_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tarea_2 test_mean.cpp
        core_numeric.h
)
add_executable(Tarea_3 test_variance.cpp
        core_numeric.h
)
add_executable(Tarea_4 test_max.cpp
        core_numeric.h
)
add_executable(Tarea_5 test_transform_reduce.cpp
        core_numeric.h
)
add_executable(Tarea_6 test_variadic.cpp
        core_numeric.h
)
add_executable(Tarea_7 test_concepts.cpp
        core_numeric.h
)
