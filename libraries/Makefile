libraries = libC \
			libGUI

build: $(libraries)
	@for entry in ${libraries};             \
    do                                      \
		cd $${entry} && make;cd ..;			\
    done