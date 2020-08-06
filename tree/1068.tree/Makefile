SAMPLE := smp
TARGET := main
CFLAGS := -Wall

IN := in0

$(TARGET): FORCE
	gcc $(CFLAGS) -o $@ $(TARGET).cpp
	./$(TARGET) < $(IN) 2>&1 | tee $(TARGET).txt

smp: FORCE
	g++ $(CFLAGS) -o $@ $(SAMPLE).cpp
	./$(SAMPLE) | tee in1

.PHONY: FORCE

clean:
	rm $(TARGET) $(TARGET).txt

reset:
	find ! -name Makefile | xargs rm -rf
