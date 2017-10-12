all: a.out doc

a.out: main.o college.o course.o
      g++ main.o college.o course.o -o a.out
      
main.o: collegemain.cc course.h node.h college.h
      g++ -c collegemain.cc course.h node.h college.h

college.o: college.cc college.h
      g++ -c

course.o:
#remove .o files and executable
clean:
	-rm *.o
	-rm game
	-rm .class
	-rm -rf html
	-rm -rf latex

all: game doc

doc: 
@doxygen Doxyfile
