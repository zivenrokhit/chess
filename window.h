// #ifndef __WINDOW_H__
// #define __WINDOW_H__
// #include <X11/Xlib.h>
// #include <iostream>
// #include <map>
// #include <string>

// using namespace std;
// class Xwindow {
// 	Display *displayPtr;
// 	Window windw;
// 	GC gcFirst;
//     GC gcSecond;
//     int s;
// 	unsigned long colours[11];
// 	int width, height;
// 	unsigned int bitmapWidth, bitmapHeight;
// 	map<char, Pixmap*> imageMap; 
//   	unsigned int axisWidth, axisHeight;
//     string directory = "../img/";

//   public:
// 	Xwindow(int width=1500, int height=1500);  // make window
// 	~Xwindow();                              // destroy window


// 	void genMsg(int x, int y, string msg, int colour = Black);
// 	void colourTile(int x, int y, int width, int height, int colour=Black);
// 	void genPiece(char piece, int x, int y, int width, int height);

//   private:
// 	GC createGC(Display* display, Window win, int reverseVideo);
//     void printMsg(int x, int y, const std::string& msg, int colour, XFontStruct& fStruct);

// };

// #endif