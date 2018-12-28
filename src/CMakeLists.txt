cmake_minimum_required(VERSION 3.7)

if(NOT TARGET uo::uo_conf)
    find_package(uo_conf CONFIG REQUIRED)
endif()
if(NOT TARGET uo::uo_err)
    find_package(uo_err CONFIG REQUIRED)
endif()
if(NOT TARGET uo::uo_http)
    find_package(uo_http CONFIG REQUIRED)
endif()

add_executable(fina-web
    fina_web.c)

target_link_libraries(fina-web
    PRIVATE
        uo::uo_conf
        uo::uo_err
        uo::uo_http)

target_compile_features(fina-web
    PUBLIC
        c_std_11)

install(DIRECTORY conf/ projectfina
    DESTINATION bin)

install(TARGETS fina-web
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)
