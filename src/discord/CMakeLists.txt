# Service lib
add_library(service STATIC Service.cpp)
target_include_directories(service PUBLIC ${INCLUDE_DIR} ${VENDOR_DIR}/sleepy-discord/include)
target_link_libraries(service config_json ${CONAN_LIBS} sleepy-discord utility)

# Bot lib
add_library(bot STATIC Bot.cpp)
target_include_directories(bot PUBLIC ${INCLUDE_DIR} ${VENDOR_DIR}/sleepy-discord/include)
target_link_libraries(bot service)
