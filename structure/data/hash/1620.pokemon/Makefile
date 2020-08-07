TARGET := main
CFLAGS := -Wall
CFLAGS += -Duse_pr

IN := in1

$(TARGET): FORCE
	gcc $(CFLAGS) -o $@ $(TARGET).cpp
	time ./$(TARGET) < $(IN) 2>&1 | tee $(TARGET).txt

smp: FORCE
	gcc -o $@ smp.cpp
	./smp | tee in1

.PHONY: FORCE

clean:
	rm $(TARGET) $(TARGET).txt

reset:
	find ! -name Makefile | xargs rm -rf
