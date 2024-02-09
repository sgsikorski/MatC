CXX = g++

mkfile_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

ezc: scan.h scan.cpp parse.cpp
	g++ -o ezc scan.cpp parse.cpp

.PHONY: clean
clean:
	$(RM) -f ezc

.phony: run
run:
	make
	./ezc