# in=smp.txt
in=in0

all: main

main: force
	g++ -o $@ $@.cpp 2>&1 | tee $@.txt
	./$@ 2>&1 | tee $@.txt

clean:
	find ! -name Makefile ! -name *.cpp ! -name *.hpp | xargs rm -rf

force:
