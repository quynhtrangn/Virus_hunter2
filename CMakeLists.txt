cmake_minimum_required(VERSION 3.17)
project(VirusHunter)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

add_executable(VirusHunter main.cpp Data.cpp Data.h Animation.cpp Animation.h StateLoad.cpp StateLoad.h StatePlay.cpp StatePlay.h StateIntro.cpp StateIntro.h Collision.cpp Collision.h)
target_link_libraries(VirusHunter sfml-system sfml-window sfml-graphics sfml-audio)