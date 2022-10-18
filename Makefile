a:Point.o Dist.o CPoint.o CDist.o main.o
	wg++ -fno-elide-constructors -std=c++11  Point.o Dist.o CPoint.o CDist.o main.o

main.o:main.cpp Point.h Dist.h CPoint.h CDist.h
	wg++ -fno-elide-constructors -std=c++11  main.cpp -c

Point.o:Point.cpp Point.h
	wg++ -fno-elide-constructors -std=c++11  Point.cpp -c

Dist.o:Dist.cpp Dist.h
	wg++ -fno-elide-constructors -std=c++11  Dist.cpp -c

CPoint.o:CPoint.cpp CPoint.h
	wg++ -fno-elide-constructors -std=c++11  CPoint.cpp -c

CDist.o:CDist.cpp CDist.h
	wg++ -fno-elide-constructors -std=c++11  CDist.cpp -c
