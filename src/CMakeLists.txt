cmake_minimum_required(VERSION 3.2)
project(reversi)

set(MOVE_PATH "./move")

include_directories(move)
set(SOURCE_FILES main.cpp
step.cpp 
algo.cpp
drawboard.cpp
${MOVE_PATH}/north.cpp
${MOVE_PATH}/east.cpp
${MOVE_PATH}/west.cpp
${MOVE_PATH}/south.cpp
${MOVE_PATH}/westsouth.cpp
${MOVE_PATH}/northwest.cpp
${MOVE_PATH}/southeast.cpp
${MOVE_PATH}/eastnorth.cpp
)

add_executable(reversi ${SOURCE_FILES})
