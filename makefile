install:
	@echo Installation in progress. Please wait
	@gcc blackice.c -g0 -O0 -o /bin/blackice
	@chmod ugo+rx /bin/blackice
	@echo Installation successfully complete
uninstall:
	@rm -f /bin/blackice
	@echo Uninstallation successfully complete