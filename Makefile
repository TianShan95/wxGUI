# Makefile for wxWidgets project
# ubuntu:
# g++ -std=c++11 *.cpp  -o RTDBwxGUI `wx-config --cxxflags --libs` -lwx_gtk2u_aui-3.0 -lwx_gtk2u_propgrid-3.0 -lwx_gtk2u_richtext-3.0
# mac:
# g++ -std=c++11 *.cpp -o wxfb `wx-config --cxxflags --libs` -I/usr/local/include/wx-3.2 -I/usr/local/lib/wx/include/osx_cocoa-unicode-3.2 -lwx_osx_cocoau_aui-3.2.0 -lwx_osx_cocoau_richtext-3.2
# 

# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11

# wxWidgets libraries and flags
# WX_LIBS := $(shell wx-config --libs)
WX_CXXFLAGS := $(shell wx-config --cxxflags --libs)

# Additional wxWidgets libraries
WX_ADDITIONAL_LIBS := -lwx_gtk2u_aui-3.0 -lwx_gtk2u_propgrid-3.0 -lwx_gtk2u_richtext-3.0 -lwx_gtk2u_core-3.0 -lwx_baseu-3.0 -lwx_gtk2u_adv-3.0
# Source files
SRCS := $(wildcard *.cpp)
# Object files
OBJS := $(SRCS:.cpp=.o)
# Executable name
TARGET := RTDBwxGUI

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(WX_LIBS) $(WX_ADDITIONAL_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(WX_CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

install:
	cp $(TARGET) /usr/bin
	cp path.conf /usr/bin
	cp -r icon /usr/bin/

uninstall:
	rm /usr/bin/$(TARGET)
	rm /usr/bin/path.conf
	rm -rf /usr/bin/icon