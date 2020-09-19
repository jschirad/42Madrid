# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 17:43:22 by jschirad          #+#    #+#              #
#    Updated: 2020/02/26 10:31:13 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global	_ft_strdup
				section.text
				extern	_malloc

_ft_strdup:
					cmp			rdi,0
					jz			checknull
strlen:
					xor			rcx, rcx
					jmp			caracter
suma:
					inc			rcx
caracter:
					cmp			BYTE [rdi + rcx], 0
					jne			suma


malloc_star:
					inc			rcx
					push		rdi
					mov			rdi, rcx
					call		_malloc
					pop			rdi
					cmp			rax, 0
					jz			checknull

strcpy:
					xor			rcx, rcx
					jmp			strcopy
while:
					inc		rcx
strcopy:
					mov		dl , byte [rdi + rcx]
					mov		byte [rax + rcx], dl
					cmp		dl, 0
					jnz		while
					jmp		return

checknull:
					xor		rax,rax
return:
					ret
