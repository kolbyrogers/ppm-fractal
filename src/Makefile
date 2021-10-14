targets = hello questions_3 ascii_image image_file ActionData.o MenuData.o ppm_menu # inquisitor simple_squares_ascii
objects = user_io.o controllers.o image_drawing.o image_output.o Image.o PPM.o MenuData.o ActionData.o image_filters.o NumberGrid.o
headers = image_menu.h Image.h PPM.h MenuData.h ActionData.h NumberGrid.h

all: $(targets)

# ---Hello---
hello: hello.o
	g++ -o hello hello.o

hello.o: hello.cpp
	g++ -c hello.cpp

# ---Questions 3---
questions_3: questions_3.o $(objects)
	g++ -o questions_3 questions_3.o $(objects)

questions_3.o: questions_3.cpp $(headers)
	g++ -c questions_3.cpp

user_io.o: user_io.cpp $(headers)
	g++ -c user_io.cpp

controllers.o: controllers.cpp $(objects) 
	g++ -c controllers.cpp

# ---ASCII image---
ascii_image: ascii_image.o $(objects)
	g++ -o ascii_image ascii_image.o $(objects)

ascii_image.o: ascii_image.cpp $(headers)
	g++ -c ascii_image.cpp

image_drawing.o: image_drawing.cpp $(headers)
	g++ -c image_drawing.cpp

image_output.o: image_output.cpp $(headers)
	g++ -c image_output.cpp

Image.o: Image.cpp $(headers)
	g++ -c Image.cpp

# ---Image File---
image_file: image_file.o $(objects)
	g++ -o image_file image_file.o $(objects)

image_file.o: image_file.cpp $(headers)
	g++ -c image_file.cpp

PPM.o: PPM.cpp $(headers)
	g++ -c PPM.cpp

# --Inquisitor--
inquisitor: inquisitors.o $(objects)
	g++ -o inquisitor inquisitors.o $(objects)

inquisitors.o: inquisitors.cpp $(headers)
	g++ -c inquisitors.cpp

# --Squares--
simple_squares_ascii: simple_squares_ascii.o $(objects)
	g++ -o simple_squares_ascii simple_squares_ascii.o $(objects)

simple_squares_ascii.o: simple_squares_ascii.cpp $(headers)
	g++ -c simple_squares_ascii.cpp

# --Action Data Menu--
ActionData.o: ActionData.cpp $(headers)
	g++ -c ActionData.cpp

MenuData.o: MenuData.cpp $(headers)
	g++ -c MenuData.cpp

# --PPM Menu--
ppm_menu: ppm_menu.o $(objects)
	g++ -o ppm_menu ppm_menu.o $(objects)

ppm_menu.o: ppm_menu.cpp $(headers)
	g++ -c ppm_menu.cpp

image_filters.o: image_filters.cpp $(headers)
	g++ -c image_filters.cpp

# --Number Grid--
NumberGrid.o: NumberGrid.cpp $(headers)
	g++ -c NumberGrid.cpp

# ---Clean---
clean:
	-rm -f *.o
	-rm -f *.ppm
	-rm -f $(targets)
