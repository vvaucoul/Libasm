; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_push_front_bonus.s                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/06/22 16:08:35 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/22 18:47:53 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern _malloc

SECTION .text
	global _ft_list_push_front

_ft_list_push_front:
					push RSP
					push RDI
					push RSI
					mov RDI, 16
					mov RAX, 0
					call _malloc
					pop RSI
					pop RDI
					cmp RAX, 0
					jz end
					jnz create_elem

create_elem:
					mov [RAX], RSI
					mov RCX, [RDI]
					mov [RAX + 8], RCX
					mov [RDI], RAX

end:
					pop RSP
					ret
