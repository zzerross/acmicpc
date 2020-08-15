TARGET := main
CFLAGS := -Wall
# CFLAGS := -Duse_pr

IN := in0

define build
$(eval 
$(2): FORCE $(1)
	g++ $(CFLAGS) -o $$@ $(2).cpp
	./$(2) $(3) 2>&1 | tee $(2).txt
	@echo
)
endef

diff: main bfrc FORCE
	diff main.txt bfrc.txt

$(call build,main,bfrc,< smp.txt)
$(call build,smp,main,< smp.txt)
$(call build,,smp)

.PHONY: FORCE

clean:
	rm $(TARGET) $(TARGET).txt

reset:
	find ! -name Makefile | xargs rm -rf
