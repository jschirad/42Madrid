# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 13:15:06 by jschirad          #+#    #+#              #
#    Updated: 2020/02/25 14:57:39 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_strcpy

_ft_strcpy:
	mov rcx, -1
while:
	inc		rcx
	mov		dl ,byte [rsi + rcx]			; dst = rdi, scr = rsi
	mov		byte [rdi + rcx], dl
	cmp		dl, 0
	jnz		while
	mov		rax, rdi						; return dst
	ret
