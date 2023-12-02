cmake_minimum_required(VERSION 3.23.2)
project(Discrete_Math)

set(CMAKE_CXX_STANDARD 17)

add_library(
        alg
        alg/alg.cpp
        alg/alg.h
)

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
        lab3.3/SetFactor.cpp
        lab3.3/SetFactor.h
)


add_library(
        OrderedSet
        lab3.4/OrderedSet.cpp
        lab3.4/OrderedSet.h
)

add_library(
        Graph
        lab4.1/Graph.cpp
        lab4.1/Graph.h
)

add_library(
        GraphCheck
        lab4.2/GraphCheck.cpp
        lab4.2/GraphCheck.h
)

add_library(
        Kruskal
        lab4.3/Kruskal.cpp
        lab4.3/Kruskal.h
)

add_library(
        test
        test/test.cpp
        test/test.h
)

add_executable(
        Discrete_Math
        main.cpp
)

target_link_libraries(
        Discrete_Math
        test
        alg
        Relation
        TransitivityClosureExperiment
        SetFactor
        OrderedSet
        Graph
        GraphCheck
        Kruskal
)