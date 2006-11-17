/*
 * vim: ts=8 sw=8
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#define	_unused		__attribute__((unused))
#define	_used		__attribute__((used))

typedef struct	{
	int		bogus;
	char		phantom[];
} Space_t;

int
main(
	int		argc		_unused,
	char * *	argv		_unused
)
{
	char const	fmt[] = "sizeof( %-7s ) = %u.\n";
	char		buf[ BUFSIZ ];
	int const	size = sizeof( Space_t ) + sizeof( buf );
	Space_t * const	ghost = alloca( size );

	printf( "size=%u.\n", size );
	printf( fmt, "Space_t", sizeof( Space_t ) );
	printf( fmt, "buf", sizeof( buf ) );
	printf( fmt, "*ghost", sizeof( *ghost ) );
	return( 0 );
}
