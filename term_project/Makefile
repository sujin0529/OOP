.SUFFIXES : .cpp .o

OBJECTS = array_2d.o block.o big_block.o fold_block.o tree_block.o cross_block.o
MAIN = main.o $(OBJECTS)

CXX = g++

TARGET = Puyo

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)


clean :
	rm -rf $(MAIN) $(TARGET)
