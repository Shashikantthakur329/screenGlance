CXX = g++
CFLAGS = -Wall
out = main
baseGrabber = BaseGrabber
X11ImageGrabber = X11ImageGrabber
BaseImageHandler = BaseImageHandler
CImgHandler = CImgHandler
Image = Image
Rectangle = Rectangle
SelectArea = ./helper/SelectArea
ScreenGlance = screenGlance

all: $(out)

$(out): $(out).o $(baseGrabber).o $(X11ImageGrabber).o $(BaseImageHandler).o $(CImgHandler).o \
    $(SelectArea).o $(Rectangle).o $(Image).o $(ScreenGlance).o $(pkg-config --libs --cflags cairo) 
	$(CXX) -o $(out) $(out).o $(baseGrabber).o $(X11ImageGrabber).o $(BaseImageHandler).o \
    $(CImgHandler).o $(SelectArea).o $(Rectangle).o $(Image).o $(ScreenGlance).o \
	$$(pkg-config --libs --cflags cairo) -lX11

$(out).o: $(out).cpp
	$(CXX) -c $(out).cpp -o $(out).o

$(SelectArea).o: $(SelectArea).cpp
	$(CXX) -c $(SelectArea).cpp $$(pkg-config --libs --cflags cairo) -o $(SelectArea).o

$(Rectangle).o: $(Rectangle).cpp
	$(CXX) -c $(Rectangle).cpp -o $(Rectangle).o

$(Image).o: $(Image).cpp
	$(CXX) -c $(Image).cpp -o $(Image).o

$(CImgHandler).o: $(CImgHandler).cpp
	$(CXX) -c $(CImgHandler).cpp -o $(CImgHandler).o

$(BaseImageHandler).o: $(BaseImageHandler).cpp
	$(CXX) -c $(BaseImageHandler).cpp -o $(BaseImageHandler).o

$(X11ImageGrabber).o: $(X11ImageGrabber).cpp
	$(CXX) -c $(X11ImageGrabber).cpp -o $(X11ImageGrabber).o

$(baseGrabber).o: $(baseGrabber).cpp
	$(CXX) -c $(baseGrabber).cpp -o $(baseGrabber).o

$(ScreenGlance).o: $(ScreenGlance).cpp
	$(CXX) -c $(ScreenGlance).cpp -o $(ScreenGlance).o
clean:
	rm -f *.o $(out)
