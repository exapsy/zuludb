.PHONY: clean build

build: CMakeLists.txt
	echo "Cleaning"
	rm -rf ./build/*
	mkdir -p ./build
	echo "Building\n"
	cmake -DCMAKE_BUILD_TYPE=Release -S . -B ./build
	cd ./build && make

release: CMakeLists.txt
	echo "Cleaning"
	rm -rf ./build/*
	mkdir -p ./build
	echo "Building\n"
	cmake -DCMAKE_BUILD_TYPE=Release -S . -B ./build
	cd ./build && make

clean:
	rm -rf ./build/*

