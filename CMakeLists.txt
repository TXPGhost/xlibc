cmake_minimum_required(VERSION 3.10)
project(xlibc C)

# Include header files
include_directories(include)

# Globbing source files
file(GLOB SOURCES "src/*.c")

# Add executable target
add_library(xlibc STATIC ${SOURCES})

# Set installation directory for headers
set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME})

# Install headers
file(GLOB HEADERS "include/*.h")
install(FILES ${HEADERS} DESTINATION ${INSTALL_INCLUDE_DIR})

# Install library
install(
  TARGETS xlibc
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
