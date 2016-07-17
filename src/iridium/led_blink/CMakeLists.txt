px4_add_module(
	MODULE iridium__led_blink
	MAIN led_blink
	STACK_MAIN 2000
	SRCS
		led_blink.c
	DEPENDS
		platforms__common
	)