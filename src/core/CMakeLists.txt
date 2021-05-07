# Config Json
add_library(config_json STATIC ConfigJson.cpp)
target_link_libraries(config_json ${CONAN_LIBS})
target_include_directories(config_json PUBLIC ${INCLUDE_DIR})