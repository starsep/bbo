all: converter deals

converter: converter.cpp
	g++ -o converter -std=c++11 converter.cpp

dealer_syntax:
	mkdir -p dealer_syntax

deals: dealer_syntax generate.sh
	./generate.sh

clean:
	rm -rf converter dealer_syntax
