OTHER_DIR := ../src
CXX := g++
CXXFLAGS := -Wall -std=c++11 -Wpedantic -Wextra -Werror -I $(OTHER_DIR)
OPENGL_LDFLAGS := -lglut -lGLU -lGL
LDFLAGS := -lpthread

UNAME := $(shell uname)

# OS X specific options
ifeq ($(UNAME), Darwin)
OPENGL_LDFLAGS := -framework OpenGL -framework GLUT
CXXFLAGS := $(CXXFLAGS) -Wno-deprecated
endif


#
# auto dependency generation requires SRCS and OBJECTS to be set
#
SRCS    := $(sort $(wildcard *.cpp) $(wildcard  $(OTHER_DIR)/*.cpp))
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))

MAINSRCS    := $(shell egrep 'int main' $(SRCS) | awk -F: '{print $$1;}' | uniq)
OPENGL_SRCS := $(sort $(wildcard gl_*.cpp glut_*.cpp Glut*.cpp))
OPENGL_SRCS := $(filter-out $(MAINSRCS),$(OPENGL_SRCS))
COMMON_SRCS := $(sort $(SRCS))
COMMON_SRCS := $(filter-out $(MAINSRCS),$(COMMON_SRCS))
COMMON_SRCS := $(filter-out $(OPENGL_SRCS),$(COMMON_SRCS))

COMMON_OBJECTS := $(patsubst %.cpp,%.o,$(COMMON_SRCS))
OPENGL_OBJECTS := $(patsubst %.cpp,%.o,$(OPENGL_SRCS))

TARGETS := glut_main

all: $(TARGETS)

glut_main: glut_main.o $(COMMON_OBJECTS) $(OPENGL_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(OPENGL_LDFLAGS)

$(COMMON_OBJECTS):
	make -C $(OTHER_DIR) $(notdir $@)

######################################
# automatic dependency generation
#
DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

%.o : %.cpp
%.o : %.cpp $(DEPDIR)/%.d
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS))))
#
#
######################################

######################################
#
#
clean:
	-rm -f $(TARGETS)
	-rm -f *.o
	-rm -f *~
	-rm -rf $(DEPDIR)
#
#
######################################



# Local Variables:
# mode:makefile
# End:
