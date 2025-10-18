builddir := build
bindir := bin

bin := glshooter 

all:
	cd $(builddir); ninja;

run:
	cd $(bindir); ./$(bin)

cmake:
	cmake . -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B $(builddir);
