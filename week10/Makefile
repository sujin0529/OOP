.SUFFIXES : .cpp .o 

OBJECTS = main.o car.o vehicle.o bike.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
car.o : car.cpp
vehicle.o : vehicle.cpp
bike.o : bike.cpp
