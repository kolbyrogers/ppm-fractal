all: hello questions_3 ascii_image image_file inquisitor

# ---Hello---
hello: hello.o
	g++ -o hello hello.o

hello.o: hello.cpp
	g++ -c hello.cpp

# ---Questions 3---
questions_3: questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o
	g++ -o questions_3 questions_3.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o

questions_3.o: questions_3.cpp image_menu.h PPM.h
	g++ -c questions_3.cpp

user_io.o: user_io.cpp
	g++ -c user_io.cpp

controllers.o: controllers.cpp image_menu.h Image.h PPM.h
	g++ -c controllers.cpp

# ---ASCII image---
ascii_image: ascii_image.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o
	g++ -o ascii_image ascii_image.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h PPM.h
	g++ -c ascii_image.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h PPM.h
	g++ -c image_drawing.cpp

image_output.o: image_output.cpp image_menu.h Image.h PPM.h
	g++ -c image_output.cpp

Image.o: Image.cpp image_menu.h Image.h PPM.h
	g++ -c Image.cpp

# ---Image File---
image_file: image_file.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o
	g++ -o image_file image_file.o user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o

image_file.o: image_file.cpp image_menu.h Image.h PPM.h
	g++ -c image_file.cpp

PPM.o: PPM.cpp image_menu.h PPM.h
	g++ -c PPM.cpp

# --Inquisitor--
inquisitor: inquisitors.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o 
	g++ -o inquisitor inquisitors.o user_io.o controllers.o Image.o image_drawing.o image_output.o PPM.o

inquisitors.o: inquisitors.cpp image_menu.h
	g++ -c inquisitors.cpp
# ---Clean---
clean:
	-rm -f *.o
	-rm -f *.ppm
	-rm -f hello questions_3 ascii_image image_file