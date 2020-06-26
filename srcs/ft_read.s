; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/03/11 16:51:19 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/24 15:36:06 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL_READ  0x2000003
extern ___error

SECTION .text
	global _ft_read

_ft_read:
	mov RAX, SYSCALL_READ
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
