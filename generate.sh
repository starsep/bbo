#!/bin/bash
for c in constraints/*.txt; do
	filename=`echo "$c" | cut - -f 2 -d /`
	./converter < "constraints/$filename" > "dealer_syntax/$filename"
done
