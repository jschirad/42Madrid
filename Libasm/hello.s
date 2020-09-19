# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hello.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:20:45 by jschirad          #+#    #+#              #
#    Updated: 2020/02/24 12:07:21 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


		global		_main

		section		.data
message: db	"hello, world", 10			;note the new line at the end

		section		.text

_main:	mov			rax, 0x02000004		;system call for write
		mov			rdi, 1				;file handle 1 is stdout
		mov			rsi, message		;address of string to output
		mov			rdx, 13				;number of bytes
		syscall							;invoke operting system to do the write
		mov			rax, 0x02000001		;system call for exit
		xor			rdi, rdi			;exit code 0
		syscall							;invoke operating system to exit
