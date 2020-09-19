# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 13:05:12 by jschirad          #+#    #+#              #
#    Updated: 2020/02/25 17:40:49 by jschirad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global		_ft_strlen

		section		.text

_ft_strlen:
					xor			rax, rax
					jmp			caracter
suma:
					inc			rax
caracter:
					cmp			BYTE [rdi + rax], 0
					jne			suma
return:
					ret

