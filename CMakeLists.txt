cmake_minimum_required(VERSION 3.1)
project(signal_handler)

# Specify C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# stop build on first error
string(APPEND CMAKE_CXX_FLAGS " -Wfatal-errors")


find_package(catkin REQUIRED)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES signal_handler
#  CATKIN_DEPENDS
#  DEPENDS
)

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
    src/signal_handler.cpp
    src/exceptions.cpp
)
target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES}
)


# Demo
add_executable(signal_handler_demo
    demos/demo.cpp
)
target_link_libraries(signal_handler_demo
    ${catkin_LIBRARIES}
    signal_handler
)

#############
## Install ##
#############

# Mark libraries for installation
# See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

# Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
    FILES_MATCHING PATTERN "*.h"
)

# Mark executables for installation
install(TARGETS signal_handler_demo
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

