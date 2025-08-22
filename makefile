install:
	@echo Installation in progress. Please wait
	@$(CC) blackice.c -g0 -O0 -o /bin/blackice
	@chmod ugo+rx /bin/blackice
	@echo Installation was successfully completed
uninstall:
	@rm -f /bin/blackice
	@echo Uninstallation was successfully completed