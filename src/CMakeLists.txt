add_executable(breakout
    main.cpp
    ball.cpp
    paddle.cpp
    brick.cpp
)

target_link_libraries(breakout
    ${SFML_LIBRARIES}
)

install(TARGETS breakout DESTINATION ${CMAKE_SOURCE_DIR}/build)
