CXX = g++
CXXFLAGS = -Wall -Wextra -pthread -lrt

all: producer consumer

producer: producer.cpp shared_mem.cpp
    $(CXX) $(CXXFLAGS) -o producer producer.cpp shared_mem.cpp

consumer: consumer.cpp shared_mem.cpp
    $(CXX) $(CXXFLAGS) -o consumer consumer.cpp shared_mem.cpp

clean:
    rm -f producer consumer
