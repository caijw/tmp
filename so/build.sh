#!/bin/bash

g++ -fPIC -std=c++17 -m64  -DSHARED_LIB -c helper.cc

g++ -std=c++17 -shared -m64 -Wl,-soname,libhelper.so -o libhelper.so helper.o

g++ main.cc -ldl -lpthread -o main

g++ main1.cc -ldl -lpthread -o main1

g++ main2.cc -ldl -lpthread -o main2
