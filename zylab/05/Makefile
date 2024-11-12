SHELL:=/usr/bin/env bash -O globstar
OUT=main

install:
	$(CXX) *.cpp *.h -o $(OUT)

clean:
	rm main

run: clean install
	./main
