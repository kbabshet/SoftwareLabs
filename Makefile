.PHONY: clean All

All:
	@echo "----------Building project:[ stopwatch - Debug ]----------"
	@cd "stopwatch" && $(MAKE) -f  "stopwatch.mk"
clean:
	@echo "----------Cleaning project:[ stopwatch - Debug ]----------"
	@cd "stopwatch" && $(MAKE) -f  "stopwatch.mk" clean
