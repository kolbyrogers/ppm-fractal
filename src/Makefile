all: hello questions_3
# Hello
hello: hello.o
	g++ -o hello hello.o

hello.o: hello.cpp
	g++ -c hello.cpp

# Questions 3
questions_3: questions_3.o user_io.o controllers.o
	g++ -o questions_3 questions_3.o user_io.o controllers.o

questions_3.o: questions_3.cpp image_menu.h
	g++ -c questions_3.cpp

user_io.o: user_io.cpp image_menu.h
	g++ -c user_io.cpp

controllers.o: controllers.cpp image_menu.h
	g++ -c controllers.cpp
