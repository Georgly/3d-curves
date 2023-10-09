cmake_minimum_required(VERSION 3.16)
project(3d-curves)

add_executable(${PROJECT_NAME} 
    curve.hpp
    utils.h
    curve_generator.h
    main.cpp
    utils.cpp
    curve_generator.cpp)
