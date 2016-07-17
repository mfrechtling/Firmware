px4_add_module(
	MODULE iridium__att_read_simple
	MAIN att_read_simple
	STACK_MAIN 2000
	SRCS
		att_read_simple.c
	DEPENDS
		platforms__common
	)
