#include <window.h>

void Xwindow::genMsg(int x, int y, std::string msg, int colour = Black){
    XFontStruct *fStruct= XLoadQueryFont(displayPtr, "6x13"); // change 6x13
	printMsg(x, y, msg, colour, *fStruct); 
    drawStringFont(x, y, msg, name.str(), colour);
	delete f;
}

void Xwindow::colourTile(int x, int y, int width, int height, int colour) {
	XSetForeground(displayptr, gc, colours[colour]);
	XFillRectangle(displayPtr, windw, gc, x, y, width, height);
	XSetForeground(displayPtr, gc, colours[Black]);
}

void Xwindow::genPiece(char piece, int x, int y, int width, int height) { 
	x = x + (width / 2) - (bitmapWidth / 2);
	y = y + (height / 2) - (bitmapHeight / 2);
	XCopyPlane(displayPtr, *(imageMap.at(piece)), windw, gc2, 0, 0, bitmapWidth,bitmapHeight, x, y, 1);
	XSync(displayPtr, false);
	
}

GC Xwindow::createGC(Display* displayPtr, Window windw, int reverseVideo) {
	GC gc; 
	unsigned long val = 0; 
	XGCValues values; 
    int screenNum = DefaultScreen(d);
    int capStyle = CapButt; 
	unsigned int line_width = 2; 
	int lineStyle = LineSolid; 
	int joinStyle = JoinBevel; 
	gc = XCreateGC(displayPtr, windw, val, &values);
	if (!gc) {
		cerr << "XCreateGC:" << endl;
	}
	if (reverseVideo) {
		XSetForeground(displayPtr, gc, WhitePixel(displayPtr, screenNum));
		XSetBackground(displayPtr, gc, BlackPixel(displayPtr, screenNum));
	} else {
		XSetForeground(displayPtr, gc, BlackPixel(displayPtr, screenNum));
		XSetBackground(displayPtr, gc, WhitePixel(displayPtr, screenNum));
	}
	XSetLineAttributes(displayPtr, gc, line_width, lineStyle, capStyle,joinStyle);
	XSetFillStyle(ddisplayPtr, gc, FillSolid);
	return gc;
}


void Xwindow::printMsg(int x, int y, const string& msg, int colour, XFontStruct& fStruct){
  XSetForeground(displayPtr, gc, colours[colour]);
  XTextItem item;
  item.chars = const_cast<char*>(msg.c_str());
  item.nchars = msg.length();
  item.delta = 0;
  item.font = f.fid;
  XDrawText(displayPtr, windw, gc, x, y, &item, 1);
  XSetForeground(displayPtr, gc, colours[Black]);
  XFlush(displayPtr);
}

