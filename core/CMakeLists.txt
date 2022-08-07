

#set source files
set(CORE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(BALL_SOURSES ${CMAKE_CURRENT_SOURCE_DIR}/src/Ball.cpp)
set(PADDLE_SOURSES ${CMAKE_CURRENT_SOURCE_DIR}/src/Paddle.cpp)
set(GAME_SOURSES ${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp)

set(GRAPHENG_SOURSES ${CMAKE_CURRENT_SOURCE_DIR}/src/GraphicEngine.cpp)
set(ENGINE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine.cpp)

# add libraries
add_library(Ball ${BALL_SOURSES}) 
target_include_directories(Ball PRIVATE ${CORE_INCLUDES})

add_library(Paddle ${PADDLE_SOURSES}) 
target_include_directories(Paddle PRIVATE ${CORE_INCLUDES})

add_library(Game ${GAME_SOURSES}) 
target_include_directories(Game PRIVATE ${CORE_INCLUDES})

target_link_libraries(Game Ball)
target_link_libraries(Game Paddle)

add_library(GraphicEngine ${GRAPHENG_SOURSES}) 
target_include_directories(GraphicEngine PRIVATE ${CORE_INCLUDES})

target_link_libraries(GraphicEngine Game)

add_library(Engine ${ENGINE_SOURCES})
target_include_directories(Engine PRIVATE ${CORE_INCLUDES})

target_link_libraries(Engine GraphicEngine)