; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/03/11 17:17:26 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/23 19:29:46 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

SECTION .text
	global _ft_strcmp

_ft_strcmp:
	mov RCX, 0
	cmp RDI, 0
	je is_null
	cmp RSI, 0
	je is_null
	jmp loop


is_null:
	mov RAX, 0
	ret

loop:
	mov AL, BYTE [RDI + RCX]
	mov BL, BYTE [RSI + RCX]
	cmp AL, 0
	jz return
	cmp BL, 0
	jz return
	cmp AL, BL
	jne return
	inc RCX
	jmp loop

return:
	mov AL, BYTE [RDI + RCX]
	mov BL, BYTE [RSI + RCX]
	cmp AL, BL
	jb inf
	ja sup
	jmp equal


inf:
	mov RAX, -1
	ret

equal:
	mov RAX, 0
	ret

sup:
	mov RAX, 1
	ret
