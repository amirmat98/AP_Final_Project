CC := g++
BUILD_DIR = BUILD_DIR
SRC_DIR = src

EXECUTABLE_FILE = final_phase1.out

OBJECTS = \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/Comment.o \
	$(BUILD_DIR)/Core.o \
	$(BUILD_DIR)/Error_Handler.o \
	$(BUILD_DIR)/Film.o \
	$(BUILD_DIR)/Input_Handler.o \
	$(BUILD_DIR)/Message.o \
	$(BUILD_DIR)/Money_Handler.o \
	$(BUILD_DIR)/Parameter_Handler.o \
	$(BUILD_DIR)/Publisher.o \
	$(BUILD_DIR)/User.o \

main_list = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Header.h \

Comment_list = \
	$(SRC_DIR)/Comment.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Film.h \
	$(SRC_DIR)/User.h \

Core_list = \
	$(SRC_DIR)/Core.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/User.h \
	$(SRC_DIR)/Publisher.h \
	$(SRC_DIR)/Input_Handler.h \
	$(SRC_DIR)/Film.h \
	$(SRC_DIR)/Money_Handler.h \
	$(SRC_DIR)/Parameter_Handler.h \
	$(SRC_DIR)/Message.h \

Error_Handler_list = \
	$(SRC_DIR)/Error_Handler.cpp \
	$(SRC_DIR)/Header.h \

Film_list = \
	$(SRC_DIR)/Film.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Comment.cpp \
	$(SRC_DIR)/User.cpp \

Input_Handler_list = \
	$(SRC_DIR)/Input_Handler.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Core.h \

Message_list = \
	$(SRC_DIR)/Message.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/User.h \

Money_Handler_list = \
	$(SRC_DIR)/Money_Handler.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Core.h \
	$(SRC_DIR)/Film.h \

Parameter_Handler_list = \
	$(SRC_DIR)/Parameter_Handler.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Core.h \

Publisher_list = \
	$(SRC_DIR)/Publisher.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/User.h \
	$(SRC_DIR)/Film.h \

User_list = \
	$(SRC_DIR)/User.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Film.h \
	$(SRC_DIR)/Comment.h \
	$(SRC_DIR)/Message.h \

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/main.o: $(main_list)
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Comment.o: $(Comment_list)
	$(CC) -c $(SRC_DIR)/Comment.cpp -o $(BUILD_DIR)/Comment.o

$(BUILD_DIR)/Core.o: $(Core_list)
	$(CC) -c $(SRC_DIR)/Core.cpp -o $(BUILD_DIR)/Core.o

$(BUILD_DIR)/Error_Handler.o: $(Error_Handler_list)
	$(CC) -c $(SRC_DIR)/Error_Handler.cpp -o $(BUILD_DIR)/Error_Handler.o

$(BUILD_DIR)/Film.o: $(Film_list)
	$(CC) -c $(SRC_DIR)/Film.cpp -o $(BUILD_DIR)/Film.o

$(BUILD_DIR)/Input_Handler.o: $(Input_Handler_list)
	$(CC) -c $(SRC_DIR)/Input_Handler.cpp -o $(BUILD_DIR)/Input_Handler.o

$(BUILD_DIR)/Message.o: $(Message_list)
	$(CC) -c $(SRC_DIR)/Message.cpp -o $(BUILD_DIR)/Message.o

$(BUILD_DIR)/Money_Handler.o: $(Money_Handler_list)
	$(CC) -c $(SRC_DIR)/Money_Handler.cpp -o $(BUILD_DIR)/Money_Handler.o

$(BUILD_DIR)/Parameter_Handler.o: $(Parameter_Handler_list)
	$(CC) -c $(SRC_DIR)/Parameter_Handler.cpp -o $(BUILD_DIR)/Parameter_Handler.o

$(BUILD_DIR)/Publisher.o: $(Publisher_list)
	$(CC) -c $(SRC_DIR)/Publisher.cpp -o $(BUILD_DIR)/Publisher.o

$(BUILD_DIR)/User.o: $(User_list)
	$(CC) -c $(SRC_DIR)/User.cpp -o $(BUILD_DIR)/User.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR) *.o *.out
