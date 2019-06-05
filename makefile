CC := g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR = BUILD_DIR
SRC_DIR = src
TEMPLATE_DIR=.template

EXECUTABLE_FILE = final_phase1.out

OBJECTS = \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/Comment.o \
	$(BUILD_DIR)/Core.o \
	$(BUILD_DIR)/Error_Handler.o \
	$(BUILD_DIR)/Film.o \
	$(BUILD_DIR)/Input_Handler.o \
	$(BUILD_DIR)/Message.o \
	$(BUILD_DIR)/Film_Graph.o \
	$(BUILD_DIR)/Money_Handler.o \
	$(BUILD_DIR)/Parameter_Handler.o \
	$(BUILD_DIR)/Publisher.o \
	$(BUILD_DIR)/User.o \
	$(BUILD_DIR)/Web_Handlers.o \
	$(BUILD_DIR)/my_server.o \
	$(BUILD_DIR)/Web_Service.o \
	$(BUILD_DIR)/response.o \
	$(BUILD_DIR)/request.o \
	$(BUILD_DIR)/utilities.o \
	$(BUILD_DIR)/server.o \
	$(BUILD_DIR)/route.o \
	$(BUILD_DIR)/template_parser.o \

main_list = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Core.h \
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
	$(SRC_DIR)/Film_Graph.h \
	$(SRC_DIR)/Web_Service.h \


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

Film_Graph_list = \
	$(SRC_DIR)/Film_Graph.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/Core.h \
	$(SRC_DIR)/Film.h \
	$(SRC_DIR)/User.h \


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


Web_Service_list = \
	$(SRC_DIR)/Web_Service.cpp \
	$(SRC_DIR)/Header.h \
	$(SRC_DIR)/my_server.h \
	$(SRC_DIR)/Web_Handlers.h \
	server/server.hpp \
	utils/utilities.hpp \
	utils/response.hpp \
	utils/request.hpp \
	utils/include.hpp \




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

$(BUILD_DIR)/Film_Graph.o: $(Film_Graph_list)
	$(CC) -c $(SRC_DIR)/Film_Graph.cpp -o $(BUILD_DIR)/Film_Graph.o

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

##APHTTP##

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp src/Core.h
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o


$(BUILD_DIR)/Web_Handlers.o: $(SRC_DIR)/Web_Handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c $(SRC_DIR)/Web_Handlers.cpp -o $(BUILD_DIR)/Web_Handlers.o

$(BUILD_DIR)/my_server.o: $(SRC_DIR)/my_server.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c $(SRC_DIR)/my_server.cpp -o $(BUILD_DIR)/my_server.o


$(BUILD_DIR)/Web_Service.o: $(Web_Service_list)
	$(CC) $(CF) -c $(SRC_DIR)/Web_Service.cpp -o $(BUILD_DIR)/Web_Service.o


$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
