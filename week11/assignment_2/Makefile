.SUFFIXES: .cpp .o

OBJ = Complex.cpp Float.cpp Integer.cpp test.cpp
OBJECTS = Complex.o Float.o Integer.o test.o

CXX = g++

TARGET = num

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJ)

clean :
	rm -rf $(OBJECTS) $(TARGET)


