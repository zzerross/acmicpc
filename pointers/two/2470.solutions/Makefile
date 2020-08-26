CFLAGS := -Wall
CFLAGS := -Duse_pr

IN := smp.txt

define build
$(eval 
$(2): FORCE $(1)
	g++ $(CFLAGS) -o $$@ $(2).cpp
	time ./$(2) $(3) 2>&1 | tee $(2).txt
	@echo

OUTS += $(2) $(2).txt
)
endef

$(call build,bfrc,main,< $(IN))
$(call build,smp,bfrc,< $(IN))
$(call build,,smp,)

clean:
	rm -rf $(OUTS)

.PHONY: FORCE

reset:
	find ! -name Makefile | xargs rm -rf

