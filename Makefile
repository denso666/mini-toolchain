.PHONY: x86_64 arm clean

x86_64:
	cd ./src && make CROSSC=

arm:
	cd ./src && make CROSSC=arm-linux-gnueabihf-

clean:
	cd ./src && make clean