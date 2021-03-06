cmake_minimum_required(VERSION 3.12)

if(NOT TARGET uo::uo_conf)
    find_package(uo_conf CONFIG REQUIRED)
endif()
if(NOT TARGET uo::uo_err)
    find_package(uo_err CONFIG REQUIRED)
endif()
if(NOT TARGET uo::uo_http)
    find_package(uo_http CONFIG REQUIRED)
endif()
if(NOT TARGET uo::uo_prog)
    find_package(uo_prog CONFIG REQUIRED)
endif()

add_executable(projectfina-web
    projectfina-web.c)

target_link_libraries(projectfina-web
    PRIVATE
        uo::uo_conf
        uo::uo_err
        uo::uo_http
        uo::uo_prog)

target_compile_features(projectfina-web
    PUBLIC
        c_std_11)

install(DIRECTORY conf/
    DESTINATION bin)

install(TARGETS projectfina-web
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)
