.SUFFIXES : .cpp .o

OBJECTS = test.o human.o student.o smart_obj.o shared_ref.o weak_pointer.o
OBJ = test.cpp human.cpp student.cpp smart_obj.cpp shared_ref.cpp weak_pointer.cpp

CXX = g++

TARGET = smart

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJ)

clean :
	rm -rf $(OBJECTS) $(TARGET)

