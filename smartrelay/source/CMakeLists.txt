set(SMART_RELAY_SRCS
    main.cpp
    smart_relay.cpp
)

set(SMART_RELAY_HDRS
smart_relay.hpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)


target_sources(${EXE_NAME_SMART_RELAY} PRIVATE ${SMART_RELAY_SRCS} ${SMART_RELAY_HDRS})

target_include_directories(${EXE_NAME_SMART_RELAY} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/include/embedded_engine
)
if(TARGET_RASPEBRRY_PI_3)
    target_include_directories(${EXE_NAME_SMART_RELAY} PRIVATE
        /usr/include/embedded_engine/wiringPi
    )
endif()

target_link_directories(${EXE_NAME_SMART_RELAY} PRIVATE /usr/lib/embedded_engine)

target_link_libraries(${EXE_NAME_SMART_RELAY} PRIVATE Threads::Threads)
target_link_libraries(${EXE_NAME_SMART_RELAY} PRIVATE EmbeddedEngine)

if(TARGET_RASPBERRY_PI_3)
    target_link_libraries(${EXE_NAME_SMART_RELAY} PRIVATE wiringPi)
endif()

install(TARGETS ${EXE_NAME_SMART_RELAY} DESTINATION bin/embedded_engine)
