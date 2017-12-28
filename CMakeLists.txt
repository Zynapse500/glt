
cmake_minimum_required(VERSION 2.8.4)

project(GLT)


option(GLT_BUILD_EXAMPLES "Build examples" ON)


add_library(glt
        include/glt.hpp
        include/vec/vec.hpp include/vec/vec_core.hpp
        include/vec/vec2.hpp include/vec/vec3.hpp include/vec/vec4.hpp
        )

set_target_properties(glt PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(glt PUBLIC "include")



if (GLT_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
