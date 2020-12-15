CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/interface.o: logics/interface.cpp logics/interface.hpp $(BUILD_DIR)/user_class.o $(BUILD_DIR)/jeek_class.o $(BUILD_DIR)/comment_class.o $(BUILD_DIR)/reply_class.o $(BUILD_DIR)/exceptions.o
	$(CC) $(CF) -c logics/interface.cpp -o $(BUILD_DIR)/interface.o

$(BUILD_DIR)/user_class.o: logics/user_class.cpp logics/user_class.hpp $(BUILD_DIR)/exceptions.o $(BUILD_DIR)/my_utilities.o
	$(CC) $(CF) -c logics/user_class.cpp -o $(BUILD_DIR)/user_class.o

$(BUILD_DIR)/jeek_class.o: logics/jeek_class.cpp logics/jeek_class.hpp $(BUILD_DIR)/comment_class.o $(BUILD_DIR)/exceptions.o
	$(CC) $(CF) -c logics/jeek_class.cpp -o $(BUILD_DIR)/jeek_class.o

$(BUILD_DIR)/reply_class.o: logics/reply_class.cpp logics/reply_class.hpp
	$(CC) $(CF) -c logics/reply_class.cpp -o $(BUILD_DIR)/reply_class.o

$(BUILD_DIR)/comment_class.o: logics/comment_class.cpp logics/comment_class.hpp $(BUILD_DIR)/reply_class.o
	$(CC) $(CF) -c logics/comment_class.cpp -o $(BUILD_DIR)/comment_class.o

$(BUILD_DIR)/my_utilities.o: logics/my_utilities.cpp logics/my_utilities.hpp
	$(CC) $(CF) -c logics/my_utilities.cpp -o $(BUILD_DIR)/my_utilities.o

$(BUILD_DIR)/exceptions.o: logics/exceptions.cpp logics/exceptions.hpp
	$(CC) $(CF) -c logics/exceptions.cpp -o $(BUILD_DIR)/exceptions.o


$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o


$(BUILD_DIR)/login_handler.o: pages/login_handler.cpp pages/login_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/login_handler.cpp -o $(BUILD_DIR)/login_handler.o

$(BUILD_DIR)/show_home_page.o: pages/show_home_page.cpp pages/show_home_page.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/show_home_page.cpp -o $(BUILD_DIR)/show_home_page.o

$(BUILD_DIR)/show_login_page.o: pages/show_login_page.cpp pages/show_login_page.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/show_login_page.cpp -o $(BUILD_DIR)/show_login_page.o

$(BUILD_DIR)/show_signup_page.o: pages/show_signup_page.cpp pages/show_signup_page.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/show_signup_page.cpp -o $(BUILD_DIR)/show_signup_page.o

$(BUILD_DIR)/signup_handler.o: pages/signup_handler.cpp pages/signup_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/signup_handler.cpp -o $(BUILD_DIR)/signup_handler.o

$(BUILD_DIR)/logout.o: pages/logout.cpp pages/logout.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/logout.cpp -o $(BUILD_DIR)/logout.o

$(BUILD_DIR)/search_handler.o: pages/search_handler.cpp pages/search_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/search_handler.cpp -o $(BUILD_DIR)/search_handler.o

$(BUILD_DIR)/like_handler.o: pages/like_handler.cpp pages/like_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/like_handler.cpp -o $(BUILD_DIR)/like_handler.o

$(BUILD_DIR)/dislike_handler.o: pages/dislike_handler.cpp pages/dislike_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/dislike_handler.cpp -o $(BUILD_DIR)/dislike_handler.o

$(BUILD_DIR)/rejeek_handler.o: pages/rejeek_handler.cpp pages/rejeek_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/rejeek_handler.cpp -o $(BUILD_DIR)/rejeek_handler.o

$(BUILD_DIR)/more_detail_handler.o: pages/more_detail_handler.cpp pages/more_detail_handler.hpp $(BUILD_DIR)/utilities.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o utils/include.hpp $(BUILD_DIR)/server.o $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/more_detail_handler.cpp -o $(BUILD_DIR)/more_detail_handler.o


$(BUILD_DIR)/html_maker.o: pages/html_maker.cpp pages/html_maker.hpp $(BUILD_DIR)/interface.o
	$(CC) $(CF) -c pages/html_maker.cpp -o $(BUILD_DIR)/html_maker.o


$(BUILD_DIR)/server_main.o: server/main.cpp $(BUILD_DIR)/server.o $(BUILD_DIR)/login_handler.o $(BUILD_DIR)/signup_handler.o $(BUILD_DIR)/logout.o $(BUILD_DIR)/search_handler.o $(BUILD_DIR)/like_handler.o $(BUILD_DIR)/dislike_handler.o $(BUILD_DIR)/rejeek_handler.o $(BUILD_DIR)/more_detail_handler.o $(BUILD_DIR)/show_home_page.o $(BUILD_DIR)/show_login_page.o $(BUILD_DIR)/show_signup_page.o $(BUILD_DIR)/html_maker.o
	$(CC) $(CF) -c server/main.cpp -o $(BUILD_DIR)/server_main.o

server.out: $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/login_handler.o $(BUILD_DIR)/signup_handler.o $(BUILD_DIR)/logout.o $(BUILD_DIR)/search_handler.o $(BUILD_DIR)/like_handler.o $(BUILD_DIR)/dislike_handler.o $(BUILD_DIR)/rejeek_handler.o $(BUILD_DIR)/more_detail_handler.o $(BUILD_DIR)/html_maker.o $(BUILD_DIR)/show_home_page.o $(BUILD_DIR)/show_login_page.o $(BUILD_DIR)/show_signup_page.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/user_class.o $(BUILD_DIR)/jeek_class.o $(BUILD_DIR)/reply_class.o $(BUILD_DIR)/comment_class.o $(BUILD_DIR)/my_utilities.o $(BUILD_DIR)/exceptions.o
	$(CC) $(CF) $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/login_handler.o $(BUILD_DIR)/signup_handler.o $(BUILD_DIR)/logout.o $(BUILD_DIR)/search_handler.o $(BUILD_DIR)/like_handler.o $(BUILD_DIR)/dislike_handler.o $(BUILD_DIR)/rejeek_handler.o $(BUILD_DIR)/more_detail_handler.o $(BUILD_DIR)/html_maker.o $(BUILD_DIR)/show_home_page.o $(BUILD_DIR)/show_login_page.o $(BUILD_DIR)/show_signup_page.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/user_class.o $(BUILD_DIR)/jeek_class.o $(BUILD_DIR)/reply_class.o $(BUILD_DIR)/comment_class.o $(BUILD_DIR)/my_utilities.o $(BUILD_DIR)/exceptions.o -o server.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null
