CFLAGS := -Werror -Wall

D ?= 0
CFLAGS := -DDEBUG=$(D)

# IN := in0
# IN := in1
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

$(call build,smp,main,< $(IN))
$(call build,,smp,)

clean:
	rm -rf $(OUTS)

.PHONY: FORCE

reset:
	find ! -name Makefile | xargs rm -rf

