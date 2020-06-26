; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_atoi_base_bonus.s                               :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/06/22 16:08:14 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/24 15:34:45 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

SECTION .text
	global _ft_atoi_base

_ft_atoi_base:
			cmp RDI, 0
			je is_null
			cmp RSI, 0
			je is_null
			jmp check_base

check_base:
	mov RCX, 0
	mov CL, 0

is_null:
		mov RAX, -1
		ret
