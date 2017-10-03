#!/bin/bash
mkdir -p dealer_syntax/north dealer_syntax/south
for c in constraints/*.txt; do
    filename=$(echo "$c" | cut - -f 2 -d /)
	./converter north < "constraints/$filename" > "dealer_syntax/north/$filename"
	./converter south < "constraints/$filename" > "dealer_syntax/south/$filename"
done
