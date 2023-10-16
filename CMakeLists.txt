cmake_minimum_required(VERSION 3.24)
project(Discrete_Math)

set(CMAKE_CXX_STANDARD 17)

add_library(
        Relation
        lab3.1/Relation.cpp
        lab3.1/Relation.h
)

add_library(
        TransitivityClosureExperiment
        lab3.2/TransitivityClosureExperiment.cpp
        lab3.2/TransitivityClosureExperiment.h
)

add_library(
        SetFactor
        lab3.3/Set_Factor.cpp
        lab3.3/Set_Factor.h
)

add_executable(
        Discrete_Math
        main.cpp
)

target_link_libraries(
        Discrete_Math
        Relation
        TransitivityClosureExperiment
        SetFactor
)