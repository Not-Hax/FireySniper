# Utility
add_library(utility STATIC Utility.cpp)
target_include_directories(utility PUBLIC ${INCLUDE_DIR})

# System
add_library(system STATIC System.cpp)
target_include_directories(system PUBLIC ${INCLUDE_DIR})