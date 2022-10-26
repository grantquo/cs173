make: driver fractal

driver: driver.o Complex.o
	g++ -o driver driver.o Complex.o

fractal: mandelbrot.o Complex.o
	g++ -o fractal mandelbrot.o Complex.o
	
driver.o: driver.cpp Complex.h
	g++ -c driver.cpp
	
Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp
	
mandelbrot.o: mandelbrot.cpp Complex.h
	g++ -c mandelbrot.cpp
	
