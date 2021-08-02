set(HOME_CONNECT_SRCS
    main.cpp
    home_connect.cpp
    config_project.cpp
)

set(HOME_CONNECT_HDRS
    home_connect.hpp
    config_project.hpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)


target_sources(${EXE_NAME_HOME_CONNECT} PRIVATE ${HOME_CONNECT_SRCS} ${HOME_CONNECT_HDRS})

target_include_directories(${EXE_NAME_HOME_CONNECT} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/include/embedded_engine
)

if(TARGET_RASPEBRRY_PI_3)
    target_include_directories(${EXE_NAME_HOME_CONNECT} PRIVATE
        /usr/include/embedded_engine/wiringPi
    )
endif()

target_link_directories(${EXE_NAME_HOME_CONNECT} PRIVATE /usr/lib/embedded_engine)

target_link_libraries(${EXE_NAME_HOME_CONNECT} PRIVATE Threads::Threads)
target_link_libraries(${EXE_NAME_HOME_CONNECT} PRIVATE EmbeddedEngine)

if(TARGET_RASPBERRY_PI_3)
    target_link_libraries(${EXE_NAME_HOME_CONNECT} PRIVATE wiringPi)
endif()

install(TARGETS ${EXE_NAME_HOME_CONNECT} DESTINATION bin/embedded_engine)
