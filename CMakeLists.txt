cmake_minimum_required(VERSION 3.10.2)
project(signal_handler)

# Using C++17
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# stop build on first error
string(APPEND CMAKE_CXX_FLAGS " -Wfatal-errors")

#
# Dependendies
#

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

#
# Library
#

add_library(${PROJECT_NAME} SHARED src/signal_handler.cpp src/exceptions.cpp)
# Add the include dependencies
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                         $<INSTALL_INTERFACE:include>)
# Export the target.
ament_export_interfaces(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
list(APPEND all_targets ${PROJECT_NAME})
list(APPEND all_target_exports export_${PROJECT_NAME})

#
# Demo
#

add_executable(demo_signal_handler demos/demo.cpp)
# save the name for installation
set(all_targets ${all_targets} demo_signal_handler)
# dependencies
target_include_directories(
  demo_signal_handler
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>)
target_link_libraries(demo_signal_handler ${PROJECT_NAME})
install(TARGETS demo_signal_handler RUNTIME DESTINATION lib/${PROJECT_NAME})

#
# Install and export
#

install(DIRECTORY include/ DESTINATION include)
install(
  TARGETS ${all_targets}
  EXPORT ${all_target_exports}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)
ament_package()
