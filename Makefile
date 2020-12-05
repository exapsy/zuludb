.PHONY: clean build

build: CMakeLists.txt
	echo "Cleaning"
	rm -rf ./build/*
	mkdir -p ./build
	echo "Building\n"
	cmake -S . -B ./build
	cd ./build && make

clean:
	rm -rf ./build/*

