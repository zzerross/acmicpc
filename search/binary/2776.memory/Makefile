CFLAGS := -Wall
# CFLAGS := -Duse_pr

IN := in0
# IN := smp.txt

define build
$(eval 
$(2): FORCE $(1)
	g++ $(CFLAGS) -o $$@ $(2).cpp
	./$(2) $(3) 2>&1 | tee $(2).txt
	@echo
)
endef

diff: main stl FORCE
	diff main.txt stl.txt

$(call build,rmsrt,main,< $(IN))
$(call build,,rmsrt,< $(IN))

# $(call build,,stl,< $(IN))

# $(call build,main,bfrc,< $(IN))
# $(call build,smp,main,< $(IN))
# $(call build,,smp)

.PHONY: FORCE

reset:
	find ! -name Makefile | xargs rm -rf
