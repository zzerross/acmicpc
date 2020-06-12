TARGET := $(MAKECMDGOALS)
ifeq ($(TARGET),)
TARGET := main
endif

CFLAGS := -Wall

IN := in0

$(TARGET): FORCE
	g++ $(CFLAGS) -o $@ $(TARGET).cpp
	./$(TARGET) < $(IN) 2>&1 | tee $(TARGET).txt

.PHONY: FORCE

clean:
	rm $(TARGET) $(TARGET).txt

reset:
	find ! -name Makefile | xargs rm -rf
