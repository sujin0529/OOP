.SUFFIXES: .cpp .o

OBJECTS = json_object.o json_list.o json_dict.o data/Integer.o data/String.o
MAIN = main.o $(OBJECTS)

CXX = g++
CPPFLAGS = -Wall -O

DATA = data
TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(MAIN) $(TARGET)
