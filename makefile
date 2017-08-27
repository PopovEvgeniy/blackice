install:
	@echo Compiling the program source code. Please wait
	@gcc blackice.c -g0 -O0 -o blackice
	@echo Compilation successfuly complete
	@chmod ugo+rx blackice
	@echo Enter you user password for do last installation step
	@sudo cp -f -p blackice /bin/
	@echo Installation complete
uninstall:
	@echo Enter you user password for uninstall this software
	@sudo rm -f /bin/blackice
	@echo Uninstallation complete