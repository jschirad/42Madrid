# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 13:15:16 by jschirad          #+#    #+#              #
#    Updated: 2020/02/25 16:49:27 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	_ft_strcmp


_ft_strcmp:									; s1 = rdi, s2 = rsi
			xor		rdx, rdx
			xor		rcx, rcx
			cmp		rdi, 0
			jz		check
			cmp		rsi, 0
			jz		check

check:
			cmp		rdi, rsi
			je		return0
			jg		return1
			jmp		return2

compare:
			mov		dl, BYTE [rsi + rdx]
			cmp		BYTE [rdi + rdx], dl
			je		return0
			jg		return1
			jmp		return2

return0:
			mov		rax, 0
			ret
return1:
			mov		rax, 1
			ret
return2:
			mov		rax, -1
			ret
