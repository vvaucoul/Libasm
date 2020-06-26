; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/03/11 17:06:32 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/24 14:31:42 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL_WRITE 0x2000004
extern ___error

SECTION .text
	global _ft_write

_ft_write:
	mov RAX, SYSCALL_WRITE
	syscall
	jc error
	ret

error:
	neg RAX
	imul RAX, -1
	mov RDI, RAX
  	call ___error
  	mov [RAX], RDI
  	mov RAX, -1
  	ret
