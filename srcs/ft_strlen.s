; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/03/10 17:59:51 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/20 19:59:09 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

SECTION .text
	global _ft_strlen

_ft_strlen:
	mov RCX, 0
	cmp RDI, 0
	je is_null
	jmp check

is_null:
	mov RAX, 0
	ret

increment:
	inc RCX

check:
	cmp BYTE [RCX + RDI], 0
	jne increment

done:
	mov RAX, RCX
	ret
