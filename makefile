all: a.out doc

a.out: main.o college.o course.o
      g++ main.o college.o course.o -o a.out
      
main.o: collegemain.cc course.h node.h college.h
      g++ -c collegemain.cc

college.o: college.cc college.h
      g++ -c college.cc
      
course.o: course.cc course.h
	g++ -c course.cc

build: a.out

myexe: a.out

doczip:
	tar -cvzf college.tar.gz


#remove .o files and executable
clean:
	-rm *.o
	-rm .class
	-rm -rf html
	-rm -rf latex
	-rm a.out

doc: 
	@doxygen Doxyfile
