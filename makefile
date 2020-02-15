# PROSTY MAKEFILE DLA PROGRAMU KATALOGUS 4.0

CPP=g++
INCLUDE=-I/usr/include/gtkmm-2.4 -I/usr/lib/gtkmm-2.4/include -I/usr/include/glibmm-2.4 -I/usr/lib/glibmm-2.4/include -I/usr/include/gdkmm-2.4 -I/usr/lib/gdkmm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/include/atkmm-1.6 -I/usr/include/gtk-2.0 -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/lib/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/atk-1.0
CPPLINK=-lgtkmm-2.4 -lgdkmm-2.4 -latkmm-1.6 -lgtk-x11-2.0 -lpangomm-1.4 -lglibmm-2.4 -lsigc-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangocairo-1.0 -lpango-1.0 -lcairo -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0 -I/usr/include/libglademm-2.4 -I/usr/lib/libglademm-2.4/include -I/usr/include/gtkmm-2.4 -I/usr/lib/gtkmm-2.4/include -I/usr/include/libglade-2.0 -I/usr/include/glibmm-2.4 -I/usr/lib/glibmm-2.4/include -I/usr/include/gdkmm-2.4 -I/usr/lib/gdkmm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/include/atkmm-1.6 -I/usr/include/gtk-2.0 -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/lib/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/atk-1.0 -I/usr/include/libxml2  -lglademm-2.4 -lgtkmm-2.4 -lglade-2.0 -lgdkmm-2.4 -latkmm-1.6 -lpangomm-1.4 -lglibmm-2.4 -lsigc-2.0 -lgtk-x11-2.0 -lxml2 -lz -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangocairo-1.0 -lpango-1.0 -lcairo -lgobject-2.0 -lgmodule-2.0 -ldl -lglib-2.0

katalogus: main.o models.o
	${CPP} -o katalogus main.o models.o ${CPPLINK}
	
main.o: main.cpp models.hpp
	${CPP} -c ${INCLUDE} ${CPPFLAGS} main.cpp

models.o: models.cpp models.hpp
	${CPP} -c ${INCLUDE} ${CPPFLAGS} models.cpp
