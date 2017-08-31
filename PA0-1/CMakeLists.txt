cmake_minimum_required (VERSION 2.6)
project (solver)

# setting variables
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMakeModules")
set (CXX11_FLAGS --std=gnu++11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS}")


# add include 
include_directories ("${PROJECT_SOURCE_DIR}/include")

# add sources
file (GLOB_RECURSE SOURCES "src/*.cpp")

add_executable (${PROJECT_NAME} ${SOURCES})

add_custom_target ("${PROJECT_NAME}_SUCCESSFUL" ALL
                  DEPENDS ${PROJECT_NAME}
                  COMMAND ${CMAKE_COMMAND} -E echo ""
                  COMMAND ${CMAKE_COMMAND} -E echo "====================="
                  COMMAND ${CMAKE_COMMAND} -E echo "  Compile complete!"
                  COMMAND ${CMAKE_COMMAND} -E echo "====================="
                  COMMAND ${CMAKE_COMMAND} -E echo "${CMAKE_CURRENT_BINARY_DIR}"
                 )
