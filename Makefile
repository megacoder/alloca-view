# vim: ts=8 sw=8

CC	=gcc -std=c99 -march=i686
OPT	=-Os
CFLAGS	=${OPT} -Wall -Wextra -Werror -pedantic -g
LDFLAGS	=-g
LDLIBS	=

.SUFFIXES: .lst

%${OPT}.lst: %${OPT}.o
	objdump -dS $^ >$@

all::	alloca-view${OPT} alloca-view${OPT}.lst

alloca-view${OPT}.o: alloca-view.c
	${CC} ${CFLAGS} -o $@ -c $^

clean::
	${RM} *.o a.out core.* lint tags
	${RM} *.lst

distclean clobber:: clean
	${RM} alloca-view alloca-view-*

check:: alloca-view
	./alloca-view ${ARGS}
