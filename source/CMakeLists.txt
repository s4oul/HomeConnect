add_executable(${EXE_NAME})

set(HOME_CONNECT_SRCS
    main.cpp
    home_connect.cpp
)

set(HOME_CONNECT_HDRS
    home_connect.hpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)


target_sources(${EXE_NAME} PRIVATE ${HOME_CONNECT_SRCS} ${HOME_CONNECT_HDRS})

target_include_directories(${EXE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/include/embedded_engine
)

if(TARGET_RASPEBRRY_PI_3)
    target_include_directories(${EXE_NAME} PRIVATE
        /usr/include/embedded_engine/wiringPi
    )
endif()

target_link_directories(${EXE_NAME} PRIVATE /usr/lib/embedded_engine)

target_link_libraries(${EXE_NAME} PRIVATE Threads::Threads)
target_link_libraries(${EXE_NAME} PRIVATE EmbeddedEngine)

if(TARGET_RASPBERRY_PI_3)
    target_link_libraries(${EXE_NAME} PRIVATE wiringPi)
endif()

install(TARGETS ${EXE_NAME} DESTINATION bin/embedded_engine)
