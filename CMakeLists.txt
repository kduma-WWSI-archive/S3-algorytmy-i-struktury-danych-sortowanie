cmake_minimum_required(VERSION 3.9)
project(Sortowanie)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sortowanie main.cpp main.h src/s_wybieranie.cpp src/s_wybieranie.h src/s_wstawianie.cpp src/s_wstawianie.h src/s_babelkowe.cpp src/s_babelkowe.h src/s_scalanie.cpp src/s_scalanie.h src/s_szybkie.cpp src/s_szybkie.h src/generator_danych_testowych.cpp src/generator_danych_testowych.h src/funkcje_we_wy.cpp src/funkcje_we_wy.h)