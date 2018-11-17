install:
	@echo Installation in progress. Please wait
	@gcc blackice.c -g0 -O0 -o blackice
	@chmod ugo+rx blackice
	@cp -f -p blackice /bin/
	@echo Installation was successfuly complete
uninstall:
	@rm -f /bin/blackice
	@echo Uninstallation was successfuly complete