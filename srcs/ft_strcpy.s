; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/06/23 18:08:33 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/23 18:08:53 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

SECTION .text
	global _ft_strcpy

_ft_strcpy:
	mov RAX, -1
	mov RCX, 0
	cmp RSI, 0
	je is_null
	cmp RDI, 0
	je is_null
	jmp loop

loop:
	mov R10, [RSI + RCX]
	mov [RDI + RCX], R10
	cmp BYTE [RSI + RCX], 0
	je end
	inc RCX
	jmp loop

is_null:
	mov RAX, 0
	ret

end:
	mov RAX, RDI
	ret
