TARGET := main
CFLAGS := -Wall

$(TARGET): FORCE
	g++ $(CFLAGS) -o $@ $(TARGET).cpp
	./$(TARGET) 2>&1 | tee $(TARGET).txt

.PHONY: FORCE

clean:
	rm $(TARGET) $(TARGET).txt

reset:
	find ! -name Makefile | xargs rm -rf
