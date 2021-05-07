add_executable(main main.cpp)
target_link_libraries(main bot)
                      
target_include_directories(main PUBLIC 
                           ${INCLUDE_DIR})