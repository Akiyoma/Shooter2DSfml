cmake_minimum_required(VERSION 3.20)
project(Shooter2DSfml)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shooter2DSfml sources/main.cpp sources/Game.cpp headers/Game.h sources/Player.cpp headers/Player.h sources/Bullet.cpp headers/Bullet.h sources/Enemies/Enemy.cpp headers/Enemies/Enemy.h sources/Enemies/TwoTimePatrolEnemy.cpp headers/Enemies/TwoTimePatrolEnemy.h sources/Loader.cpp headers/Loader.h sources/Level.cpp headers/Level.h)

set(SFML_ROOT "C:/Program Files (x86)/SFML-2.5.1")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    target_link_libraries(Shooter2DSfml sfml-graphics sfml-window sfml-system)
endif()