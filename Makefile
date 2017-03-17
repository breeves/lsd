default:
	g++ -o bin/lsd src/lsd.cpp

clean:
	rm -rf *.o bin/lsd

runtest:
	./bin/lsd test
