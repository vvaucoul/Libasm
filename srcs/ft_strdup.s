; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/03/11 17:41:31 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/22 18:26:42 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern _malloc

SECTION .text
	global _ft_strdup

_ft_strdup:
	mov RCX, 0
	cmp RDI, 0
	je is_null
	jmp count

count:
	cmp BYTE [RDI + RCX], 0
	jne increment
	je	malloc_str

increment:
	inc RCX

malloc_str:
	inc RCX
	push RDI
	mov RDI, RCX
	call _malloc
	pop RDI
	cmp RAX, 0
	je is_null
	jmp set_str

increment_str:
	inc RCX

set_str:
	mov dl, BYTE [RDI + RCX]
	mov BYTE [RAX + RCX], dl
	cmp dl, 0
	jne	increment_str
	je done

is_null:
	mov RAX, 0
	ret

done:
	ret
