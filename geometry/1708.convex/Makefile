CFLAGS := -Werror -Wall

D ?= 0
CFLAGS += -DDEBUG=$(D)

I ?= 0

T ?= 0
CFLAGS += -DTEST=$(T)

define build
$(eval 
$(2): FORCE $(1)
	g++ $(CFLAGS) -o $$@ $(2).cpp
	time ./$(2) $(3) 2>&1 | tee $(2).txt
	@echo

OUTS += $(2) $(2).txt
)
endef

$(call build,,main,< in$(I))

clean:
	rm -rf $(OUTS)

.PHONY: FORCE

reset:
	find ! -name Makefile | xargs rm -rf

