all: make-lineups

make-lineups: main.cpp PlayerTypes/* TeamTypes/*
	g++ -std=c++11 main.cpp -o make-lineups

clean:
	rm *make-lineups

run: make-lineups
	./make-lineups
