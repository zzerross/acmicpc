CFLAGS := -Wall
# CFLAGS += -D_lv_=3
# CFLAGS += -D_tc_=1
TARGET := main
IN := in0

$(TARGET): FORCE
	g++ $(CFLAGS) -o $@ $(TARGET).cpp
	time ./$(TARGET) < $(IN) 2>&1 | tee $(TARGET).txt

.PHONY: FORCE

clean:
	rm -rf $(TARGET) $(TARGET).txt 

reset:
	find ! -name Makefile | xargs rm -rf
