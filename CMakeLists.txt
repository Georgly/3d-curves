cmake_minimum_required(VERSION 3.16)
project(3d-curves)

add_executable(${PROJECT_NAME} 
    curve.hpp
    utils.hpp
    curve_generator.hpp
    main.cpp
    utils.cpp)
