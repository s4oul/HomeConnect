set(FAN_SMART_SRCS
    main.cpp
    fan_smart.cpp
)

set(FAN_SMART_HDRS
    fan_smart.hpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)


target_sources(${EXE_NAME_FAN_SMART} PRIVATE ${FAN_SMART_SRCS} ${FAN_SMART_HDRS})

target_include_directories(${EXE_NAME_FAN_SMART} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/include/embedded_engine
)
if(TARGET_RASPEBRRY_PI_3)
    target_include_directories(${EXE_NAME_FAN_SMART} PRIVATE
        /usr/include/embedded_engine/wiringPi
    )
endif()

target_link_directories(${EXE_NAME_FAN_SMART} PRIVATE /usr/lib/embedded_engine)

target_link_libraries(${EXE_NAME_FAN_SMART} PRIVATE Threads::Threads)
target_link_libraries(${EXE_NAME_FAN_SMART} PRIVATE EmbeddedEngine)

if(TARGET_RASPBERRY_PI_3)
    target_link_libraries(${EXE_NAME_FAN_SMART} PRIVATE wiringPi)
endif()

install(TARGETS ${EXE_NAME_FAN_SMART} DESTINATION bin/embedded_engine)
