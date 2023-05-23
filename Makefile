.PHONY: arm clean

all:
	make -C ./src/ CROSS_COMPILE=

arm:
	cd ./src && make CROSS_COMPILE=arm-linux-gnueabihf-

clean:
	make -C ./src/ clean