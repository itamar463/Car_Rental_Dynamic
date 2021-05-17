cmake_minimum_required(VERSION 3.17)
project(Car_Rental_Dynamic C)

set(CMAKE_C_STANDARD 90)

add_executable(Car_Rental_Dynamic main.c Car.c Car.h Supplier.c Supplier.h Client.c Client.h ValidInput.c ValidInput.h Common.c Common.h)