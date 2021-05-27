cmake_minimum_required(VERSION 3.17)
project(Car_Rental_Dynamic C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ansi -pedantic-errors -lm")
add_executable(Car_Rental_Dynamic main.c Car.c Car.h Supplier.c Supplier.h Client.c Client.h ValidInput.c ValidInput.h Common.c Common.h matam.c matam.h)